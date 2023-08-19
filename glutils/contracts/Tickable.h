/*
 * Tickable.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Palanath
 */

#ifndef GLUTILS_CONTRACTS_TICKABLE_H_
#define GLUTILS_CONTRACTS_TICKABLE_H_

namespace glutils::contracts {

class Tickable {
public:
	virtual void tick() = 0;
	virtual ~Tickable();
};

} /* namespace glutils::contracts */

#endif /* GLUTILS_CONTRACTS_TICKABLE_H_ */
