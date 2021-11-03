#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int SawbladeHeight(vector<int> A, int B) // TC exceeded
{
	int max_height = INT_MIN;
	for(auto x : A)
	{
		max_height = max(max_height, x);
	}
	
	int lowest = 0, highest = max_height;
	while(lowest <= highest)
	{
		int mid = lowest + (highest-lowest)/2;
		int wood = 0;
		for(auto x : A)
		{
			if(x > mid)
			{
				wood += (x-mid);
			}
		}
		if(wood == B)
		{
			return mid;
		}
		else if(wood > B)
		{
			lowest = mid+1;
		}
		else if(wood < B)
		{
			highest = mid-1;
		}
	}
	return (lowest+highest)/2;
}

int Solution(vector<int> &A, int B)
{
    sort(A.begin(),A.end());
    int n = A.size();
    if(B==0)
	{
		return A[n-1];
	}
    int j = 0;
    int H;
    int sum = 0;
    for(int i = n-1 ; i >= 0 ; i--){
        sum+=A[i];
        j++;
        H = A[i];
        if(sum - j*H<B)
		{
			continue;
		}
        else if(sum - j*H==B)
		{
			return H;
		}
        else
		{
			H=A[i+1]; //we go to previous index
        	sum-= A[i];
        	j--;
        	int hnew =  (sum - B)/j;
        	return hnew;
        }
    }
    //when we reach to zero 
    
    int hnew = (sum-B)/j;
    return hnew;
}

int main()
{
	vector<int> arr = {114, 55, 95, 131, 77, 111, 141};
	cout << Solution(arr, 95) << endl;
}
