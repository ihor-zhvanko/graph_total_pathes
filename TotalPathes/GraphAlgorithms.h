#pragma once
#ifndef _GRAPH_ALGORITHMS_H_
#define _GRAPH_ALGORITHMS_H_

#include "Graph.h"

class GraphAlgorithms 
{
	static std::list<Edge>& path;

	static int total;
public:
	static int total_pathes(Graph& g, int cur, int from, int to) 
	{
		if (cur == to)
		{
			path.pop_back();
			return 1;
		}


	}
private:
	virtual void fake() = 0;

	
};

#endif // !_GRAPH_ALGORITHMS_H_
