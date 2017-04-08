#include "Menu.h"

using namespace std;


void agencyMenu() {

	Agency ag();

	cout << "/***********************/" << endl;
	cout << "1- Clientes" << endl;
	cout << "2- Cidades" << endl;
	cout << "3- Viagens" << endl;
	cout << "4- Sair" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		clientsMenu(); //Passado sempre como apontador para evitar a duplicacao desnecessaria de objetos
		break;
	}

	case 2:
	{
		//		citiesMenu();
		break;
	}

	case 3:
	{
		//		travelsMenu();
		break;
	}

	case 4:
		break;
	default:
		cout << "Escolha invalida" << endl;
		agencyMenu();
	}
}


void clientsMenu(){

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
		clientsMenu(); //Importante incluir
		break;
	}

	case 2:
		ag.showClients();
		clientsMenu();
		break;

	case 3:
		agencyMenu();
		break;
	}
}
