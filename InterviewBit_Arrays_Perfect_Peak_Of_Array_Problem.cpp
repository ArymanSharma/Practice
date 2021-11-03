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

int perfectPeak(vector<int> &A)
{
    int n = A.size();
	int max_num = A[0], min_num = A[n-1];
    vector<int> max_vec(n,0), min_vec(n,0);
    for(int i = 1 ; i < n ; ++i)
    {
        if(A[i] > max_num)
        {
        	max_vec[i] = 1;
        	max_num = A[i];
		}
    }
    Print(max_vec);
    
    for(int i = n-2 ; i >= 0 ; i--)
    {
        if(A[i] < min_num)
        {
        	min_vec[i] = 1;
        	min_num = A[i];
		}
    }
    Print(min_vec);
    
    for(int i = 1 ; i < n-1 ; ++i)
    {
        if(min_vec[i] == 1 and max_vec[i] == 1)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
	vector<int> A = {5, 1, 4, 3, 6, 8, 10, 7, 9}, B = {5,1,4,4};
	cout << perfectPeak(B) << endl;
}
