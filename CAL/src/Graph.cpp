#include "Graph.h"

void exercicio1();
void exercicio2();
void exercicio3();
/*
void exercicio1()
{
	GraphViewer *gv = new GraphViewer(600, 600, true);

	gv->setBackground("background.jpg");

	gv->createWindow(600, 600);

	gv->defineEdgeDashed(true);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	gv->addNode(0);
	gv->addNode(1);
	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);

	Sleep(2000); // use sleep(1) in linux ; Sleep(2000) on Windows

	gv->removeEdge(0);
	gv->removeNode(1);
	gv->addNode(2);

	gv->rearrange();

	Sleep(2000);

	gv->addEdge(1, 0, 2, EdgeType::UNDIRECTED);
	gv->defineEdgeCurved(false);

	gv->setVertexLabel(0, "Isto e um no");
	gv->setEdgeLabel(1, "Isto e uma aresta");

	gv->setVertexColor(2, "green");
	gv->setEdgeColor(1, "yellow");

	gv->setVertexSize(2, 40);
	gv->setVertexIcon(0, "icon.gif");

	gv->setEdgeDashed(1, false);

	gv->rearrange();

}

void exercicio2()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(600, 600);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");
	gv->addNode(0,300,50);
	gv->addNode(1,318,58);
	gv->addNode(4,300,100);
	gv->addNode(7,282,58);
	gv->addNode(2,325,75);
	gv->addNode(3,318,93);
	gv->addNode(6,275,75);
	gv->addNode(5,282,93);

	gv->addNode(8,150,200);

	gv->setVertexColor(8, "green");
	gv->setVertexColor(9, "blue");
	gv->setVertexColor(10, "green");
	gv->setVertexColor(11, "blue");
	gv->setVertexColor(12, "green");
	gv->setVertexColor(13, "green");
	gv->addNode(9,300,200);
	gv->addNode(10,450,200);
	gv->addNode(11,300,400);

	gv->addNode(12,200,550);
	gv->addNode(13,400,550);

	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
	gv->addEdge(1, 1, 2, EdgeType::UNDIRECTED);
	gv->addEdge(2, 2, 3, EdgeType::UNDIRECTED);
	gv->addEdge(3, 3, 4, EdgeType::UNDIRECTED);
	gv->addEdge(4, 4, 5, EdgeType::UNDIRECTED);
	gv->addEdge(5, 5, 6, EdgeType::UNDIRECTED);
	gv->addEdge(6, 6, 7, EdgeType::UNDIRECTED);
	gv->addEdge(7, 7, 0, EdgeType::UNDIRECTED);

	gv->addEdge(8, 4, 9, EdgeType::UNDIRECTED);
	gv->addEdge(9, 9, 8, EdgeType::UNDIRECTED);
	gv->addEdge(10, 9, 10, EdgeType::UNDIRECTED);
	gv->addEdge(11, 9, 11, EdgeType::UNDIRECTED);
	gv->addEdge(12, 11, 12, EdgeType::UNDIRECTED);
	gv->addEdge(13, 11, 13, EdgeType::UNDIRECTED);


	gv->rearrange();
	bool first=true;

	while(1)
	{
		Sleep(2000);
		if (first)
		{
			gv->removeNode(12);
			gv->removeNode(13);
			first=false;
		}
		else
		{
			gv->removeNode(20);
			gv->removeNode(21);
		}
		gv->addNode(14,250,550);
		gv->addNode(15,350,550);
		gv->addEdge(14, 11, 14, EdgeType::UNDIRECTED);
		gv->addEdge(15, 11, 15, EdgeType::UNDIRECTED);
		gv->rearrange();

		Sleep(2000);
		gv->removeNode(14);
		gv->removeNode(15);
		gv->addNode(16,300,550);
		gv->addNode(17,300,550);
		gv->addEdge(16, 11, 16, EdgeType::UNDIRECTED);
		gv->addEdge(17, 11, 17, EdgeType::UNDIRECTED);
		gv->rearrange();
		Sleep(2000);

		gv->removeNode(16);
		gv->removeNode(17);
		gv->addNode(18,250,550);
		gv->addNode(19,350,550);
		gv->addEdge(18, 11, 18, EdgeType::UNDIRECTED);
		gv->addEdge(19, 11, 19, EdgeType::UNDIRECTED);
		gv->rearrange();
		Sleep(2000);

		gv->removeNode(18);
		gv->removeNode(19);
		gv->addNode(20,200,550);
		gv->addNode(21,400,550);
		gv->addEdge(20, 11, 20, EdgeType::UNDIRECTED);
		gv->addEdge(21, 11, 21, EdgeType::UNDIRECTED);
		gv->rearrange();
	}
}

*/

/*
void exercicio3()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(600, 600);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	ifstream inFile;

	//Ler o ficheiro nos.txt
	inFile.open("nos.txt");

	if (!inFile) {
	    cerr << "Unable to open file datafile.txt";
	    exit(1);   // call system to stop
	}

	std::string line;

	int idNo=0;
	int X=0;
	int Y=0;

	while(std::getline(inFile, line))
	{
	    std::stringstream linestream(line);
	    std::string         data;

	    linestream >> idNo;

	    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
	    linestream >> X;
	    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
	    linestream >> Y;
	    gv->addNode(idNo,X,Y);

	}

	inFile.close();


	//Ler o ficheiro arestas.txt
	inFile.open("arestas.txt");

		if (!inFile) {
		    cerr << "Unable to open file datafile.txt";
		    exit(1);   // call system to stop
		}

		int idAresta=0;
		int idNoOrigem=0;
		int idNoDestino=0;

		while(std::getline(inFile, line))
		{
		    std::stringstream linestream(line);
		    std::string data;


		    linestream >> idAresta;

		    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		    linestream >> idNoOrigem;
		    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		    linestream >> idNoDestino;
		    gv->addEdge(idAresta,idNoOrigem,idNoDestino, EdgeType::UNDIRECTED);

		}

		inFile.close();

	gv->rearrange();
}

 */




void createGraph() {
	Graph<City> graph;
	//std::string name, double price, double lat, double lon)
	/*City lisbon("Lisbon", 10.0, 38.736946, -9.142685);//0
	City madrid("Madrid", 10.0, 40.416775, -3.703790);//1
	City paris("Paris", 10.0, 48.858093, 2.294694);//2
	City london("London", 10.0, 51.509865, -0.118092);//3
	City riodejaneiro("Rio de Janeiro",10.0,-22.970722,-43.182365);//4
	City newyork("New York",10.0,40.730610,-73.935242);//5
	City shanghai("Shanghai",10.0,31.267401,121.522179);//6
	City sydney("Sydney",10.0,-33.865143,151.209900);//7
	City johannesburg("Johannesburg",10.0,-26.195246,28.034088);//8
	City mexicocity("Mexico City",10.0,19.432608,-99.133209);//9
	City moscow("Moscow",10.0,55.751244,37.618423);//10
	City tokyo("Tokyo",10.0,35.652832,139.839478);//11
	City istanbul("Istanbul",10.0,41.015137,28.979530);//12
	City rome("Rome",10.0,41.890251,12.492373);//13
	City munich("Munich",10.0,48.137154,11.576124);//14
	City buenosaires("Buenos Aires",10.0,-34.603722,-58.381592);//15
	City losangeles("Los Angeles",10.0,34.052235,-118.243683);//16
	City jerusalem("Jerusalem",10.0,31.771959,35.217018);//!7
	City bangkok("Bangkok",10.0,13.736717,100.523186);//18
	City luanda("Luanda",10.0,-8.38333,13.2344439);//19*/

	vector<City> cities = Parser::ParseCities("cities.txt");
	vector<Client *> clients = Parser::ParseClients("clients.txt");


	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(600, 600);

	gv->defineEdgeDashed(true);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	for (vector<City>::iterator city = cities.begin(); city != cities.end(); city++)
		gv->addNode(city->getId(), city->getXCoord(600), city->getYCoord(600));

	/*gv->addNode(lisbon.getId(), lisbon.getXCoord(600), lisbon.getYCoord(600));
	gv->addNode(madrid.getId(), madrid.getXCoord(600), madrid.getYCoord(600));
	gv->addNode(paris.getId(), paris.getXCoord(600), paris.getYCoord(600));
	gv->addNode(london.getId(), london.getXCoord(600), london.getYCoord(600));
	gv->addNode(riodejaneiro.getId(), riodejaneiro.getXCoord(600), riodejaneiro.getYCoord(600));
	gv->addNode(newyork.getId(), newyork.getXCoord(600), newyork.getYCoord(600));
	gv->addNode(shanghai.getId(), shanghai.getXCoord(600), shanghai.getYCoord(600));
	gv->addNode(sydney.getId(), sydney.getXCoord(600), sydney.getYCoord(600));
	gv->addNode(johannesburg.getId(), johannesburg.getXCoord(600), johannesburg.getYCoord(600));
	gv->addNode(mexicocity.getId(), mexicocity.getXCoord(600), mexicocity.getYCoord(600));
	gv->addNode(moscow.getId(), moscow.getXCoord(600), moscow.getYCoord(600));
	gv->addNode(tokyo.getId(), tokyo.getXCoord(600), tokyo.getYCoord(600));
	gv->addNode(istanbul.getId(), istanbul.getXCoord(600), istanbul.getYCoord(600));
	gv->addNode(rome.getId(), rome.getXCoord(600), rome.getYCoord(600));
	gv->addNode(munich.getId(), munich.getXCoord(600), munich.getYCoord(600));
	gv->addNode(buenosaires.getId(), buenosaires.getXCoord(600), buenosaires.getYCoord(600));
	gv->addNode(losangeles.getId(), losangeles.getXCoord(600), losangeles.getYCoord(600));
	gv->addNode(jerusalem.getId(), jerusalem.getXCoord(600), jerusalem.getYCoord(600));
	gv->addNode(bangkok.getId(), bangkok.getXCoord(600), bangkok.getYCoord(600));
	gv->addNode(luanda.getId(), luanda.getXCoord(600), luanda.getYCoord(600));*/

	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
	gv->addEdge(1, 1, 2, EdgeType::UNDIRECTED);
	gv->addEdge(2, 1, 3, EdgeType::UNDIRECTED);
	gv->addEdge(3, 2, 3, EdgeType::UNDIRECTED);
	gv->addEdge(4, 6, 11, EdgeType::UNDIRECTED);
	gv->addEdge(5, 6, 18, EdgeType::UNDIRECTED);
	gv->addEdge(6, 11, 18, EdgeType::UNDIRECTED);
	gv->addEdge(7, 6, 7, EdgeType::UNDIRECTED);
	gv->addEdge(8, 18, 7, EdgeType::UNDIRECTED);
	gv->addEdge(9, 7, 16, EdgeType::UNDIRECTED);
	gv->addEdge(10, 16, 5, EdgeType::UNDIRECTED);
	gv->addEdge(11, 16, 9, EdgeType::UNDIRECTED);
	gv->addEdge(12, 5, 9, EdgeType::UNDIRECTED);
	gv->addEdge(13, 9, 4, EdgeType::UNDIRECTED);
	gv->addEdge(14, 4, 1, EdgeType::UNDIRECTED);
	gv->addEdge(15, 2, 4, EdgeType::UNDIRECTED);
	gv->addEdge(16, 2, 13, EdgeType::UNDIRECTED);
	gv->addEdge(17, 2, 14, EdgeType::UNDIRECTED);
	gv->addEdge(18, 14, 10, EdgeType::UNDIRECTED);
	gv->addEdge(19, 13, 19, EdgeType::UNDIRECTED);
	gv->addEdge(20, 19, 0, EdgeType::UNDIRECTED);
	gv->addEdge(21, 19, 8, EdgeType::UNDIRECTED);
	gv->addEdge(22, 8, 1, EdgeType::UNDIRECTED);
	gv->addEdge(23, 11, 6, EdgeType::UNDIRECTED);
	gv->addEdge(24, 10, 3, EdgeType::UNDIRECTED);
	gv->addEdge(25, 11, 10, EdgeType::UNDIRECTED);
	gv->addEdge(26, 3, 0, EdgeType::UNDIRECTED);
}
