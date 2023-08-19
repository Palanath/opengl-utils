/*
 * Tickable.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Palanath
 */

#ifndef GLUTILS_CONTRACTS_TICKABLE_H_
#define GLUTILS_TICKING_TICKABLE_H_

namespace glutils::ticking {

class Tickable {
public:
	virtual void tick() = 0;
	virtual ~Tickable();
};

} /* namespace glutils::ticking */

#endif /* GLUTILS_CONTRACTS_TICKABLE_H_ */
