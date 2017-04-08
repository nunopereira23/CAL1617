
#include "lib/graphviewer.h"
#include "Agency.h"

using namespace std;

void Agency::addClient(string name,string origin,string dest,int max){

	Client* c1 = new Client(name, origin, dest, max);

	this->clients.push_back(c1);
}

void Agency::addClient(string name, string origin, int max, vector<City *> places){

	Client* c1 = new Client(name, origin, max, places);

	this->clients.push_back(c1);
}


vector <Client *> Agency::getClients(){
	return this->clients;
}


void Agency::showClients(){

	for (int i=0; i< clients.size();i++){
		cout << clients[i] << endl;
	}
}
