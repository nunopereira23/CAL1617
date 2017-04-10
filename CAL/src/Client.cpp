
#include "Client.h"

using namespace std;

int Client::cId = 0;

Client::Client(string nome, string origem, int max, vector<string> places){
	this->id=Client::cId++;
	this->name=nome;
	this->origin=origem;
	this->places=places;
	this->maxDays=max;
}


string Client::getName(){
	return this->name;
}

int Client::getId(){
	return this->id;
}

string Client::getOrigin(){
	return this->origin;
}

vector<string> Client::getPlaces(){
	return this->places;
}

int Client::getMaxDays() const {
	return this->maxDays;
}

void Client::setMaxDays(int x){
	this->maxDays=x;
}

bool Client::operator==(Client &c){
	if(this->id==c.id)
		return true;
	else return false;
}


ostream & operator<<(ostream &os, Client &c1){

	os << c1.getId() << ", " << c1.getName() << ", " << c1.getMaxDays() << ", " << c1.getOrigin();
	for (unsigned int i = 0; i < c1.getPlaces().size(); i++) {
		os << ", " << c1.getPlaces().at(i);
	}
	os << ";";
	return os;
}


/*
ostream & operator<<(ostream &os, Client &c1){

	os << c1.getId() << ", " << c1.getName() << ", " << c1.getMaxDays() << ", " << c1.getOrigin() << ", ";

for(unsigned int i=0; i < c1.getPlaces().size()-1; i++){
	os << c1.getPlaces().at(i) << ", ";
}
	os << c1.getPlaces()[c1.getPlaces().size()-1] << ";";
	return os;
}

*/
