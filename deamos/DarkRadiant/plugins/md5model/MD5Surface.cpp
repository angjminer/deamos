#include "MD5Surface.h"

#include "ivolumetest.h"
#include "GLProgramAttributes.h"
#include "string/convert.h"
#include "MD5Model.h"
#include "math/Ray.h"

namespace md5
{

inline VertexPointer vertexpointer_arbitrarymeshvertex(const ArbitraryMeshVertex* array)
{
  return VertexPointer(&array->vertex, sizeof(ArbitraryMeshVertex));
}

// Constructor
MD5Surface::MD5Surface() : 
	_originalShaderName(""),
	_mesh(new MD5Mesh),
	_normalList(0),
	_lightingList(0)
{}

MD5Surface::MD5Surface(const MD5Surface& other) :
	_aabb_local(other._aabb_local),
	_originalShaderName(other._originalShaderName),
	_mesh(other._mesh),
	_normalList(0),
	_lightingList(0)
{}

// Destructor
MD5Surface::~MD5Surface()
{
	// Release GL display lists
	glDeleteLists(_normalList, 1);
	glDeleteLists(_lightingList, 1);
}

// Update geometry
void MD5Surface::updateGeometry()
{
	_aabb_local = AABB();

	for (Vertices::const_iterator i = _vertices.begin(); i != _vertices.end(); ++i)
	{
		_aabb_local.includePoint(i->vertex);
	}

	for (Indices::iterator i = _indices.begin();
		 i != _indices.end();
		 i += 3)
	{
		ArbitraryMeshVertex& a = _vertices[*(i + 0)];
		ArbitraryMeshVertex& b = _vertices[*(i + 1)];
		ArbitraryMeshVertex& c = _vertices[*(i + 2)];

		ArbitraryMeshTriangle_sumTangents(a, b, c);
	}

	for (Vertices::iterator i = _vertices.begin();
		 i != _vertices.end();
		 ++i)
	{
		i->tangent.normalise();
		i->bitangent.normalise();
	}

	// Build the display lists
	createDisplayLists();
}

// Back-end render
void MD5Surface::render(const RenderInfo& info) const
{
	if (info.checkFlag(RENDER_BUMP))
    {
		glCallList(_lightingList);
	}
	else
    {
		glCallList(_normalList);
	}
}

// Construct the display lists
void MD5Surface::createDisplayLists()
{
	// Create the list for lighting mode
	_lightingList = glGenLists(1);
	assert(_lightingList != 0);
	glNewList(_lightingList, GL_COMPILE);

	glBegin(GL_TRIANGLES);
	for (Indices::const_iterator i = _indices.begin();
		 i != _indices.end();
		 ++i)
	{
		// Get the vertex for this index
		ArbitraryMeshVertex& v = _vertices[*i];

		// Submit the vertex attributes and coordinate
		if (GLEW_ARB_vertex_program) {
			// Submit the vertex attributes and coordinate
			glVertexAttrib2dvARB(ATTR_TEXCOORD, v.texcoord);
			glVertexAttrib3dvARB(ATTR_TANGENT, v.tangent);
			glVertexAttrib3dvARB(ATTR_BITANGENT, v.bitangent);
			glVertexAttrib3dvARB(ATTR_NORMAL, v.normal);
		}
		glVertex3dv(v.vertex);
	}
	glEnd();

	glEndList();

	// Generate the list for flat-shaded (unlit) mode
	_normalList = glGenLists(1);
	assert(_normalList != 0);
	glNewList(_normalList, GL_COMPILE);

	glBegin(GL_TRIANGLES);
	for (Indices::const_iterator i = _indices.begin();
		 i != _indices.end();
		 ++i)
	{
		// Get the vertex for this index
		ArbitraryMeshVertex& v = _vertices[*i];

		// Submit attributes
		glNormal3dv(v.normal);
		glTexCoord2dv(v.texcoord);
		glVertex3dv(v.vertex);
	}
	glEnd();

	glEndList();
}

// Selection test
void MD5Surface::testSelect(Selector& selector,
							SelectionTest& test,
							const Matrix4& localToWorld)
{
	test.BeginMesh(localToWorld);

	SelectionIntersection best;
	test.TestTriangles(
	  vertexpointer_arbitrarymeshvertex(_vertices.data()),
	  IndexPointer(_indices.data(), IndexPointer::index_type(_indices.size())),
	  best
	);

	if(best.valid()) {
		selector.addIntersection(best);
	}
}

bool MD5Surface::getIntersection(const Ray& ray, Vector3& intersection, const Matrix4& localToWorld)
{
	Vector3 bestIntersection = ray.origin;
	Vector3 triIntersection;

	for (Indices::const_iterator i = _indices.begin();
		 i != _indices.end();
		 i += 3)
	{
		// Get the vertices for this triangle
		const ArbitraryMeshVertex& p1 = _vertices[*(i)];
		const ArbitraryMeshVertex& p2 = _vertices[*(i+1)];
		const ArbitraryMeshVertex& p3 = _vertices[*(i+2)];

		if (ray.intersectTriangle(localToWorld.transformPoint(p1.vertex), 
			localToWorld.transformPoint(p2.vertex), localToWorld.transformPoint(p3.vertex), triIntersection))
		{
			intersection = triIntersection;
			
			// Test if this surface intersection is better than what we currently have
			float oldDistSquared = (bestIntersection - ray.origin).getLengthSquared();
			float newDistSquared = (triIntersection - ray.origin).getLengthSquared();

			if ((oldDistSquared == 0 && newDistSquared > 0) || newDistSquared < oldDistSquared)
			{
				bestIntersection = triIntersection;
			}
		}
	}

	if ((bestIntersection - ray.origin).getLengthSquared() > 0)
	{
		intersection = bestIntersection;
		return true;
	}
	else
	{
		return false;
	}
}

void MD5Surface::setDefaultMaterial(const std::string& name)
{
	_originalShaderName = name;
}

const AABB& MD5Surface::localAABB() const {
	return _aabb_local;
}

void MD5Surface::render(RenderableCollector& collector, const Matrix4& localToWorld, 
						const ShaderPtr& shader, const IRenderEntity& entity) const
{
	assert(shader); // shader must be captured at this point

	collector.SetState(shader, RenderableCollector::eFullMaterials);
	collector.addRenderable(*this, localToWorld, entity);
}

int MD5Surface::getNumVertices() const
{
	return static_cast<int>(_vertices.size());
}

int MD5Surface::getNumTriangles() const
{
	return static_cast<int>(_indices.size() / 3);
}

const ArbitraryMeshVertex& MD5Surface::getVertex(int vertexIndex) const
{
	assert(vertexIndex >= 0 && vertexIndex < static_cast<int>(_vertices.size()));
	return _vertices[vertexIndex];
}

model::ModelPolygon MD5Surface::getPolygon(int polygonIndex) const
{
	assert(polygonIndex >= 0 && polygonIndex*3 < _indices.size());

	model::ModelPolygon poly;

	poly.a = _vertices[_indices[polygonIndex*3]];
	poly.b = _vertices[_indices[polygonIndex*3 + 1]];
	poly.c = _vertices[_indices[polygonIndex*3 + 2]];

	return poly;
}

const std::string& MD5Surface::getDefaultMaterial() const
{
	return _originalShaderName;
}

void MD5Surface::updateToDefaultPose(const MD5Joints& joints)
{
	if (_vertices.size() != _mesh->vertices.size())
	{
		_vertices.resize(_mesh->vertices.size());
	}

	for (std::size_t j = 0; j < _mesh->vertices.size(); ++j)
	{
		MD5Vert& vert = _mesh->vertices[j];

		Vector3 skinned(0, 0, 0);

		for (std::size_t k = 0; k != vert.weight_count; ++k)
		{
			MD5Weight& weight = _mesh->weights[vert.weight_index + k];
			const MD5Joint& joint = joints[weight.joint];

			Vector3 rotatedPoint = joint.rotation.transformPoint(weight.v);
			skinned += (rotatedPoint + joint.position) * weight.t;
		}

		_vertices[j].vertex = skinned;
		_vertices[j].texcoord = TexCoord2f(vert.u, vert.v);
		_vertices[j].normal = Normal3f(0,0,0);
	}

	// Ensure the index array is ok
	if (_indices.empty())
	{
		buildIndexArray();
	}

	buildVertexNormals();

	updateGeometry();
}

void MD5Surface::updateToSkeleton(const MD5Skeleton& skeleton)
{
	// Ensure we have all vertices allocated
	if (_vertices.size() != _mesh->vertices.size())
	{
		_vertices.resize(_mesh->vertices.size());
	}

	// Deform vertices to fit the skeleton
	for (std::size_t j = 0; j < _mesh->vertices.size(); ++j)
	{
		MD5Vert& vert = _mesh->vertices[j];

		Vector3 skinned(0, 0, 0);

		for (std::size_t k = 0; k != vert.weight_count; ++k)
		{
			MD5Weight& weight = _mesh->weights[vert.weight_index + k];
			const IMD5Anim::Key& key = skeleton.getKey(weight.joint);
			//const Joint& joint = skeleton.getJoint(weight.joint);

			Vector3 rotatedPoint = key.orientation.transformPoint(weight.v);
			skinned += (rotatedPoint + key.origin) * weight.t;
		}

		_vertices[j].vertex = skinned;
		_vertices[j].texcoord = TexCoord2f(vert.u, vert.v);
		_vertices[j].normal = Normal3f(0,0,0);
	}

	// Ensure the index array is ok
	if (_indices.empty())
	{
		buildIndexArray();
	}

	buildVertexNormals();

	updateGeometry();
}

void MD5Surface::buildVertexNormals()
{
	for (Indices::iterator j = _indices.begin(); j != _indices.end(); j += 3)
	{
		ArbitraryMeshVertex& a = _vertices[*(j + 0)];
		ArbitraryMeshVertex& b = _vertices[*(j + 1)];
		ArbitraryMeshVertex& c = _vertices[*(j + 2)];

		Vector3 weightedNormal((c.vertex - a.vertex).crossProduct(b.vertex - a.vertex));

		a.normal += weightedNormal;
		b.normal += weightedNormal;
		c.normal += weightedNormal;
	}

	// Normalise all normal vectors
	for (Vertices::iterator j = _vertices.begin(); j != _vertices.end(); ++j)
	{
		j->normal = Normal3f(j->normal.getNormalised());
	}
}

void MD5Surface::buildIndexArray()
{
	_indices.clear();

	// Build the indices based on the triangle information
	for (MD5Tris::const_iterator j = _mesh->triangles.begin(); j != _mesh->triangles.end(); ++j)
	{
		const MD5Tri& tri = (*j);

		_indices.push_back(static_cast<RenderIndex>(tri.a));
		_indices.push_back(static_cast<RenderIndex>(tri.b));
		_indices.push_back(static_cast<RenderIndex>(tri.c));
	}
}

void MD5Surface::parseFromTokens(parser::DefTokeniser& tok)
{
	// Start of datablock
	tok.assertNextToken("mesh");
	tok.assertNextToken("{");

	// Get the reference to the mesh definition
	MD5Mesh& mesh = *_mesh;

	// Get the shader name
	tok.assertNextToken("shader");
	setDefaultMaterial(tok.nextToken());

	// ----- VERTICES ------

	// Read the vertex count
	tok.assertNextToken("numverts");
	std::size_t numVerts = string::convert<std::size_t>(tok.nextToken());

	// Initialise the vertex vector
	MD5Verts& verts = mesh.vertices;
	verts.resize(numVerts);

	// Populate each vertex struct with parsed values
	for (MD5Verts::iterator vt = verts.begin(); vt != verts.end(); ++vt) {

		tok.assertNextToken("vert");

		// Index of vert
		vt->index = string::convert<std::size_t>(tok.nextToken());

		// U and V texcoords
		tok.assertNextToken("(");
		vt->u = string::convert<float>(tok.nextToken());
		vt->v = string::convert<float>(tok.nextToken());
		tok.assertNextToken(")");

		// Weight index and count
		vt->weight_index = string::convert<std::size_t>(tok.nextToken());
		vt->weight_count = string::convert<std::size_t>(tok.nextToken());

	} // for each vertex

	// ------  TRIANGLES ------

	// Read the number of triangles
	tok.assertNextToken("numtris");
	std::size_t numTris = string::convert<std::size_t>(tok.nextToken());

	// Initialise the triangle vector
	MD5Tris& tris = mesh.triangles;
	tris.resize(numTris);

	// Read each triangle
	for(MD5Tris::iterator tr = tris.begin(); tr != tris.end(); ++tr) {

		tok.assertNextToken("tri");

		// Triangle index, followed by the indexes of its 3 vertices
		tr->index = string::convert<std::size_t>(tok.nextToken());
		tr->a = 	string::convert<std::size_t>(tok.nextToken());
		tr->b = 	string::convert<std::size_t>(tok.nextToken());
		tr->c = 	string::convert<std::size_t>(tok.nextToken());

	} // for each triangle

	// -----  WEIGHTS ------

	// Read the number of weights
	tok.assertNextToken("numweights");
	std::size_t numWeights = string::convert<std::size_t>(tok.nextToken());

	// Initialise weights vector
	MD5Weights& weights = mesh.weights;
	weights.resize(numWeights);

	// Populate with weight data
	for(MD5Weights::iterator w = weights.begin(); w != weights.end(); ++w) {

		tok.assertNextToken("weight");

		// Index and joint
		w->index = string::convert<std::size_t>(tok.nextToken());
		w->joint = string::convert<std::size_t>(tok.nextToken());

		// Strength and relative position
		w->t = string::convert<float>(tok.nextToken());
		w->v = MD5Model::parseVector3(tok);

	} // for each weight

	// ----- END OF MESH DECL -----

	tok.assertNextToken("}");
}

} // namespace md5
