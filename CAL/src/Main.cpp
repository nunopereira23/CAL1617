//#include "Graph.h"
#include <iostream>
#include "Agency.h"
#include "Graph.h"
#include "Parser.h"

using namespace std;

void createGraph() {
	//Graph<City> graph;
	vector<City> cities = Parser::ParseCities("cities.txt");
	vector<Link> links;
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

	for (vector<City>::iterator city = cities.begin(); city != cities.end(); city++) {
		gv->addNode(city->getId(), city->getXCoord(600), city->getYCoord(600));
		gv->setVertexLabel(city->getId(), city->getName());
	}

	for (vector<Link>::iterator link = links.begin(); link != links.end(); link++)
		gv->addEdge(link->getId(), link->getOriginId(), link->getDestinationId(), EdgeType::UNDIRECTED);
}

int main() {
	createGraph();
	getchar();
	return 0;
}
