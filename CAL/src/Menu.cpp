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
		string name, origin, dest;
		int max;
		cout << "Indique o nome do cliente" << endl;
		cin.ignore();
		getline(cin, name);

		cout << "Indique a origem da viagem" << endl;
		cin.ignore();
		getline(cin, origin);

		cout << "Indique o destino da viagem" << endl;
		cin.ignore();
		getline(cin, dest);

		cout << "Introduza o nr maximo de dias ate fazer a viagem" << endl;
		cin.ignore();
		cin >> max;

		ag->addClient(name, origin, dest, max);
		clientsMenu(ag); //Importante incluir
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
			break;
		}

		case 3:
		{
			agencyMenu(ag);
			break;
		}
		}
}


