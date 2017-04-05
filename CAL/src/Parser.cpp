/*
 * Parser.cpp
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */

#include "Parser.h"

#include <fstream>
#include <string>
#include <stdlib.h>
#include "City.h"

using namespace std;

vector<string> Parser::parseLines(string file) {
	vector<string> lines;

	ifstream inFile(file.c_str());

	if (inFile.good() && inFile.is_open()) {
		string line;
		while (getline(inFile, line)) {
			lines.push_back(line);
		}
		inFile.close();
	}
	return lines;
}

vector<City> Parser::ParseCities(string file) {
	vector<City> cities;

	vector<string> lines = Parser::parseLines(file);
	for (unsigned int i = 0; i < lines.size(); i++) {
		string line = lines.at(i);
		string name, lat, lon;
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		lat = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		lon = line.substr(0, line.find(','));
		City city(name, 10, atof(lat.c_str()), atof(lon.c_str()));
		cities.push_back(city);
	}

	return cities;
}
