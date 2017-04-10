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
	vector<Client *> clients = Parser::ParseClients("clients.txt");

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

Graph<City> CreateCityGraph(vector<City *> cities, vector<Link *> links) {
	Graph<City> graph;
	for (vector<City *>::iterator city = cities.begin(); city != cities.end(); city++) {
		graph.addVertex(**city);
	}

	for (vector<Link *>::iterator link = links.begin(); link != links.end(); link++) {
		City* o = (*link)->getOrigin();
		City* d = (*link)->getDestination();
		double w = (*link)->getPrice() + d->getPrice();
		graph.addEdge(*o, *d, w);
	}
	return graph;
}

Graph<City> CreateCityGraph(vector<City *> cities, vector<Link *> links, Date date) {
	Graph<City> graph;
	for (vector<City *>::iterator city = cities.begin(); city != cities.end(); city++) {
		graph.addVertex(**city);
	}

	for (vector<Link *>::iterator link = links.begin(); link != links.end(); link++) {
		City* o = (*link)->getOrigin();
		City* d = (*link)->getDestination();
		double w = (*link)->getPrice() + d->getPrice(date);
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

vector<City> CalculatePath(City* origin, vector<City*> ctv, Graph<City> graph) {
	graph.dijkstraShortestPath(*origin);

	// Get shortest path to every city
	vector<City> shortestPath;
	City pathOrigin = *origin;
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

	return shortestPath;
}

int main() {
	vector<City *> cities = Parser::ParseCities("cities.txt");
	vector<Client *> clients = Parser::ParseClients("clients.txt");
	vector<Link *> links= Parser::ParseConnections("connections.txt", cities);

	Agency ag(clients, cities, links);
	agencyMenu(&ag);
	ag.exportClients();
	ag.exportCities();
	return 0;
}
