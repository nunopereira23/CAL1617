/*
 * Client.h
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */

#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include <string>
#include <vector>
#include "City.h"

class Client {
private:
	std::string name;
	int maxDays;
	void dijkstraShortestPath(const City &c);
public:
	Client(City origin, City dest);
	Client(City origin, std::vector<City *> places);
	void setMaxDays(int days);
	int getMaxDays(void) const;
	virtual ~Client();
};

#endif /* SRC_CLIENT_H_ */
