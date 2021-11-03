#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

Print(vector<int> &A)
{
	for(auto a : A)
	{
		cout << a << " ";
	}
	cout << endl ;
}

Print2D(vector<vector<int>> &A)
{
	for(auto a : A)
	{
		for(auto b : a)
		{
			cout << b << " ";
		}
		cout << endl ;
	}
}

vector<vector<int> > threeSum(vector<int> &A)
{
    vector<vector<int>> ans;
    int size = A.size();
    for(int i = 0 ; i < size-2 ; ++i)
    {
        unordered_set<long long int> uset;
        uset.insert((long long int)A[i+1]);
        for(int j = i+2 ; j < A.size() ; ++j)
        {
            long long int sum_2 = ((long long int)A[i] + (long long int)A[j])*(-1);
			if(uset.find(sum_2) != uset.end())
            {
				vector<int> temp = {A[i], A[j], (int)sum_2};
                sort(temp.begin(), temp.end());
                if(std::find(ans.begin(), ans.end(), temp) == ans.end())
                {
                	ans.push_back(temp);
				}
                temp.clear();
            }
            uset.insert(A[j]);
        }
        uset.clear();
    }
    return ans;
}

int main()
{
	vector<int> A = {2147483647, -2147483648, -2147483648, 0, 1};
	vector<vector<int>> C = threeSum(A);
	Print2D(C);
}
