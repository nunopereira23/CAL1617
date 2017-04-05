
#include "Client.h"

using namespace std;

int Client::cId = 0;

Client::Client(string nome, string origem, string destino, int max){
	this->id=Client::cId++;
	this->name=nome;
	this->origin=origem;
	this->dest=destino;
	this->maxDays=max;
}


Client::Client(string nome, string origem, int max, std::vector<City *> places){
	this->id=Client::cId++;
	this->name=nome;
	this->origin=origem;
	this->places=places;
	this->maxDays=max;
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

bool Client::operator==(Client &c){
	if(this->id==c.id)
		return true;
	else return false;
}
