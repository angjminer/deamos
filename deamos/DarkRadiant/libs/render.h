/*
Copyright (C) 2001-2006, William Joseph.
All Rights Reserved.

This file is part of GtkRadiant.

GtkRadiant is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

GtkRadiant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GtkRadiant; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

/// \file
/// \brief High-level constructs for efficient OpenGL rendering.

#include "render/ArbitraryMeshVertex.h"
#include "render/Vertex3f.h"
#include "render/TexCoord2f.h"
#include "render/VertexCb.h"

#include "irender.h"
#include "igl.h"

#include "math/FloatTools.h"
#include "math/Vector2.h"
#include "math/pi.h"

#include <vector>

typedef unsigned int RenderIndex;
const GLenum RenderIndexTypeID = GL_UNSIGNED_INT;

/// Vector of indices for use with glDrawElements
typedef std::vector<RenderIndex> IndexBuffer;

/// \brief A wrapper around a std::vector which inserts only vertices which have not already been inserted.
/// \param Vertex The vertex data type. Must support operator<, operator== and operator!=.
/// For best performance, quantise vertices before inserting them.
template<typename Vertex>
class UniqueVertexBuffer {
	typedef std::vector<Vertex> Vertices;
	Vertices& m_data;

	struct bnode {
		bnode()
				: m_left(0), m_right(0) {}
		RenderIndex m_left;
		RenderIndex m_right;
	};

	std::vector<bnode> m_btree;
	RenderIndex m_prev0;
	RenderIndex m_prev1;
	RenderIndex m_prev2;

	const RenderIndex find_or_insert(const Vertex& vertex) {
		RenderIndex index = 0;

		while(1) {
			if(vertex < m_data[index]) {
				bnode& node = m_btree[index];
				if(node.m_left != 0) {
					index = node.m_left;
					continue;
				}
				else {
					node.m_left = RenderIndex(m_btree.size());
					m_btree.push_back(bnode());
					m_data.push_back(vertex);
					return RenderIndex(m_btree.size()-1);
				}
			}
			if(m_data[index] < vertex) {
				bnode& node = m_btree[index];
				if(node.m_right != 0) {
					index = node.m_right;
					continue;
				}
				else {
					node.m_right = RenderIndex(m_btree.size());
					m_btree.push_back(bnode());
					m_data.push_back(vertex);
					return RenderIndex(m_btree.size()-1);
				}
			}

			return index;
		}
	}
public:
	UniqueVertexBuffer(Vertices& data)
			: m_data(data), m_prev0(0), m_prev1(0), m_prev2(0) {}

	typedef typename Vertices::const_iterator iterator;

	iterator begin() const {
		return m_data.begin();
	}
	iterator end() const {
		return m_data.end();
	}

	std::size_t size() const {
		return m_data.size();
	}
	const Vertex* data() const {
		return &(*m_data.begin());
	}
	Vertex& operator[](std::size_t index) {
		return m_data[index];
	}
	const Vertex& operator[](std::size_t index) const {
		return m_data[index];
	}

	void clear() {
		m_prev0 = 0;
		m_prev1 = 0;
		m_prev2 = 0;
		m_data.clear();
		m_btree.clear();
	}
	void reserve(std::size_t max_vertices) {
		m_data.reserve(max_vertices);
		m_btree.reserve(max_vertices);
	}
	/// \brief Returns the index of the element equal to \p vertex.
	RenderIndex insert(const Vertex& vertex) {
		if(m_data.empty()) {
			m_data.push_back(vertex);
			m_btree.push_back(bnode());
			return 0;
		}

		if(m_data[m_prev0] == vertex)
			return m_prev0;
		if(m_prev1 != m_prev0 && m_data[m_prev1] == vertex)
			return m_prev1;
		if(m_prev2 != m_prev0 && m_prev2 != m_prev1 && m_data[m_prev2] == vertex)
			return m_prev2;

		m_prev2 = m_prev1;
		m_prev1 = m_prev0;
		m_prev0 = find_or_insert(vertex);

		return m_prev0;
	}
};


// A Normal3f is just another Vertex3f (Vector3)
typedef Vertex3f Normal3f;

/// \brief Returns a double-precision \p component quantised to \p precision.
inline double double_quantise(double component, double precision)
{
	return float_snapped(component, precision);
}

/// \brief Returns a \p vertex quantised to \p precision.
inline Vertex3f vertex3f_quantised(const Vertex3f& vertex, double precision)
{
	return Vertex3f(double_quantise(vertex.x(), precision), double_quantise(vertex.y(), precision), double_quantise(vertex.z(), precision));
}

const float c_quantise_vertex = 1.f / static_cast<float>(1 << 3);

/// \brief Returns \p v with vertex quantised to a fixed precision.
inline VertexCb pointvertex_quantised(const VertexCb& v) {
	return VertexCb(vertex3f_quantised(v.vertex, c_quantise_vertex), v.colour);
}

/// \brief Sets up the OpenGL colour and vertex arrays for \p array.
inline void pointvertex_gl_array(const VertexCb* array)
{
	glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(VertexCb), &array->colour);
	glVertexPointer(3, GL_DOUBLE, sizeof(VertexCb), &array->vertex);
}

/// A renderable collection of coloured vertices
class RenderablePointVector :
	public OpenGLRenderable
{
protected:
	typedef std::vector<VertexCb> PointVertexVector;
	PointVertexVector _vector;
	const GLenum _mode;

public:
	RenderablePointVector(GLenum mode) :
		_mode(mode)
	{}

	RenderablePointVector(GLenum mode, std::size_t initialSize) :
		_vector(initialSize),
		_mode(mode)
	{}

	void render(const RenderInfo& info) const
	{
		if (_vector.empty()) return;

        // Enable point colours if required
        if (info.checkFlag(RENDER_VERTEX_COLOUR)
            || (info.checkFlag(RENDER_POINT_COLOUR) && _mode == GL_POINTS))
        {
            glEnableClientState(GL_COLOR_ARRAY);
        }
		pointvertex_gl_array(&_vector.front());
		glDrawArrays(_mode, 0, static_cast<GLsizei>(_vector.size()));
	}

	// Convenience method to set the colour of the whole array
	void setColour(const Colour4b& colour)
	{
		for (PointVertexVector::iterator i = _vector.begin(); i != _vector.end(); ++i)
		{
			i->colour = colour;
		}
	}

	const VertexCb& operator[](std::size_t i) const
	{
		return _vector[i];
	}

	VertexCb& operator[](std::size_t i)
	{
		return _vector[i];
	}

	VertexCb& front()
	{
		return _vector.front();
	}

	const VertexCb& front() const
	{
		return _vector.front();
	}

	std::size_t size() const {
		return _vector.size();
	}

	bool empty() const {
		return _vector.empty();
	}

	void clear() {
		_vector.clear();
	}

	void resize(std::size_t size) {
		_vector.resize(size);
	}

	void reserve(std::size_t size) {
		_vector.reserve(size);
	}

	void push_back(const VertexCb& point) {
		_vector.push_back(point);
	}
};


/// A renderable wrapper for a collection of vertices stored elsewhere
class RenderableVertexBuffer : public OpenGLRenderable
{
	const GLenum _mode;
	const std::vector<VertexCb>& m_vertices;
public:
	RenderableVertexBuffer(GLenum mode, const std::vector<VertexCb>& vertices)
			: _mode(mode), m_vertices(vertices) {}

	void render(const RenderInfo& info) const
    {
        if (info.checkFlag(RENDER_VERTEX_COLOUR)
            || (info.checkFlag(RENDER_POINT_COLOUR) && _mode == GL_POINTS))
        {
            glEnableClientState(GL_COLOR_ARRAY);
        }
		pointvertex_gl_array(m_vertices.data());
		glDrawArrays(_mode, 0, static_cast<GLsizei>(m_vertices.size()));
	}
};

/// Renderable wrapper for a set of vertices and indices stored in other arrays
class RenderableIndexBuffer : public OpenGLRenderable
{
	const GLenum _mode;
	const IndexBuffer& m_indices;
	const std::vector<VertexCb>& m_vertices;
public:
	RenderableIndexBuffer(GLenum mode, const IndexBuffer& indices, const std::vector<VertexCb>& vertices)
			: _mode(mode), m_indices(indices), m_vertices(vertices) {}

	void render(const RenderInfo& info) const
    {
        if (info.checkFlag(RENDER_VERTEX_COLOUR)
            || (info.checkFlag(RENDER_POINT_COLOUR) && _mode == GL_POINTS))
        {
            glEnableClientState(GL_COLOR_ARRAY);
        }
		pointvertex_gl_array(m_vertices.data());
		glDrawElements(_mode, GLsizei(m_indices.size()), RenderIndexTypeID, m_indices.data());
	}
};


class RemapXYZ {
public:
	static void set(Vertex3f& vertex, float x, float y, float z) {
		vertex.x() = x;
		vertex.y() = y;
		vertex.z() = z;
	}
};

class RemapYZX {
public:
	static void set(Vertex3f& vertex, float x, float y, float z) {
		vertex.x() = z;
		vertex.y() = x;
		vertex.z() = y;
	}
};

class RemapZXY {
public:
	static void set(Vertex3f& vertex, float x, float y, float z) {
		vertex.x() = y;
		vertex.y() = z;
		vertex.z() = x;
	}
};

template<typename remap_policy>
inline void draw_circle(const std::size_t segments, const float radius, VertexCb* vertices, remap_policy remap) {
	const double increment = c_pi / double(segments << 2);

	std::size_t count = 0;
	float x = radius;
	float y = 0;
	while(count < segments) {
		VertexCb* i = vertices + count;
		VertexCb* j = vertices + ((segments << 1) - (count + 1));

		VertexCb* k = i + (segments << 1);
		VertexCb* l = j + (segments << 1);

		VertexCb* m = i + (segments << 2);
		VertexCb* n = j + (segments << 2);
		VertexCb* o = k + (segments << 2);
		VertexCb* p = l + (segments << 2);

		remap_policy::set(i->vertex, x,-y, 0);
		remap_policy::set(k->vertex,-y,-x, 0);
		remap_policy::set(m->vertex,-x, y, 0);
		remap_policy::set(o->vertex, y, x, 0);

		++count;

		{
			const double theta = increment * count;
			x = static_cast<float>(radius * cos(theta));
			y = static_cast<float>(radius * sin(theta));
		}

		remap_policy::set(j->vertex, y,-x, 0);
		remap_policy::set(l->vertex,-x,-y, 0);
		remap_policy::set(n->vertex,-y, x, 0);
		remap_policy::set(p->vertex, x, y, 0);
	}
}

inline void draw_quad(const float radius, VertexCb* quad) {
	(*quad++).vertex = Vertex3f(-radius, radius, 0);
	(*quad++).vertex = Vertex3f(radius, radius, 0);
	(*quad++).vertex = Vertex3f(radius, -radius, 0);
	(*quad++).vertex = Vertex3f(-radius, -radius, 0);
}
