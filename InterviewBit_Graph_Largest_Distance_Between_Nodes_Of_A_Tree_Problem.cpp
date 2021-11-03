#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;

void Print(vector<vector<int>> &g)
{
	for(int i = 0 ; i < g.size() ; ++i)
	{
		cout << i << "--> ";
		for(int j = 0 ; j < g[i].size() ; ++j)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}

/*pair<int,int> MaxDist(int source, vector<vector<int>> &g, vector<bool> &visited, int parent)
{
    visited[source] = true;
	if((g[source].size() == 1 or g[source].size() == 0) and parent != -1)
    {
		return {1,1};
    }
    pair<int,int> max_pair = {INT_MIN,INT_MIN};
    set<int, greater<int>> s;
    for(int i = 0 ; i < g[source].size() ; ++i)
    {
        if(!visited[g[source][i]])
        {
        	pair<int,int> temp = MaxDist(g[source][i], g, visited, source);
            max_pair.first = max(max_pair.first, temp.first);
            max_pair.second = max(max_pair.second, temp.second);
            s.insert(temp.second);
		}
    }
    int sum = 0, size = s.size();
    auto it = s.begin();
    if(it != s.end())
    {
        sum += s[0];
    }
    if(size > 1)
    {
        sum += s[1];
    }
    if(sum > max_pair.first)
    {
        max_pair.first = sum;
    }
    if(max_path == {INT_MIN,INT_MIN})
    {
    	return 1;
	}
    return max_path+1;
}*/

pair<int, int> MaxDist(int root, vector<vector<int>> &g, vector<bool> &visited, int parent)
{
	visited[root] = true;
	if(g[root].size() == 0) //for root node
	{
		return {0, 0};
	}
	if(g[root].size() == 1 and parent != -1)
	{
		return {0, 1};
	}
	
	int max_until = 0;
	priority_queue<int> pq;
	for(int i = 0 ; i < g[root].size() ; ++i)
	{
		if(visited[g[root][i]] == false)
		{
			pair<int, int> p = MaxDist(g[root][i], g, visited, root);
			max_until = max(max_until, p.first);
			pq.push(p.second);
		}
	}
	
	int max1 = 0, max2 = 0;
	if(!pq.empty())
	{
		max1 = pq.top();
		pq.pop();
	}
	if(!pq.empty())
	{
		max2 = pq.top();
	}
	max_until = max(max_until, max1 + max2);
	return {max_until, max1+1};
}

int solve(vector<int> &A)
{
    if(A.size() == 1)
    {
    	return 0;
	}
	vector<vector<int>> g(A.size());
    vector<bool> visited(A.size());
    int root;
    for(int i = 0 ; i < A.size() ; ++i)
    {
        if(A[i] != -1)
        {
        	g[i].push_back(A[i]);
        	g[A[i]].push_back(i);
		}
		else
		{
			root = i;
		}
    }
    Print(g);
    return MaxDist(root, g, visited, -1).first;
}

int main()
{
	vector<int> A= {-1, 0, 0, 0, 3};
	vector<int> B= {-1, 0};
	cout << solve(B) << endl;
}
