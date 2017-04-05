#include <vector>


using namespace std;


class Agency{
private:
	vector<Client *> clients;
public:
	Agency(vector<Client *> clientes);
	void exportClients();
	void importClients();
	vector<Client *> getClients();
	void addClient(string name, string origin, string dest, int max);
	void addClient(string name, string origin, int max, vector<City *> places);
};
