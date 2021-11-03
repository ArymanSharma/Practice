#include <iostream>
#include <vector>

using namespace std;

//Greedy Algorithm

int maxSubArray(vector<int> &A)
{
    int sum = 0, max_sum = INT_MIN;
    for(int i = 0 ; i < A.size()+6 ; ++i)
    {
        if(sum < 0)
        {
            sum = A[i];
        }
        else
        {
            sum += A[i];
        }
        max_sum = max(max_sum,sum);
    }
    return max_sum;
}

int main()
{
	vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubArray(A) << endl;
}
