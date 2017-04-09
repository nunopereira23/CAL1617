#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "City.h"
#include "Client.h"
#include "Parser.h"
#include "Link.h"

class Agency{
private:
	std::vector<Client *> clients;
	std::vector<City *> cities;
public:
	Agency();
	void exportClients();
	std::vector<Client *> getClients();
	void addClient(std::string name, std::string origin, std::string dest, int max);
	void addClient(std::string name, std::string origin, int max, std::vector<City *> places);
	void addCity(std::string name, double price, double lat, double lon);
	void showClients();
	void showCities();

};
