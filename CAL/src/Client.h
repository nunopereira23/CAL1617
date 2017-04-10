
#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include <string>
#include <vector>
#include "City.h"
#include <iostream>


class Client {
private:
	static int cId;
	std::string name;
	int id;
	int maxDays;
	std::string origin;
	std::string dest;
	std::vector<std::string> places;
	void dijkstraShortestPath(const City &c);
public:
	Client(std::string nome, std::string origem, std::string dest, int max);
	Client(std::string nome, std::string origem, int max, std::vector<std::string> places);
	void setMaxDays(int days);
	int getMaxDays(void) const;
	int getId();
	std::string getOrigin();
	std::string getDest();
	std::string getName();
	bool operator== (Client &c);
	friend std::ostream &operator<< (std::ostream &os, Client &c1);
};

#endif /* SRC_CLIENT_H_ */


