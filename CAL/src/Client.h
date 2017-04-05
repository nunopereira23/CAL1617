
#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include <string>
#include <vector>
#include "City.h"

class Client {
private:
	std::string name;
	int maxDays;
	std::string origin;
	std::string dest;
	std::vector<City *> places;
	void dijkstraShortestPath(const City &c);
public:
	Client(std::string nome, City origem, City dest);
	Client(std::string nome, City origem, std::vector<City *> places);
	void setMaxDays(int days);
	int getMaxDays(void) const;
	std::string getName();
	virtual ~Client();
};

#endif /* SRC_CLIENT_H_ */
