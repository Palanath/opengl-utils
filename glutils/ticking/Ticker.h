/*
 * Ticker.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Palanath
 */

#ifndef GLUTILS_TICKING_TICKER_H_
#define GLUTILS_TICKING_TICKER_H_

#include <vector>

#include "Tickable.h"

namespace glutils::ticking {

class Ticker {
private:
	std::vector<Tickable*> tickables;
public:
	virtual ~Ticker();
	/*
	 * Adds the provided Tickable to the Ticker. If added twice, the Tickable will be ticked twice per tick.
	 */
	void add(Tickable* tickable);
	/*
	 * Removes the provided Tickable from the Ticker once.
	 */
	void remove(Tickable* tickable);
};

} /* namespace glutils::ticking */

#endif /* GLUTILS_TICKING_TICKER_H_ */
