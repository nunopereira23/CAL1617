#include <cmath>
#include <vector>
#include <climits>
#include "City.h"
#include "matcher.h"

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


City* City::getCity(const string name, const vector<City *> &cities) {
	for (vector<City*>::const_iterator it = cities.begin(); it != cities.end(); it++) {
		if ((*it)->getName() == name) {
			return (*it);
		}
	}
	return NULL;
}

vector<string> City::search(string searchString, vector<City*> cities, bool exactSearch) {
	vector<string> found;
	if (exactSearch) {
		for(vector<City*>::const_iterator city = cities.begin(); city != cities.end(); city++){
			string text = (*city)->getName() + (*city)->PoisToString();
			if (kmp(text, searchString) > 0)
				found.push_back((*city)->getName());
		}
		return found;
	}
	else {
		vector<int> distances;
		for(vector<City*>::const_iterator city = cities.begin(); city != cities.end(); city++) {
			int distance = (*city)->getApproxSearchDistance(searchString);
			if (distances.size() == 0) {
				distances.push_back(distance);
				found.push_back((*city)->getName());
			} else {
				bool wasInserted = false;
				for (unsigned int i = 0; i < distances.size(); i++) {
					if (distances.at(i) > distance) {
						distances.insert(distances.begin() + i, distance);
						found.insert(found.begin() + i, (*city)->getName());
						wasInserted = true;
						break;
					}
				}
				if (!wasInserted) {
					distances.push_back(distance);
					found.push_back((*city)->getName());
				}
			}

		}
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

string City::PoisToString() const {
	string result = "";
	for (unsigned int i = 0; i < pointsOfInterest.size(); i++)
		result += pointsOfInterest.at(i);
	return result;
}

int City::getApproxSearchDistance(string pattern) const {
	string word1;
	int min;
	int num;
	min = editDistance(pattern, this->name);

	for (unsigned int i = 0; i < pointsOfInterest.size(); i++) {
		num = editDistance(pattern, pointsOfInterest.at(i));
		min = min < num ? min : num;
	}
	//cout << name <<": " << ((float)num/nwords) << endl;
	return min;
}

ostream & operator<<(ostream &os, City &c1){

	os << c1.getName() << ", " << (c1.getLatitude()-90) << ", " << (c1.getLongitude()-180) << ", " << c1.getPrice() << ";";
	return os;
}

