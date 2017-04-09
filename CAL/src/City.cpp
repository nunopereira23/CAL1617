
#include <cmath>
#include <vector>
#include "City.h"

using namespace std;

int City::cid = 0;

double City::distance(const City &c1, const City &c2) {
	return sqrt(pow(c2.lon-c1.lon, 2)+pow(c2.lat-c1.lat, 2));
}

double City::distance(const vector<City> &cities) {
	double dist = 0;

	for (vector<City>::const_iterator c = cities.begin() + 1; c != cities.end(); c++)
		dist += City::distance(*(c-1), *c);
	return dist;
}

City::City(string name, double price, double lat, double lon) :
		id(City::cid++), name(name), price(price), lat(lat + 90), lon(lon + 180) { }

string City::getName() const {
	return this->name;
}

int City::getXCoord(int xRes) const {
	return lon*xRes/360;
}

int City::getYCoord(int yRes) const {
	return yRes-lat*yRes/180;
}

int City::getId() const {
	return this->id;
}

double City::getLatitude() const{
	return this->lat;
}

double City::getLongitude() const{
	return this->lon;
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

bool City::operator!=(const City &c){
	return this->id != c.getId();
}

ostream & operator<<(ostream &os, City &c1){

	os << c1.getName() << ", " << c1.getLatitude() << ", " << c1.getLongitude() << ";";
}
