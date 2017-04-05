/*
 * Node.h
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */

#ifndef SRC_CITY_H_
#define SRC_CITY_H_

#include <string>
#include <vector>

#include "Travel.h"

class City {
	private:
	std::string name;
	double price;
	double lat;
	double lon;

	std::vector<Travel> travels;

public:
	City(std::string name, double price, double lat, double lon);
	void addTravel(Travel t);
	void removeTravelTo(City *c);
};

#endif /* SRC_CITY_H_ */
