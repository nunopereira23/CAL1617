/*
 * Node.h
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */

#ifndef SRC_CITY_H_
#define SRC_CITY_H_

#include <string>

class City {
public:
	City();
	virtual ~City();

private:
	std::string name;
	double price;
	

};

#endif /* SRC_CITY_H_ */
