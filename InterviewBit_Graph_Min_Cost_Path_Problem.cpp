#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char pos[4]={'R','D','L','U'};   // Positions that can be visited
int dx[4]={0,1,0,-1};   // where to go in x direction for ith position
int dy[4]={1,0,-1,0};   // where to go in y direction for ith position
bool check(int i,int j,int A,int B){
    return (i>=0 && j>=0 && i<A && j<B);
}

int solve(int A, int B, vector<string> &C)
{
    int dis[A+1][B+1];  // to store the distances of node (i,j) from (0,0)
    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++){
            dis[i][j]=INT_MAX;   // initially every node is at infinite distance from (0,0)
        }
    }
    deque <pair<int,int> > q; // for 0-1 BFS
    q.push_front({0,0});
    dis[0][0]=0;  // initialisation
    while(!q.empty()){ // BFS starts here
        int i=q.front().first,j=q.front().second;
        q.pop_front();
        for(int k=0;k<4;k++){
            int x = dx[k]+i,y=dy[k]+j;
            if(check(x,y,A,B)){
                int d; // for storing whether the node x,y can be visited with 0 cost or 1 cost
                if(C[i][j]==pos[k]) d=0;
                else d=1;
                if(dis[x][y]>dis[i][j]+d){ // if x,y could be relaxed
                    dis[x][y]=dis[i][j]+d;
                    if(d==0) q.push_front({x,y});  // if at same level
                    else q.push_back({x,y});  // if one level ahead
                }
            }
        }
    }
    return dis[A-1][B-1];
}


int main()
{
	vector<string> A = {"RRRRRRRRRR"};
	cout << solve(1,10,A) << endl;
}
