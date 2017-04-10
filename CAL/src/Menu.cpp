#include "Menu.h"

using namespace std;


void agencyMenu(Agency *ag) {

	cout << "/***********************/" << endl;
	cout << "1- Clientes" << endl;
	cout << "2- Cidades" << endl;
	cout << "3- Sair" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		clientsMenu(ag);
		break;
	}

	case 2:
	{
		citiesMenu(ag);
		break;
	}


	case 3:
		break;
	default:
		cout << "Escolha invalida" << endl;
		agencyMenu(ag);
	}
}


void clientsMenu(Agency *ag){

	cout << "/***********************/" << endl;
	cout << "1- Novo cliente" << endl;
	cout << "2- Consultar todos os clientes" << endl;
	cout << "3- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		string name, origin;
		int max;
		vector<string> places;

		cout << "Indique o nome do cliente" << endl;
		cin.clear();
		cin.ignore(10000,'\n');
		getline(cin, name);

		cout << "Introduza o nr maximo de dias ate fazer a viagem" << endl;
		cin.clear();
		cin >> max;

		cout << "Indique a origem da viagem" << endl;
		cin.clear();
		cin.ignore(10000,'\n');
		getline(cin, origin);

		string input;
		do {
			cout << "Indique os seus destinos (0 para terminar)" << endl;
			cin.clear();
			getline(cin, input);

			if(City::exists(input, ag->getCities())) {
				places.push_back(input);
			} else if (input != "0"){
				cout << "Nao existe nenhuma cidade com o nome que introduziu! Por favor tente novamente." << endl;
			}
		} while(input != "0");
		ag->addClient(name, origin, max, places);
		clientsMenu(ag);
		break;
	}
		case 2:
			ag->showClients();
			clientsMenu(ag);
			break;

		case 3:
			agencyMenu(ag);
			break;
	}
}


void citiesMenu(Agency *ag){

	cout << "/***********************/" << endl;
	cout << "1- Adicionar uma cidade"<<endl;
	cout << "2- Consultar todas as cidades" << endl;
	cout << "3- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		string name;
		double price, lat, lon;

		cout << "Indique o nome da cidade" << endl;
		cin.ignore();
		getline(cin, name);

		cout << "Indique o preço associado a cidade" << endl;
		cin.ignore();
		cin >> price;

		cout << "Indique a latitude da cidade" << endl;
		cin.ignore();
		cin >> lat;

		cout << "Introduza a longitude da cidade" << endl;
		cin.ignore();
		cin >> lon;

		ag->addCity(name, price, lat, lon);
		citiesMenu(ag);
		break;
	}

	case 2:
	{
		ag->showCities();
		citiesMenu(ag);
		break;
	}

	case 3:
	{
		agencyMenu(ag);
		break;
	}
	}
}
