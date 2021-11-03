#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

bool dfs(int source, bool *visited, int dest, vector<vector<int>> &g)
{
	visited[source] = true;
	if(source == dest)
    {
        return true;
    }
    bool isPathPresent = false;
	for(auto neighbour : g[source])
	{
		if(!visited[neighbour])
		{
			isPathPresent = (isPathPresent or dfs(neighbour, visited, dest, g));
		}
	}
	return isPathPresent;
}

int solve(int A, vector<vector<int> > &B)
{
    vector<vector<int>> g(A, vector<int>(0));
    for(int i = 0 ; i < B.size() ; ++i)
    {
        g[B[i][0]-1].push_back(B[i][1]-1);
    }
    bool *visited = new bool[A]{false};

    return (int)dfs(0, visited , A-1 , g);
}

int main()
{
	vector<vector<int>> a = {{1, 4},{2, 1},{4, 3},{4, 5},{2, 3},{2, 4},{1, 5},{5, 3},{2, 5},{5, 1},{4, 2},{3, 1},{5, 4},{3, 4},{1, 3},{4, 1},{3, 5},{3, 2},{5, 2}};
	int A = 5;
	cout << solve(A, a) << endl;
}
