#include "Parser.h"
#include "Date.h"
#include "SpecialDate.h"

using namespace std;

vector<string> Parser::parseLines(string file) {
	vector<string> lines;

	ifstream inFile(file.c_str());
	if (inFile.is_open()) {
		string line;

		while (getline(inFile, line))
			lines.push_back(line);
		inFile.close();
	}
	return lines;
}

vector<City *> Parser::ParseCities(string file) {
	vector<City *> cities;

	vector<string> lines = Parser::parseLines(file);

	for (unsigned int i = 0; i < lines.size(); i++) {
		string line = lines.at(i);
		string name, lat, lon, pr;
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		lat = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		lon = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		if (line.find(',') != string::npos) {
			pr = line.substr(0, line.find(','));
			line = line.substr(line.find(',') + 2);
		} else {
			pr = line.substr(0, line.find(';'));
		}
		cities.push_back(new City(name, atoi(pr.c_str()), atof(lat.c_str()), atof(lon.c_str())));

		while(line.find(',') != string::npos) {
			string sInitialDate = line.substr(0, line.find(','));
			line = line.substr(line.find(',') + 2);
			string sFinalDate = line.substr(0, line.find(','));
			line = line.substr(line.find(',') + 2);
			string sFactor;
			if (line.find(',') != string::npos) {
				sFactor = line.substr(0, line.find(','));
				line = line.substr(line.find(',') + 2);
			} else {
				sFactor = line.substr(0, line.find(';'));
			}
			Date initialDate(sInitialDate);
			Date finalDate(sFinalDate);
			double factor = atof(sFactor.c_str());
			SpecialDate date(initialDate, finalDate, factor);
			cities.at(cities.size() - 1)->addSpecialDate(date);
		}
	}

	return cities;
}

vector<Link *> Parser::ParseConnections(string file, vector<City *> cities) {
	vector<Link *> links;
	vector<string> lines = Parser::parseLines(file);

	for (unsigned int i = 0; i < lines.size(); i++) {
		string line = lines.at(i);
		string city1 = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		string city2 = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		string pr = line.substr(0, line.find(';'));
		links.push_back(new Link(city1, city2, atof(pr.c_str()), cities));
	}

	return links;
}

vector<Client *> Parser::ParseClients(string file){
	vector<Client *> clientes;

	vector<string> lines = Parser::parseLines(file);
	for (unsigned int i = 0; i < lines.size(); i++) {
		string line = lines.at(i);

		string name, origin, date;
		vector<City *> places;
		line = line.substr(line.find(',') + 2);
		name = line.substr(0,line.find(','));
		line = line.substr(line.find(',') + 2);
		date = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		origin = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		vector<string> destinations;
		while (line.find(',') != string::npos) {
			destinations.push_back(line.substr(0,line.find(',')));
			line = line.substr(line.find(',') + 2);
		}
		destinations.push_back(line.substr(0, line.find(';')));
		Date d(date);
		Client* c = new  Client(name, origin, destinations);
		c->setDate(d);
		clientes.push_back(c);

	}
	return clientes;
}

void Parser::ParsePointsOfInterest(string file, vector<City *> cities) {
	vector<string> lines = Parser::parseLines(file);
	for (unsigned int i = 0; i < lines.size(); i++) {
		string line = lines.at(i);

		string name = line.substr(0,line.find(','));
		line = line.substr(line.find(',') + 2);

		City * city = NULL;
		for(vector<City *>::iterator it = cities.begin(); it != cities.end(); it++) {
			if ((*it)->getName() == name) {
				city = (*it);
			}
		}

		if (!city) {
			cout << "Couldn't find city \"" << name << "\" on parsing points of interest!" << endl;
			continue;
		}

		while (line.find(',') != string::npos) {
			city->addPointsOfInterest(line.substr(0,line.find(',')));
			line = line.substr(line.find(',') + 2);
		}
	}
}
