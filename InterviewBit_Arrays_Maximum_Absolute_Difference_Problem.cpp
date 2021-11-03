#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Print(vector<int> &A)
{
	for(auto a : A)
	{
		cout << a << " ";
	}
	cout << endl;
}

int calFunc(int i, int j, vector<int> &A)
{
	return abs(A[i] - A[j]) + abs(i-j);
}

//-----------------------------------------------------------------------------Brute-Force Solution--------------------------------------------------------------------------------------------------------

int maxArrBrute(vector<int> &A) // TC = O(N^2)
{
    int ans = INT_MIN;
	for(int i = 0 ; i < A.size() ; ++i)
    {
    	for(int j = i+1 ; j < A.size() ; ++j)
		{
			ans = max(ans, calFunc(i,j,A));
		}
	}
    return ans;
}

//--------------------------------------------------------------------------------Efficient Solution---------------------------------------------------------------------------------------------------------

int maxArr(vector<int> &A)
{
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX, ans = INT_MIN;
    for(int i = 0 ; i < A.size() ; ++i)
    {
        max1 = max(max1, A[i] - i);
        max2 = max(max2, A[i] + i);
        min1 = min(min1, A[i] - i);
        min2 = min(min2, A[i] + i);
    }

    ans = max(ans, max1 - min1);
    ans = max(ans, max2 - min2);
    return ans;
}


int main()
{
	vector<int> A = {1, 3, -1};
	cout << maxArr(A) << endl;
	//Print(ans);
}
