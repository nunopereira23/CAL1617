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
	double price;
	City* origin;
	City* destination;
	City* getCityId(std::string city, std::vector<City *> cities) const;

public:
	Link(std::string origin, std::string destination, double price, std::vector<City *> cities);
	int getId() const;
	int getOriginId() const;
	int getDestinationId() const;
	double getPrice() const;
	City* getOrigin() const;
	City* getDestination() const;
};


#endif /* SRC_LINK_H_ */
