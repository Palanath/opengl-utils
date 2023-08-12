/*
 * Model.cpp
 *
 *  Created on: Aug 7, 2023
 *      Author: Palanath
 */

#include "../multiple-vaos/Model.h"

namespace pala::opengl::tests::multiple_vaos {
Model::Model() {
	// TODO Auto-generated constructor stub
	glGenVertexArrays(1, &vao);
}

Model::~Model() {

}

unsigned Model::addData(float data[], int dataSize) {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	vbos.push_back(vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);

	return vbos.size() - 1;
}

/*
 * Specifies one of the attributes.
 *
 * The first parameter is the layout location of the attribute.
 * The second is the vboIndex, i.e., the value returned by the call to addData(float[], int) which specified the VBO containing the data of the attribute being specified.
 * The third paarameter is the number of components in the attribute. For a 2D float position, this will be 2.
 * The fourth parameter is the stride between the same component in two adjacent vertices' attributes, specified in floats.
 * The fifth parameter is the position of the first vertex's attribute. The position is given in floats.
 */
void Model::specifyAttribute(unsigned attribLayoutLoc, unsigned vboIndex,
		unsigned components, unsigned attributeFloatStride,
		unsigned firstAttributeFloatOffset) {
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[vboIndex]);
	glVertexAttribPointer(attribLayoutLoc, components, GL_FLOAT, false,
			sizeof(float) * attributeFloatStride,
			(void*) (sizeof(float) * firstAttributeFloatOffset));
	glEnableVertexAttribArray(attribLayoutLoc);
}

void Model::draw(unsigned vertices, unsigned offset) {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, offset, vertices);
}
}  // namespace pala::opengl::tests::multiple_vaos
