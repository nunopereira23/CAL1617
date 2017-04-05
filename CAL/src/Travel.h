/*
 * Edge.h
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */

#ifndef SRC_TRAVEL_H_
#define SRC_TRAVEL_H_
#pragma once

class City;
class Travel {
private:
	City * dest;
	double price;
public:
	Travel();
	Travel(City * dest, double price);
	friend class City;
};

#endif /* SRC_TRAVEL_H_ */
