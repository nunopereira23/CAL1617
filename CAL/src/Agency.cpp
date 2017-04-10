#include "lib/graphviewer.h"
#include "Agency.h"

using namespace std;


Agency::Agency(std::vector<Client *> clients, std::vector<City *> cities){
	this->clients=clients;
	this->cities=cities;
}

void Agency::addClient(string name,string origin,string dest,int max){

	Client* c1 = new Client(name, origin, dest, max);

	this->clients.push_back(c1);
}

void Agency::addClient(string name, string origin, int max, vector<string> places){

	Client* c1 = new Client(name, origin, max, places);

	this->clients.push_back(c1);
}

void Agency::addCity(string name, double price, double lat, double lon){

	City* ct = new City(name, price, lat, lon);

	this->cities.push_back(ct);
}


vector <Client *> Agency::getClients(){
	return this->clients;
}


void Agency::showClients(){


	for(vector<Client *>::iterator it = clients.begin(); it!=clients.end();it++){
		cout << *(*it) << endl;
	}
}

void Agency::showCities(){

	vector<City *>::iterator it = cities.begin();
	for(it; it!=cities.end();it++){
		cout << *(*it) << endl;
	}
}

void Agency::exportClients(){

	ofstream out;
	out.open("clients.txt");

	for(unsigned int i=0; i<clients.size(); i++){
		out << *clients[i] <<endl;
	}
	out.close();
}

void Agency::exportCities(){

	ofstream out;
	out.open("cities.txt");

	for(unsigned int i=0; i<cities.size(); i++){
		out << *cities[i] <<endl;
	}
	out.close();
}

