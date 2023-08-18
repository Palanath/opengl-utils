/*
 * Point3.cpp
 *
 *  Created on: Aug 17, 2023
 *      Author: Palanath
 */

#include "Point3.h"

namespace glutils {

Point3::Point3() :
		Point3(0, 0, 0) {

}

Point3::~Point3() {
}

Point3::Point3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

} /* namespace glutils */
