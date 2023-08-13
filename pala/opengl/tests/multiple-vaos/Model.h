/*
 * Model.h
 *
 *  Created on: Aug 7, 2023
 *      Author: Palanath
 */

#ifndef MODEL_H_
#define MODEL_H_
#include <GL/glew.h>
#include <vector>

namespace pala::opengl::tests::multiple_vaos {
class Model {
	GLuint vao;
	std::vector<GLuint> vbos;
public:
	Model();
	virtual ~Model();

	/*
	 * Creates a VBO and uploads the specified float array to it.
	 * The size of the float array should be provided in bytes.
	 *
	 * The index of the VBO is returned.
	 * This index can be used in other member functions of this class, on this object.
	 */
	unsigned addData(float[], int);

	/*
	 * Specifies a vertex array attribute pointer.
	 *
	 * The attribLayoutLoc is the generic vertex attribute array index.
	 * The vboIndex should be the index of a VBO returned from a call to addData.
	 * The components parameter specifies the number of float components in the attribute.
	 * The attributeFloatStride parameter specifies the number of float values between one component of one vertex in the array and that same component of the next vertex in the array.
	 * The firstAttributeFloatOffset specifies the number of float values before the attribute data begins in the buffer.
	 */
	void specifyAttribute(unsigned, unsigned, unsigned, unsigned, unsigned);

	/*
	 * Draws this Model using the GL_TRIANGLES drawing mode.
	 *
	 * The number of vertices to draw is specified in the first argument.
	 * The second parameter specifies the offset, in vertices, of where to begin drawing.
	 * The third parameter is the number of instances to draw.
	 */
	void draw(unsigned, unsigned = 0, unsigned=1);
};
}  // namespace pala::opengl::tests::multiple_vaos

#endif /* MODEL_H_ */
