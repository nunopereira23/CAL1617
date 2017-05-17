#include <iostream>
#include <iomanip>
#include "Graph.h"
#include "Parser.h"
#include "Menu.h"

#define CITIES_FILE "cities.txt"
#define CLIENTS_FILE "clients.txt"
#define CONNECTIONS_FILE "connections.txt"
#define POIS_FILE "pointsOfInterest.txt"

using namespace std;

int main() {
	vector<City *> cities = Parser::ParseCities(CITIES_FILE);
	vector<Client *> clients = Parser::ParseClients(CLIENTS_FILE);
	vector<Link *> links= Parser::ParseConnections(CONNECTIONS_FILE, cities);
	Parser::ParsePointsOfInterest(POIS_FILE, cities);

	vector<string> poi = cities.at(0)->getPointsOfInterest();
	cout << "Lisboa" << endl;
	for (unsigned int i = 0; i < poi.size(); i++)
		cout << poi.at(i) << endl;

	poi = cities.at(1)->getPointsOfInterest();
	cout << "Madrid" << endl;
	for (unsigned int i = 0; i < poi.size(); i++)
		cout << poi.at(i) << endl;

	Agency ag(clients, cities, links);
	agencyMenu(&ag);
	ag.exportClients(CLIENTS_FILE);
	ag.exportCities(CITIES_FILE);
	ag.exportPointsOfInterest(POIS_FILE);
	return 0;
}
