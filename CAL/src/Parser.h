/*
 * Parser.h

 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "City.h"
#include "Client.h"

class Parser {
private:
	static std::vector<std::string> parseLines(std::string file);
public:
	static std::vector<City> ParseCities(std::string file);
	static std::vector<Client *> ParseClients(std::string file);


};

#endif /* SRC_PARSER_H_ */
