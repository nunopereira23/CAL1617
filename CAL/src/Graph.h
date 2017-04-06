/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cstdio>
#include <cmath>
#include <climits>
#include "lib/graphviewer.h"

#include "City.h"
#include "Parser.h"

template <class T> class Edge;
template <class T> class Graph;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;



 void exercicio1();
 void exercicio2();
 void exercicio3();



/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template <class T>
class Vertex {
	T info;
	std::vector<Edge<T>  > adj;
	bool visited;
	bool processing;
	int indegree;
	double dist;
public:

	Vertex(T in);
	friend class Graph<T>;

	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);

	T getInfo() const;
	void setInfo(T info);

	int getDist() const;
	int getIndegree() const;

	bool operator<(const Vertex<T> vertex);

	Vertex* path;
};


template <class T>
struct vertex_greater_than {
    bool operator()(Vertex<T> * a, Vertex<T> * b) const {
        return a->getDist() > b->getDist();
    }
};


template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	d->indegree--; //adicionado do exercicio 5
	typename std::vector<Edge<T> >::iterator it= adj.begin();
	typename std::vector<Edge<T> >::iterator ite= adj.end();
	while (it!=ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		}
		else it++;
	}
	return false;
}

//atualizado pelo exerc�cio 5
template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = 0;
}


template <class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest,w);
	adj.push_back(edgeD);
}

//--
template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
int Vertex<T>::getDist() const {
	return this->dist;
}


template <class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}

template <class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}




/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template <class T>
class Edge {
	Vertex<T> * dest;
	double weight;
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w){}





/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */


void createGraph();

template <class T>
class Graph {
	std::vector<Vertex<T> *> vertexSet;

	//exercicio 5
	int numCycles;
	void getPathTo(Vertex<T> *origin, std::list<T> &res);

	//exercicio 6
	int ** W;   //weight
	int ** P;   //path

public:
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	std::vector<Vertex<T> * > getVertexSet() const;
	int getNumVertex() const;

	Vertex<T>* getVertex(const T &v) const;
	std::vector<T> getPath(const T &origin, const T &dest);

	void dijkstraShortestPath(const T &s);
};


template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}
template <class T>
std::vector<Vertex<T> * > Graph<T>::getVertexSet() const {
	return vertexSet;
}

template <class T>
bool Graph<T>::addVertex(const T &in) {
	typename std::vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename std::vector<Vertex<T>*>::iterator ite= vertexSet.end();
	for (; it!=ite; it++)
		if ((*it)->info == in) return false;
	Vertex<T> *v1 = new Vertex<T>(in);
	vertexSet.push_back(v1);
	return true;
}

template <class T>
bool Graph<T>::removeVertex(const T &in) {
	typename std::vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename std::vector<Vertex<T>*>::iterator ite= vertexSet.end();
	for (; it!=ite; it++) {
		if ((*it)->info == in) {
			Vertex<T> * v= *it;
			vertexSet.erase(it);
			typename std::vector<Vertex<T>*>::iterator it1= vertexSet.begin();
			typename std::vector<Vertex<T>*>::iterator it1e= vertexSet.end();
			for (; it1!=it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}

			typename std::vector<Edge<T> >::iterator itAdj= v->adj.begin();
			typename std::vector<Edge<T> >::iterator itAdje= v->adj.end();
			for (; itAdj!=itAdje; itAdj++) {
				itAdj->dest->indegree--;
			}
			delete v;
			return true;
		}
	}
	return false;
}

template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	typename std::vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename std::vector<Vertex<T>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<T> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->info == sourc )
			{ vS=*it; found++;}
		if ( (*it)->info == dest )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2) return false;
	vD->indegree++;
	vS->addEdge(vD,w);

	return true;
}

template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	typename std::vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename std::vector<Vertex<T>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<T> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->info == sourc )
			{ vS=*it; found++;}
		if ( (*it)->info == dest )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2)
		return false;

	vD->indegree--;

	return vS->removeEdgeTo(vD);
}

template <class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for(unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v) return vertexSet[i];
	return 0;
}

template<class T>
std::vector<T> Graph<T>::getPath(const T &origin, const T &dest){

	std::list<T> buffer;
	Vertex<T>* v = getVertex(dest);

	buffer.push_front(v->info);
	while ( v->path != 0 &&  v->path->info != origin) {
		v = v->path;
		buffer.push_front(v->info);
	}
	if( v->path != 0 )
		buffer.push_front(v->path->info);


	std::vector<T> res;
	while( !buffer.empty() ) {
		res.push_back( buffer.front() );
		buffer.pop_front();
	}
	return res;
}

template<class T>
void Graph<T>::dijkstraShortestPath(const T &s) {

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = 0;
		vertexSet[i]->dist = INT_MAX;
		vertexSet[i]->processing = false;
	}

	Vertex<T>* v = getVertex(s);
	v->dist = 0;

	std::vector< Vertex<T>* > pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());


	while( !pq.empty() ) {

		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;

			if(v->dist + v->adj[i].weight < w->dist ) {

				w->dist = v->dist + v->adj[i].weight;
				w->path = v;

				//se estiver na lista, apenas a actualiza
				if(!w->processing)
				{
					w->processing = true;
					pq.push_back(w);
				}

				make_heap (pq.begin(),pq.end(),vertex_greater_than<T>());
			}
		}
	}
}



void createGraph() {
	Graph<City> graph;
	//std::string name, double price, double lat, double lon)
	City lisbon("Lisbon", 10.0, 38.736946, -9.142685);//0
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
	City luanda("Luanda",10.0,-8.38333,13.2344439);//19

	vector<City> cities = Parser::ParseCities("cities.txt");
	vector<Client *> clients = Parser::ParseClients("clients.txt");


	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(600, 600);

	gv->defineEdgeDashed(true);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	/*
	for (vector<City>::iterator city = cities.begin(); city != cities.end(); city++)
		gv->addNode(city->getId(), city->getXCoord(600), city->getYCoord(600));
		*/

	gv->addNode(lisbon.getId(), lisbon.getXCoord(600), lisbon.getYCoord(600));
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
	gv->addNode(luanda.getId(), luanda.getXCoord(600), luanda.getYCoord(600));

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

#endif /* GRAPH_H_ */
