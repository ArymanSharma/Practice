#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

Print(vector<int> &A)
{
	for(auto a : A)
	{
		cout << a << " ";
	}
	cout << endl ;
}

int threeSumClosest(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    Print(A);
    long long min_diff = LLONG_MAX;
    for(int i = 0 ; i < A.size() ; ++i)
    {
        int j = i+1, k = A.size()-1;
        while(j < k)
        {
            long long sum = A[i]+A[j]+A[k];
			if(abs(sum - B) < abs(min_diff))
            {
                min_diff = A[i]+A[j]+A[k] - B;
                if(min_diff == 0)
                {
                    return B;
                }
                j++;
            }
            else if(abs(sum - B) == abs(min_diff))
            {
            	j++;
			}
            else
            {
                k--;
            }
        }
    }
    return (int)B+min_diff;
}

int main()
{
	vector<int> A = {-5, 1, -7, -1, -10, 7, -4, 1, -8, -1};
	int B = 4;
	cout << threeSumClosest(A,B) << endl;
}
