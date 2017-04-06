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

class City {
	private:
	static int cid;
	std::string name;
	int id;
	double price;
	double lat;
	double lon;


public:
	static double distance(City &c1, City &c2);
	City(std::string name, double price, double lat, double lon);
	void removeTravelTo(City *c);
	int getId() const;
	std::string getName() const;
	double getPrice() const;
	double getLatitude() const;
	double getLongitude() const;
	int getXCoord(int xRes) const;
	int getYCoord(int yRes) const;
	void operator= (const City &c);
	bool operator== (const City &c);
};

#endif /* SRC_CITY_H_ */
