#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int to, weight;
};

int BFSForBinaryWeightedGraph(int n, vector<vector<pair<int,int>>> &g, int source, int dest)/// Better TC than Dijiktras Algorithm TC = 
{
	vector<int> distance(n,INT_MAX);
	deque<pair<int,int>> dq;
		
	distance[source]=0;
	dq.push_front({0,source});
		
	while(!dq.empty())
	{
		auto f = dq.front();
		int node = f.second;
		int distTillNow = f.first;
		dq.pop_front(); //Pop
			
		for(auto nbr_pair : g[node])
		{
			int nbr = nbr_pair.second;
			int current_edge = nbr_pair.first;
			int current_distance = distTillNow + current_edge;
			if(current_distance < distance[nbr])
			{
				distance[nbr] = current_distance;
				if(current_edge == 0)
				{
					dq.push_front({current_distance,nbr});
				}
				else
				{
					dq.push_back({current_distance,nbr});
				}
			}
		}
	}
	
	for (auto dist : distance)
	{
		cout << dist << " ";
	}
	cout << endl;
	return distance[dest];
}

void addEdge(int u, int v, int wt, vector<vector<pair<int,int>>>& edges)
{
   edges[u].push_back({wt, v});
   edges[v].push_back({wt, u});
}

int main()
{
	vector<vector<pair<int,int>>> edges(9);
	addEdge(0, 1, 0, edges);
    addEdge(0, 7, 1, edges);
    addEdge(1, 7, 1, edges);
    addEdge(1, 2, 1, edges);
    addEdge(2, 3, 0, edges);
    addEdge(2, 5, 0, edges);
    addEdge(2, 8, 1, edges);
    addEdge(3, 4, 1, edges);
    addEdge(3, 5, 1, edges);
    addEdge(4, 5, 1, edges);
    addEdge(5, 6, 1, edges);
    addEdge(6, 7, 1, edges);
    addEdge(7, 8, 1, edges);
    BFSForBinaryWeightedGraph(9, edges, 0, 8);
}
