#include <vector>


using namespace std;

class Agency{
private:
	vector<Client *> clients;
public:
	Agency(vector<Client *> clientes);
	void exportClients();
	void importClients();
};
