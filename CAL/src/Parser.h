/*
 * Parser.h
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include <string>
#include <vector>
#include "City.h"

class Parser {
private:
	static std::vector<std::string> parseLines(std::string file);
public:
	static std::vector<City> ParseCities(std::string file);


};

#endif /* SRC_PARSER_H_ */
