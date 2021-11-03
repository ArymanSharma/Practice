#include <iostream>
#include <vector>
#include <string>

using namespace std;

int BellmanFord(int source, int dest, vector<vector<pair<int,int>>> &g)
{
	int vertices = g.size();
	vector<int> distance(vertices, INT_MAX);
	
	distance[source] = 0;
	
	for(int i = 1 ; i < vertices ; i++) // Traversing each edge for |V|-1 times
	{
		for(int j = 0 ; j < vertices ; j++) // Traversing each Edge present in the graph
		{
			for(int k = 0 ; k < g[j].size() ; ++k)
			{
				auto node = g[j][k];
				if(distance[j] != INT_MAX and distance[j] + node.second < distance[node.first])
				{
					distance[node.first] = distance[j] + node.second;
				}
			}
		}
	}
	
	for(int j = 0 ; j < vertices ; j++) // Traversing each Edge present in the graph to check if there is any negative cycle in the graph.
	{
		for(int k = 0 ; k < g[j].size() ; ++k)
		{
			auto node = g[j][k];
			if(distance[j] != INT_MAX and distance[j] + node.second < distance[node.first])
			{
				cout << "There is a negative cycle in the graph" << endl ;
				return -1;
			}
		}
	}
	
	for(int i = 0 ; i < distance.size() ; ++i)
	{
		cout << "Node " << i << " : " << distance[i] << endl;
	}
	
	return distance[dest];
}

int main()
{
	vector<vector<pair<int,int>>> g(4);
	g[0].push_back({1,4});
	g[0].push_back({3,5});
	//g[1].push_back({3,5});
	g[2].push_back({1,-10});
	g[3].push_back({2,3});
	cout << BellmanFord(0,2,g) << endl;
}
