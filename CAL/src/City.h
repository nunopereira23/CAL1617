

#ifndef SRC_CITY_H_
#define SRC_CITY_H_

#include <string>
#include <vector>
#include <iostream>

class City {
	private:
	static int cid;
	int id;
	std::string name;
	double price;
	double lat;
	double lon;


public:
	static double distance(const City &c1, const City &c2);
	static double distance(const std::vector<City> &cities);
	static bool exists(const std::string &city, const std::vector<City *> &cities);
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
	bool operator!= (const City &c);
	friend std::ostream &operator<< (std::ostream &os, City &c1);

};

#endif /* SRC_CITY_H_ */
