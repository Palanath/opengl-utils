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

float Point3::getX() const {
	return x;
}

float Point3::getY() const {
	return y;
}

float Point3::getZ() const {
	return z;
}

void Point3::setX(const float x) {
	this->x = x;
}

void Point3::setY(const float y) {
	this->y = y;
}

void Point3::setZ(const float z) {
	this->z = z;
}

void Point3::set(const float x, const float y, const float z) {
	setX(x);
	setY(y);
	setZ(z);
}

} /* namespace glutils */
