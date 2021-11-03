#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

Print(vector<int> &A)
{
	for(auto a : A)
	{
		cout << a << " ";
	}
	cout << endl;
}

vector<int> solve(vector<int> &A, int B) // TC = O(N)
{
    int n=A.size();
    vector<int> mp(n+1);
    for(int i=0;i<n;i++)
    {
        mp[A[i]]=i;
    }
    Print(mp);
    for(int i=0;i<n && B>0;i++)
    {
        if(A[i]!=(n-i)) 
        {
            mp[A[i]]=mp[n-i];
            swap(A[mp[n-i]],A[i]);
            B--;
        }
    }
    return A;
}

int main()
{
	vector<int> A = {8, 2, 7, 4, 5, 6, 3, 1};
	vector<int> ans = solve(A,2);
	Print(ans);
}
