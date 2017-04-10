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

	Agency ag(clients, cities, links);
	agencyMenu(&ag);
	ag.exportClients();
	ag.exportCities();
	return 0;
}
