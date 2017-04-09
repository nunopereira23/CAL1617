#include <iostream>
#include <iomanip>
#include "Graph.h"
#include "Parser.h"
#include "Menu.h"


using namespace std;

void createGraph() {
	//Graph<City> graph;

	vector<City *> cities = Parser::ParseCities("cities.txt");
	vector<Link *> links;
	vector<Client *> clients = Parser::ParseClients("clientes.txt");

	try {
		links = Parser::ParseConnections("connections.txt", cities);
	} catch (ExceptionInvalidCityName& e) {

		cerr << "EInvalidCityName: " << e.info << " - " << e.cityName << endl;
		return;
	}

	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->defineEdgeDashed(true);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	gv->defineEdgeCurved(false);

	for (vector<City *>::iterator city = cities.begin(); city != cities.end(); city++) {
		gv->addNode((*city)->getId(), (*city)->getXCoord(600), (*city)->getYCoord(600));
		gv->setVertexLabel((*city)->getId(), (*city)->getName());
	}

	for (vector<Link *>::iterator link = links.begin(); link != links.end(); link++)
		gv->addEdge((*link)->getId(), (*link)->getOriginId(), (*link)->getDestinationId(), EdgeType::UNDIRECTED);
}

void test() {
	vector<City *> cities = Parser::ParseCities("cities.txt");
	vector<Link *> links;
	vector<Client *> clients = Parser::ParseClients("clientes.txt");
	try {
		links = Parser::ParseConnections("connections.txt", cities);
	} catch (ExceptionInvalidCityName& e) {

		cerr << "EInvalidCityName: " << e.info << " - " << e.cityName << endl;
		return;
	}

	Graph<City> graph;

	for (vector<City *>::iterator city = cities.begin(); city != cities.end(); city++) {
		graph.addVertex(**city);
	}

	for (vector<Link *>::iterator link = links.begin(); link != links.end(); link++) {
		City* o = (*link)->getOrigin();
		City* d = (*link)->getDestination();
		double w = City::distance(*o, *d);
		graph.addEdge(*o, *d, w);
	}

	vector<City*> cs;
	cs.push_back(cities.at(1));
	cs.push_back(cities.at(2));
	//cs.push_back(cities.at(6));
	City* org = cities.at(0);
	graph.dijkstraShortestPath(*org);

	vector<City> tripPath;
	tripPath.push_back(*org);

	while(cs.size() > 0) {
		vector<City> cheapestLink;
		vector<City*>::iterator cheapestLinkIt;
		double lowestPrice = numeric_limits<double>::max();

		for (vector<City*>::iterator it = cs.begin(); it != cs.end(); it++) {
			City origin = *tripPath.end();
			vector<City> currentPath = graph.getPath(origin, **it);
			double currentPrice = City::distance(currentPath);
			if (currentPrice < lowestPrice) {
				lowestPrice = currentPrice;
				cheapestLink = currentPath;
				cheapestLinkIt = it;
			}
		}

		for (vector<City>::iterator it = cheapestLink.begin()+1; it != cheapestLink.end(); it++) {
			tripPath.push_back(*it);
		}
		cs.erase(cheapestLinkIt);

	}

	for (unsigned int i = 0; i < tripPath.size(); i++) {
		cout << tripPath.at(i).getName() << endl;
	}

	vector<City> path = graph.getPath(*org, *cities.at(2));
	for (unsigned int i = 0; i < path.size(); i++) {
		//cout << path.at(i).getName() << endl;
	}
}

Graph<City> createCityGraph(vector<City *> cities, vector<Link *> links) {
	Graph<City> graph;
	for (vector<City *>::iterator city = cities.begin(); city != cities.end(); city++) {
		graph.addVertex(**city);
	}

	for (vector<Link *>::iterator link = links.begin(); link != links.end(); link++) {
		City* o = (*link)->getOrigin();
		City* d = (*link)->getDestination();
		double w = City::distance(*o, *d);
		graph.addEdge(*o, *d, w);
	}
	return graph;
}

vector<City> getShortestPath(Graph<City> graph, City& origin, vector<City*> possibleDestinations) {
	vector<City> shortestPath;
	double weight = numeric_limits<double>::max();

	graph.dijkstraShortestPath(origin);
	for (unsigned int i = 0; i < possibleDestinations.size(); i++) {
		vector<City> path = graph.getPath(origin, *possibleDestinations.at(i));
		double curWeight = City::distance(path);
		if (weight > curWeight) {
			shortestPath = path;
			weight = curWeight;
		}
	}

	return shortestPath;
}

void test1() {
	// Parse files
	vector<City *> cities = Parser::ParseCities("cities.txt");
	vector<Link *> links;
	try {
		links = Parser::ParseConnections("connections.txt", cities);
	} catch (ExceptionInvalidCityName& e) {

		cerr << "EInvalidCityName: " << e.info << " - " << e.cityName << endl;
		return;
	}

	// Create graph
	Graph<City> graph = createCityGraph(cities, links);

	// Origin city
	City* org = cities.at(0);
	graph.dijkstraShortestPath(*org);

	// Cities to visit
	vector<City*> ctv;
	ctv.push_back(cities.at(3));
	ctv.push_back(cities.at(1));
	ctv.push_back(cities.at(2));
	ctv.push_back(cities.at(4));

	// Get shortest path to every city
	vector<City> shortestPath;
	City pathOrigin = *org;
	shortestPath.push_back(pathOrigin);

	while (ctv.size() > 0) {
		vector<City> curShortestPath = getShortestPath(graph, pathOrigin, ctv);
		// Removes city from ctv vector
		for (vector<City*>::iterator it = ctv.begin(); it != ctv.end(); it++) {
			if ((**it).getId() == curShortestPath.at(curShortestPath.size() - 1).getId()){
				ctv.erase(it);
				break;
			}
		}

		// Adds the calculated path to the path vector
		for (vector<City>::iterator it = curShortestPath.begin() + 1; it != curShortestPath.end(); it++) {
			shortestPath.push_back(*it);
		}

		// Makes the next origin the current city
		pathOrigin = shortestPath.at(shortestPath.size() - 1);
	}

	for (vector<City>::iterator it = shortestPath.begin(); it != shortestPath.end(); it++) {
		cout << it->getName() << endl;
	}
}

int main() {
	Agency ag();
	test1();

	//createGraph();
	//agencyMenu();
	//getchar();
	return 0;
}
