/*
 * Node.cpp
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */

#include <cmath>

#include "City.h"

int City::cid = 0;
double City::distance(City &c1, City &c2) {
	return std::sqrt(std::pow(c2.lon-c1.lon, 2)+std::pow(c2.lat-c1.lat, 2));
}

City::City(std::string name, double price, double lat, double lon) :
		id(City::cid++), name(name), price(price), lat(lat + 90), lon(lon + 180) {

}

int City::getXCoord(int xRes) const {
	return lon*xRes/360;
}

int City::getYCoord(int yRes) const {
	return yRes-lat*yRes/180;
}

int City::getId() const {
	return id;
}

void City::operator=(const City &c){
	this->id=c.id;
	this->name=c.name;
	this->lat=c.lat;
	this->lon=lon;
	this->price=c.price;
}


bool City::operator==(const City &c){

	if(this->id == c.id)
		return true;
	else return false;
}
