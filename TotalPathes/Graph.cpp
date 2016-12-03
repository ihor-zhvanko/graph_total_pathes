#include "Graph.h"

Graph::Graph(int v)
	: _matrix(v, v)
{
	_matrix.initialize(0);
}

bool Graph::load_edge_list(char * filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		return false;

	while (!file.eof())
	{
		Edge e;
		file >> e;
		_matrix(e.x1 - 1, e.x2 - 1) += 1;
		_edges.push_back({ 
			e.x1 - 1, 
			e.x2 - 1 
		});
	}

	file.close();

	return true;
}

Matrixi Graph::get_matrix()
{
	return _matrix;
}

std::list<Edge> Graph::get_edges()
{
	return std::list<Edge>();
}

int Graph::vertex_count()
{
	return _matrix.rows();
}

int & Graph::operator()(int v1, int v2)
{
	return _matrix(v1, v2);
}
