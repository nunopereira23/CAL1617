#include <iostream>
#include <iomanip>
#include "Graph.h"
#include "Parser.h"
#include "Menu.h"


using namespace std;

int main() {
	vector<City *> cities = Parser::ParseCities("cities.txt");
	vector<Client *> clients = Parser::ParseClients("clients.txt");
	vector<Link *> links= Parser::ParseConnections("connections.txt", cities);
	Parser::ParsePointsOfInterest("pointsOfInterest.txt", cities);

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
	ag.exportClients();
	ag.exportCities();
	return 0;
}
