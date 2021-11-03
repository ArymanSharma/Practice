#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

PrintVector(vector<int> &A)
{
	for(auto x : A)
	{
		cout << x << " ";
	}
	cout << endl;
}

int sqrt(int A)
{
    int start = INT_MIN, end = A, temp = A;
    while(start == INT_MIN)
    {
        temp = temp/2;
        if(temp*temp > A)
        {
            end = temp;
        }
        else if (temp*temp == A)
        {
            return temp;
        }
        else if(temp* temp < A)
        {
            start = temp;
        }
    }

    while(end - start > 1)
    {
        int mid = start + (end-start)/2;
        if(mid*mid == A)
        {
            return mid;
        }
        else if(mid*mid > A)
        {
            end = mid-1;
        }
        else if(mid*mid < A)
        {
            start = mid+1;
        }
    }

    return floor((start+end)/2);
}

int main()
{
	cout << sqrt(2) << endl;
}
