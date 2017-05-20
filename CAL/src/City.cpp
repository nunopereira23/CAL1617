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

bool City::exists(const string &city, const vector<City *> &cities) {
	for (vector<City *>::const_iterator it = cities.begin(); it != cities.end(); it++)
		if (city == (*it)->getName())
			return true;
	return false;
}

/*bool City::existsPOI(const std::string &POI, const std::vector<City *> &cities){
	for (vector<City *>::const_iterator it = cities.begin(); it != cities.end(); it++){
		for(size_t i=0; i<(*it)->getPointsOfInterest().size();i++){
			if((*it)->getPointsOfInterest().at(i)==POI){
				return true;
			}
		}
	}
return false;
}
 */
City* City::getCity(const string name, const vector<City *> &cities) {
	for (vector<City*>::const_iterator it = cities.begin(); it != cities.end(); it++) {
		if ((*it)->getName() == name) {
			return (*it);
		}
	}
	return NULL;
}


string City::remove_if(string POI)
{
	string dest = POI;
	for (string::iterator itr = POI.begin();itr != POI.end(); itr++){
		if ((*itr) !=" ")
			*(dest++) = *itr;
		else{}
	}
	return dest;
}

string City::stringMatchingPOI(string &POI){
	remove_if(POI);
	vector<string>::iterator itr = pointsOfInterest.begin();
	for(itr; itr!= pointsOfInterest.end(); itr++){
		string potencial = *itr;
		remove_if(potencial);
		if(kmp(potencial, POI))
			return this->name;
	}
	return "";
}


vector<string> City::search(string searchString, std::vector<City*> cities, bool exactSearch) {
	vector<string> found;
	if (exactSearch) {
		string result;
		for(size_t i=0; i < cities.size(); i++){
			if((result = stringMatchingPOI(searchString)) !="")
				found.push_back(result);
		}
		return found;
	}
	else {
		// TODO approximate search on the cities vector; populate found vector with results
	}
	return found;
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

double City::getPrice() const{
	return this->price;
}

double City::getPrice(Date date) const {
	for (vector<SpecialDate>::const_iterator sd = specialDates.begin(); sd != specialDates.end(); sd++)
		if (sd->getInitialDate() < date && date < sd->getFinalDate())
			return this->price * sd->getFactor();
	return this->price;
}

void City::addSpecialDate(SpecialDate date) {
	specialDates.push_back(date);
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

void City::addPointsOfInterest(string pointOfInterest) {
	this->pointsOfInterest.push_back(pointOfInterest);
}

void City::printPointsOfInterest(ostream &os, bool splitLines) const {
	for (vector<string>::const_iterator poi = pointsOfInterest.begin(); poi != pointsOfInterest.end(); poi++) {
		if (splitLines) {
			if (poi != pointsOfInterest.begin()) {
				os << endl;
			}
			os << "\t- " << *poi;
		} else {
			if (poi != pointsOfInterest.begin()) {
				os << ", ";
			}
			os << *poi;
		}
	}
}

vector<string> City::getPointsOfInterest() const {
	return this->pointsOfInterest;
}

ostream & operator<<(ostream &os, City &c1){

	os << c1.getName() << ", " << (c1.getLatitude()-90) << ", " << (c1.getLongitude()-180) << ", " << c1.getPrice() << ";";
	return os;
}

