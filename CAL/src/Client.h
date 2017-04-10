
#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include <string>
#include <vector>
#include <iostream>
#include "City.h"
#include "Date.h"


class Client {
private:
	static int cId;
	std::string name;
	int id;
	std::string origin;
	std::vector<std::string> places;
	bool _hasDate;
	Date date;
	void dijkstraShortestPath(const City &c);
public:
	Client(std::string nome, std::string origem, std::vector<std::string> places);
	int getId();
	std::string getOrigin();
	std::vector<std::string> getPlaces();
	std::string getName();
	bool hasDate() const;
	void setDate(Date date);
	Date getDate() const;
	bool operator== (Client &c);
	friend std::ostream &operator<< (std::ostream &os, Client &c1);
};

#endif /* SRC_CLIENT_H_ */


