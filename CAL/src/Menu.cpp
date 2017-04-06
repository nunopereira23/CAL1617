#include "Menu.h"

using namespace std;

//Nao esquecer criar uma agencia sempre

void menuAgencia() {
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
		menuClientes(); //Passado sempre como apontador para evitar a duplicacao desnecessaria de objetos
		break;
	}

	case 2:
	{
//		menuCidades();
		break;
	}

	case 3:
	{
//		menuViagens();
		break;
	}

	case 4:
		break;
	default:
		cout << "Escolha invalida" << endl;
		menuAgencia();
	}
}


void menuClientes(){

	cout << "/***********************/" << endl;
	cout << "1- Novo cliente" << endl;
	cout << "2- Apagar cliente" << endl;
	cout << "3- Consultar cliente" << endl;
	cout << "4- Consultar todos os clientes" << endl;
	cout << "5- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		string nome;
		cout << "Indique o nome do cliente" << endl;
		cin.ignore();
		getline(cin, nome);
		//Cliente c(nome);
		//(*p).addCliente(c);
		menuClientes(); //Importante incluir
		break;
	}
	}
}
