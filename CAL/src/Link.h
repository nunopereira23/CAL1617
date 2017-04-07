/*
 * Link.h
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */

#ifndef SRC_LINK_H_
#define SRC_LINK_H_

#include <string>
#include <vector>
#include "City.h"

struct ExceptionInvalidCityName {
	std::string info;
	std::string cityName;
	ExceptionInvalidCityName(std::string info, std::string cityName):
		info(info), cityName(cityName) {}
};

class Link {
private:
	static int lid;
	int id;
	std::string origin;
	std::string destination;
	int originId;
	int destinationId;
	int getCityId(std::string city, std::vector<City> cities) const;

public:
	Link(std::string origin, std::string destination, std::vector<City> cities);
	int getId() const;
	int getOriginId() const;
	int getDestinationId() const;
	std::string getOrigin() const;
	std::string getDestination() const;
};

#endif /* SRC_LINK_H_ */
