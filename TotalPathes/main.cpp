#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "Graph.h"


class A
{
	
public:
	int a;

	~A()
	{
		std::cout << "Schluss" << std::endl;
	}
};

void foo()
{
	static A var;

	var.a = 12;
}

int total_pathes(Graph& g, std::list<Edge>& edge_buffer, int current, int to)
{
	if (current == to)
		return 1;

	auto total = 0;

	for (int i = 0; i < g.vertex_count(); ++i)
	{
		if (g(current, i) == 1)
		{
			Edge edge(current, i);
			auto is_used_edge = std::find(edge_buffer.begin(), edge_buffer.end(), edge);

			if (is_used_edge == edge_buffer.end()) //edge isn't used 
			{
				edge_buffer.push_back(edge);
				total += total_pathes(g, edge_buffer, i, to);
				edge_buffer.pop_back();
			}
		}
	}

	return total;
}

std::vector<int> v = {1, -1, -1, -1, -1, -1};

int acycling_graph_total_pathes(Graph& g, int to)
{
	if (v[to] != -1)
		return v[to];

	auto total_p = 0;

	for (int i = 0; i < g.vertex_count(); ++i)
	{
		if (g(i, to) == 1)
		{
			v[to] = acycling_graph_total_pathes(g, i);
			total_p += v[to];
		}
	}

	return total_p;
}


void main()
{
	foo();


	std::cout << std::endl;
	std::cin.get();
}

void main___()
{
	Graph g(6);
	if (!g.load_edge_list("Matrix.txt"))
		std::cout << "can't find file" << std::endl;
	std::cout << g._matrix << std::endl;

	/*auto start = clock();
	total_pathes(g, 0, 5);

	std::cout << (clock() - start) << std::endl;

	std::cout << total << std::endl;*/

	std::list<Edge> buffer;
	std::cout << total_pathes(g, buffer, 0, 5);;

	std::cin.get();

}