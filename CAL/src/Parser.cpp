
#include "Parser.h"

using namespace std;

vector<string> Parser::parseLines(string file) {
	vector<string> lines;

	ifstream inFile(file.c_str());
	if (inFile.is_open()) {
		string line;

		while (getline(inFile, line)) {
			lines.push_back(line);
			cout << "LINE:";
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

vector<Link> Parser::ParseConnections(string file, vector<City> cities) {
	vector<Link> links;
	vector<string> lines = Parser::parseLines(file);

	for (unsigned int i = 0; i < lines.size(); i++) {
		string line = lines.at(i);
		string city1 = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		Link link(city1, line, cities);
		links.push_back(link);
	}

	return links;
}

vector<Client *> Parser::ParseClients(string file){
	vector<Client *> clientes;

	vector<string> lines = Parser::parseLines(file);
	for (unsigned int i = 0; i < lines.size(); i++) {
		string line = lines.at(i);

		string name, origin, dest, max;
		vector<City *> places;

		name=line.substr(0,line.find(','));
		line = line.substr(line.find(',') + 2);
		origin = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		dest = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		max = line.substr(0, line.find(';'));
		Client* c = new  Client(name, origin, dest, atoi(max.c_str()));
		clientes.push_back(c);
		cout << clientes[0];
	}
	return clientes;
}
