#include "lib/graphviewer.h"
#include "Agency.h"

using namespace std;


Agency::Agency(vector<Client *> clients, vector<City *> cities, vector<Link *> links){
	this->clients=clients;
	this->cities=cities;
	this->links=links;
}

void Agency::addClient(string name, string origin, vector<string> places, Date date){

	Client* c1 = new Client(name, origin, places);
	c1->setDate(date);
	this->clients.push_back(c1);
}

void Agency::addCity(string name, double price, double lat, double lon){

	City* ct = new City(name, price, lat, lon);

	this->cities.push_back(ct);
}


vector <Client *> Agency::getClients(){
	return this->clients;
}

vector <City *> Agency::getCities(){
	return this->cities;
}

vector <Link *> Agency::getLinks(){
	return this->links;
}

void Agency::showClients(){
	for(vector<Client *>::iterator it = clients.begin(); it!=clients.end();it++){
		cout << *(*it) << endl;
	}
}

void Agency::showCities(){

	vector<City *>::iterator it = cities.begin();
	for(; it!=cities.end();it++){
		cout << *(*it) << endl;
	}
}

void Agency::exportClients(){

	ofstream out;
	out.open("clients.txt");

	for(unsigned int i=0; i<clients.size(); i++){
		out << *clients.at(i) << endl;
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

