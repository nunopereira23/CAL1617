#include "Menu.h"
#include "Graph.h"
#include "CityGraphHelper.h"

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
	cout << "3- Visualisar viagem de cliente" << endl;
	cout << "4- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		string name, origin, sDate;
		Date date;
		vector<string> places;

		cout << "Indique o nome do cliente" << endl;
		cin.clear();
		cin.ignore(10000,'\n');
		getline(cin, name);

		cout << "Introduza a data para fazer a viagem (dd-mm-aaaa, 0 para ignorar)" << endl;
		cin.clear();
		getline(cin, sDate);

		cout << "Indique a origem da viagem" << endl;
		cin.clear();
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

		if (sDate == "0")
			date = Date("99-99-9999");
		else
			date = Date(sDate);
		ag->addClient(name, origin, places, date);
		clientsMenu(ag);
		break;
	}
		case 2:
			ag->showClients();
			clientsMenu(ag);
			break;

		case 3:
		{
			cout << "Introduza o ID do cliente:" << endl;
			int id;
			cin.clear();
			cin >> id;

			Client* client = ag->getClients().at(id);
			City* origin;
			vector<City*> ctv; // Cities to visit
			for (unsigned int i = 0; i < ag->getCities().size(); i++) {
				City* city = ag->getCities().at(i);
				if (city->getName() == client->getOrigin()) {
					origin = city;
				} else {
					for (unsigned int j = 0; j < client->getPlaces().size(); j++) {
						if (city->getName() == client->getPlaces().at(j)) {
							ctv.push_back(city);
							break;
						}
					}
				}
			}

			Graph<City> cityGraph;
			if (client->hasDate())
				cityGraph = CityGraphHelper::CreateCityGraph(ag->getCities(), ag->getLinks(), client->getDate());
			else
				cityGraph = CityGraphHelper::CreateCityGraph(ag->getCities(), ag->getLinks());
			vector<City> path = CityGraphHelper::CalculatePath(origin, ctv, cityGraph);

			vector<Link *> pathLinks;
			// Display Graph
			for (unsigned int i = 1; i < path.size() && path.size() > 1; i++)
				pathLinks.push_back(Link::findLink(path.at(i-1).getName(), path.at(i).getName(), ag->getLinks()));
			CityGraphHelper::ShowGraph(path, pathLinks);

			CityGraphHelper::PrintGraph(path);
			clientsMenu(ag);
			break;
		}
		case 4:
			agencyMenu(ag);
			break;
	}
}


void citiesMenu(Agency *ag){

	cout << "/***********************/" << endl;
	cout << "1- Adicionar uma cidade"<<endl;
	cout << "2- Consultar todas as cidades" << endl;
	cout << "3- Visualizar grafo de todas as cidades" << endl;
	cout << "4- Menu Anterior" << endl;
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
		CityGraphHelper::ShowGraph(ag->getCities(), ag->getLinks());
		cout << "Prima ENTER para continuar..." << endl;
		cin.clear();
		getchar();
		citiesMenu(ag);
		break;
	}

	case 4:
	{
		agencyMenu(ag);
		break;
	}
	}
}
