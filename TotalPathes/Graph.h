#pragma once
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <fstream>
#include <list>
#include "Edge.h"
#include "Matrix.h"

class Graph
{
public:
	Graph(int v);

	bool load_edge_list(char* filename);
	Matrixi get_matrix();
	std::list<Edge> get_edges();
	int vertex_count();

	int& operator()(int v1, int v2);
//private:
	Matrixi _matrix;
	std::list<Edge> _edges;
};

#endif // !_GRAPH_H_