#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Print(vector<vector<int>> &A)
{
	for(int i = 0 ; i < A.size() ; ++i)
	{
		cout << i << " : " ;
		for(int j = 0 ; j < A[i].size() ; ++j)
		{
			cout << A[i][j] << " ";
		}
		cout << endl ;
	}
}

/*int result;
int num;
void dfs(int v, int count, vector<int> &A, vector<bool> vis, vector<vector<int>> &arr){
    vis[v]=1;
    
    for(int child: arr[v]){
        if(vis[child]==0){
            if(A[child-1]) dfs(child, count+1, A, vis, arr);
            else dfs(child, count, A, vis, arr);
        }
    }
    if(arr[v].size()==1 && count<=num) result++;
}

int solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n=A.size();
    result=0;
    num=C;
    vector<bool> vis(n+1, false);
    vector<vector<int>> arr(n+1);
    
    for(int i=0; i<n-1; i++){
        arr[B[i][0]].push_back(B[i][1]);
        arr[B[i][1]].push_back(B[i][0]);
    }

    if(A[0]==1) dfs(1, 1, A, vis, arr);
    else dfs(1, 0, A, vis, arr);
    return result;
}*/

void dfs(int node, vector<int> &A, vector<vector<int>> &g, int C, int GN, int &ans, vector<bool> &visited)
{
	visited[node] = true;
	if(GN > C)
	{
		return;
	}
	if(g[node].size() == 1 and GN <= C)
	{
		ans++;
	}
	
	for(int i = 0 ; i < g[node].size() ; ++i)
	{
		if(visited[g[node][i]] == false)
		{
			if(A[g[node][i]-1] == 1)
			{
				dfs(g[node][i], A, g, C, GN+1, ans, visited);
			}
			else
			{
				dfs(g[node][i], A, g, C, GN, ans, visited);
			}
		}
	}
}

int solve(vector<int> &A, vector<vector<int> > &B, int C)
{
    int n = A.size(), ans = 0;
    vector<bool> visited(n+1, false);
    vector<vector<int>> g(n+1);
    
    for(int i = 0 ; i < n - 1 ; i++)
	{
        g[B[i][0]].push_back(B[i][1]);
        g[B[i][1]].push_back(B[i][0]);
    }

    if(A[0]==1)
	{
		dfs(1, A, g, C, 1, ans, visited);
	}
    else
	{
		dfs(1, A, g, C, 0, ans, visited);
	}
    return ans;
}

int main()
{
	vector<int> A = {1, 1, 1, 0, 1, 0, 1, 0};
	vector<vector<int> > B = {{8, 2},{6, 3},{5, 2},{3, 1},{4, 2},{7, 2},{2, 1}};
	int C = 2;
	int result = solve(A, B, C);
	cout<< result << endl;
}
