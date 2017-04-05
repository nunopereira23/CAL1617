
#include "Client.h"

using namespace std;

Client::Client(string nome, City origem, City destino){
	this->name=nome;
	this->origin=origem;
	this->dest=destino;
}


Client::Client(string nome, City origem, std::vector<City *> places){
	this->name=nome;
	this->origin=origem;
	this->places=places;
}


string Client::getName(){
	return this->name;
}


int Client::getMaxDays() const {
	return this->maxDays;
}

void Client::setMaxDays(int x){
	this->maxDays=x;
}
