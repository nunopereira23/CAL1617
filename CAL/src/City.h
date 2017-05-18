

#ifndef SRC_CITY_H_
#define SRC_CITY_H_

#include <string>
#include <vector>
#include <iostream>
#include "SpecialDate.h"

class City {
	private:
	static int cid;
	int id;
	std::string name;
	double price;
	double lat;
	double lon;
	std::vector<SpecialDate> specialDates;
	std::vector<std::string> pointsOfInterest;


public:
	static double distance(const City &c1, const City &c2);
	static double distance(const std::vector<City> &cities);
	static bool exists(const std::string &city, const std::vector<City *> &cities);
	static bool existsPOI(const std::string &POI, const std::vector<City *> &cities);
	static City* getCity(const std::string name, const std::vector<City *> &cities);
	static std::vector<std::string> search(const std::string searchString, std::vector<City*> cities, bool exactSearch);
	City(std::string name, double price, double lat, double lon);
	void removeTravelTo(City *c);
	int getId() const;
	std::string getName() const;
	double getPrice() const;
	double getPrice(Date date) const;
	double getLatitude() const;
	double getLongitude() const;
	int getXCoord(int xRes) const;
	int getYCoord(int yRes) const;
	void operator= (const City &c);
	bool operator== (const City &c);
	bool operator!= (const City &c);
	friend std::ostream &operator<< (std::ostream &os, City &c1);
	void addSpecialDate(SpecialDate date);
	void addPointsOfInterest(std::string pointOfInterest);
	std::vector<std::string> getPointsOfInterest() const;
	void printPointsOfInterest(std::ostream &os, bool splitLines) const;
};

#endif /* SRC_CITY_H_ */
