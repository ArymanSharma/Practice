#include <bits/stdc++.h>
#include <cmath>

using namespace std;


void traverseComponent(vector<vector<int>> &g, vector<bool> &vis, int root, int &weight)
{
	vis[root] = true;
	weight++;
	for(auto node : g[root])
	{
		if(!vis[node])
		{
			traverseComponent(g, vis, node, weight);
		}
	}
}

vector<int> solve(vector<vector<int>> &g)
{
	int n = g.size(), weight;
	vector<bool> vis(n, false);
	vector<int> weights;
	for(int i = 0 ; i < n ; i++)
	{
		weight = 0;
		if(!vis[i])
		{
			traverseComponent(g, vis, i, weight);
			weights.push_back(weight);
		}
	}
	return weights;
}

int main()
{
	vector<vector<int>> g(10);
	g[0] = {1, 2};
	g[1] = {0, 3};
	g[2] = {0, 4};
	g[3] = {1};
	g[4] = {2};
	g[5] = {};
	g[6] = {7};
	g[7] = {6};
	g[8] = {};
	g[9] = {};
	
	vector<int> ans = solve(g);
	int sum = 0;
	for(auto a : ans)
	{
		sum += ceil(sqrt(a));
	}
	cout << sum << endl;
	return 0;
}
