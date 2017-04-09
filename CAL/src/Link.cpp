#include "Link.h"
#include <iostream>

using namespace std;

int Link::lid = 0;

City* Link::getCityId(string city, vector<City *> cities) const {
	for (vector<City *>::const_iterator it = cities.begin(); it != cities.end(); it++)
		if ((*it)->getName() == city)
			return (*it);
	return 0;
}

Link::Link(string origin, string destination, double price, vector<City *> cities):
		id(Link::lid++) {
	this->price=price;
	this->origin = getCityId(origin, cities);
	if (!this->origin)
		throw ExceptionInvalidCityName("Wrong origin city name!", origin);
	this->destination = getCityId(destination, cities);
	if (!this->destination)
		throw ExceptionInvalidCityName("Wrong destination city name!", destination);
}

int Link::getId() const {
	return this->id;
}

int Link::getOriginId() const {
	return this->origin->getId();
}

int Link::getDestinationId() const {
	return this->destination->getId();
}

double Link::getPrice() const{
	return this->price;
}

City* Link::getOrigin() const {
	return this->origin;
}

City* Link::getDestination() const {
	return this->destination;
}



