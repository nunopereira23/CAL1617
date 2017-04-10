
#include "Client.h"

using namespace std;

int Client::cId = 0;

Client::Client(string nome, string origem, vector<string> places) {
	this->id=Client::cId++;
	this->name=nome;
	this->origin=origem;
	this->places=places;
	this->_hasDate = false;
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

bool Client::operator==(Client &c){
	if(this->id==c.id)
		return true;
	else return false;
}

bool Client::hasDate() const {
	return this->_hasDate;
}

void Client::setDate(Date date) {
	this->date = date;
	if (!date.isInvalid())
		this->_hasDate = true;
	else
		this->_hasDate = false;
}

Date Client::getDate() const {
	return this->date;
}


ostream & operator<<(ostream &os, Client &c1){

	os << c1.getId() << ", " << c1.getName() << ", " << c1.getDate() << ", " << c1.getOrigin();
	for (unsigned int i = 0; i < c1.getPlaces().size(); i++) {
		os << ", " << c1.getPlaces().at(i);
	}
	os << ";";
	return os;
}
