#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "City.h"
#include "Client.h"
#include "Link.h"

class Parser {
private:
	static std::vector<std::string> parseLines(std::string file);
public:
	static std::vector<City *> ParseCities(std::string file);
	static std::vector<Link *> ParseConnections(std::string file, std::vector<City *> cities);
	static std::vector<Client *> ParseClients(std::string file);
	static void ParsePointsOfInterest(std::string file, std::vector<City *> cities);
};


#endif /* SRC_PARSER_H_ */
