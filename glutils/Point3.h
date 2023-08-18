/*
 * Point3.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Palanath
 */

#ifndef GLUTILS_POINT3_H_
#define GLUTILS_POINT3_H_

namespace glutils {

class Point3 {
public:
	float x, y, z;
	Point3();
	Point3(float, float, float);
	virtual ~Point3();

	float getX() const;
	float getY() const;
	float getZ() const;
	void setX(const float);
	void setY(const float);
	void setZ(const float);
	void set(const float, const float, const float);
};

} /* namespace glutils */

#endif /* GLUTILS_POINT3_H_ */
