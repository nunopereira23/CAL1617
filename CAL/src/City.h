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
public:
	City();

private:
	std::string name;
	double price;
	//std::vector<Travel> travels;

};

#endif /* SRC_CITY_H_ */
