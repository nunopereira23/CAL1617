/*
 * Link.cpp
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */


#include "Link.h"
#include <iostream>

using namespace std;

int Link::lid = 0;

int Link::getCityId(string city, vector<City> cities) const {
	for (vector<City>::const_iterator it = cities.begin(); it != cities.end(); it++)
		if (it->getName() == city)
			return cities.end() - it - 1;
	return -1;

}

Link::Link(string origin, string destination, vector<City> cities):
		id(Link::lid++), origin(origin), destination(destination) {
	originId = getCityId(origin, cities);
	if (originId < 0)
		throw ExceptionInvalidCityName("Wrong origin city name!", origin);
	destinationId = getCityId(destination, cities);
	if (destinationId < 0)
		throw ExceptionInvalidCityName("Wrong destination city name!", destination);
}

int Link::getId() const {
	return this->id;
}

int Link::getOriginId() const {
	return this->originId;
}

int Link::getDestinationId() const {
	return this->destinationId;
}

std::string Link::getOrigin() const {
	return this->origin;
}

std::string Link::getDestination() const {
	return this->destination;
}
