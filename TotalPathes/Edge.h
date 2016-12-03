#pragma once
#ifndef _EDGE_H_

#include <iostream>

struct Edge
{
	int x1;
	int x2;

	Edge(){}

	Edge(int v1, int v2)
		: x1(v1), x2(v2)
	{
	}

	friend std::istream& operator >> (std::istream& is, Edge& e)
	{
		is >> e.x1 >> e.x2;
		return is;
	}

	bool operator==(const Edge& e)
	{
		return (e.x1 == x1 && e.x2 == x2);
	}
};

#endif // !_EDGE_H_

