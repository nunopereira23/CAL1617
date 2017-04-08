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
public:
	Agency();
	void exportClients();
	void importClients();
	std::vector<Client *> getClients();
	void addClient(std::string name, std::string origin, std::string dest, int max);
	void addClient(std::string name, std::string origin, int max, std::vector<City *> places);
	void showClients();
};
