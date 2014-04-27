#pragma once

#include "Vector3.h"
#include "Plane3.h"
#include "Matrix4.h"
#include "AABB.h"

class Ray
{
public:
	Vector3 origin;
	Vector3 direction;

	Ray()
	{}

	Ray(const Vector3& origin_, const Vector3& direction_) :
		origin(origin_), 
		direction(direction_)
	{}

	static Ray createForPoints(const Vector3& origin, const Vector3& p2)
	{
		return Ray(origin, (p2 - origin).getNormalised());
	}

	/* greebo: this calculates the intersection point of two rays
	 * (copied from Radiant's Intersection code, there may be better ways)
	 */
	Vector3 getIntersection(Ray& other)
	{
		Vector3 intersection = origin - other.origin;

		Vector3::ElementType dot = direction.dot(other.direction);
  		Vector3::ElementType d = direction.dot(intersection);
		Vector3::ElementType e = other.direction.dot(intersection);
		Vector3::ElementType D = 1 - dot*dot;       // always >= 0

		if (D < 0.000001f)
		{
			// the lines are almost parallel
			return other.origin + other.direction*e;
		}
		else
		{
			return other.origin + other.direction*((e - dot*d) / D);
		}
	}

	void transform(const Matrix4& matrix)
	{
		origin = matrix.transformPoint(origin);
		direction = matrix.transformDirection(direction);
	}

	// closest-point-on-line
	Vector3::ElementType getSquaredDistance(const Vector3& point) const
	{
		return (point - (origin + direction * (point - origin).dot(direction))).getLengthSquared();
	}

	Vector3::ElementType getDistance(const Plane3& plane) const
	{
		return -(plane.normal().dot(origin) - plane.dist()) / direction.dot(plane.normal());
	}

	/**
	 * Intersect this ray with the given bounding box. If no intersection occurs, this method
	 * returns FALSE, in case of intersection (even if the ray starts within the AABB volume)
	 * the method returns TRUE. The coord parameter will contain the intersection point in the
	 * latter case (which will be the Ray's origin if it starts within the AABB to test).
	 * Algorithm taken and adjusted from http://tog.acm.org/resources/GraphicsGems/gems/RayBox.c
	 */
	bool intersectAABB(const AABB& aabb, Vector3& intersection) const
	{
		if (!aabb.isValid()) return false;

		#define QUADRANT_RIGHT	0
		#define QUADRANT_LEFT	1
		#define QUADRANT_MIDDLE	2

		bool inside = true;
		char quadrant[3];
		Vector3::ElementType candidatePlane[3];

		Vector3 aabbMin = aabb.getOrigin() - aabb.getExtents();
		Vector3 aabbMax = aabb.getOrigin() + aabb.getExtents();

		// Find candidate planes; this loop can be avoided if
   		// rays cast all from the eye(assume perpsective view) 
		for (int i = 0; i < 3; i++)
		{
			if (origin[i] < aabbMin[i])
			{
				quadrant[i] = QUADRANT_LEFT;
				candidatePlane[i] = aabbMin[i];
				inside = false;
			}
			else if (origin[i] > aabbMax[i])
			{
				quadrant[i] = QUADRANT_RIGHT;
				candidatePlane[i] = aabbMax[i];
				inside = false;
			}
			else
			{
				quadrant[i] = QUADRANT_MIDDLE;
			}
		}

		// Ray origin inside bounding box 
		if (inside)
		{
			intersection = origin;
			return true;
		}

		Vector3::ElementType maxT[3];

		// Calculate T distances to candidate planes
		for (int i = 0; i < 3; i++)
		{
			if (quadrant[i] != QUADRANT_MIDDLE && direction[i] != 0)
			{
				maxT[i] = (candidatePlane[i] - origin[i]) / direction[i];
			}
			else
			{
				maxT[i] = -1;
			}
		}

		// Get largest of the maxT's for final choice of intersection
		int whichPlane = 0;

		for (int i = 1; i < 3; i++)
		{
			if (maxT[whichPlane] < maxT[i])
			{
				whichPlane = i;
			}
		}

		// Check final candidate actually inside box 
		if (maxT[whichPlane] < 0) return false;

		for (int i = 0; i < 3; i++)
		{
			if (whichPlane != i)
			{
				intersection[i] = origin[i] + maxT[whichPlane] * direction[i];

				if (intersection[i] < aabbMin[i] || intersection[i] > aabbMax[i])
				{
					return false;
				}
			} 
			else 
			{
				intersection[i] = candidatePlane[i];
			}
		}

		return true; // ray hits box
	}

	// Return type for intersectTriangle()
	enum eTriangleIntersectionType
	{
		NO_INTERSECTION,
		POINT,
		COPLANAR,
	};

	/**
	 * Intersect this ray with the given triangle as represented by the 3 given points and 
	 * returns the found intersection type. Only in the case of eTriangleIntersectionType::POINT
	 * the intersection argument will be filled with suitable coordinates, otherwise it's undefined.
	 *
	 * Note: degenerate triangles will return NO_INTERSECTION.
	 * Taken and adjusted from http://geomalgorithms.com/a06-_intersect-2.html
	 */
	eTriangleIntersectionType intersectTriangle(const Vector3& p1, const Vector3& p2, const Vector3& p3, Vector3& intersection) const
	{
		// get triangle edge vectors and plane normal
		Vector3 u = p2 - p1;
		Vector3 v = p3 - p1;
		Vector3 n = u.crossProduct(v);

		if (n.getLengthSquared() == 0) 
		{
			return NO_INTERSECTION;  // triangle is degenerate
		}

		Vector3 dir = direction; // ray direction vector

		Vector3 w0 = origin - p1;

		double a = -n.dot(w0);
		double b = n.dot(dir);

		if (fabs(b) < 0.00001)
		{
			// ray is  parallel to triangle plane
			if (a == 0)
			{
				return COPLANAR; // ray lies in triangle plane
			}
			else 
			{
				return NO_INTERSECTION; // ray disjoint from plane
			}
		}

		// get intersect point of ray with triangle plane
		double r = a / b;

		if (r < 0.0)                    // ray goes away from triangle
		{
			return NO_INTERSECTION;                   // => no intersect
		}

		// for a segment, also test if (r > 1.0) => no intersect
		intersection = origin + direction * r; // // intersect point of ray and plane

		// is I inside T?
		double uu = u.dot(u);
		double uv = u.dot(v);
		double vv = v.dot(v);

		Vector3 w = intersection - p1;
		double wu = w.dot(u);
		double wv = w.dot(v);

		double D = uv * uv - uu * vv;

		// get and test parametric coords
		double s = (uv * wv - vv * wu) / D;

		if (s < 0.0 || s > 1.0)
		{
			return NO_INTERSECTION; // intersection is outside T
		}

		double t = (uv * wu - uu * wv) / D;

		if (t < 0.0 || (s + t) > 1.0) 
		{
			return NO_INTERSECTION; // intersection is outside T
		}

		return POINT; // I is in T
	}
};
