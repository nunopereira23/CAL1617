#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "City.h"
#include "Client.h"
#include "Parser.h"
#include "Link.h"
#include "Date.h"

class Agency{
private:
	std::vector<Client *> clients;
	std::vector<City *> cities;
	std::vector<Link *> links;
public:
	Agency(std::vector<Client *> clients, std::vector<City *> cities, std::vector<Link *> links);
	void exportClients(std::string file) const;
	void exportCities(std::string file) const;
	void exportPointsOfInterest(std::string file) const;
	std::vector<Client *> getClients();
	std::vector<City *> getCities();
	std::vector<Link *> getLinks();
	void addClient(std::string name, std::string origin, std::vector<std::string> places, Date date);
	void addCity(std::string name, double price, double lat, double lon);
	void showClients();
	void showCities();
};

