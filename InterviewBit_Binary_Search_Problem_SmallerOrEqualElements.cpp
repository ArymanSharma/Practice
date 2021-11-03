#include <iostream>
#include <vector>

using namespace std;

int ElementsLessThanOrEqualToTarget(vector<int> arr, int target) // Iterative Method
{
	int start = 0, mid, end = arr.size()-1;
	while(start <= end)
	{
		mid = start + (end-start)/2;
		
		if(arr[mid] == target)
		{
			while(arr[mid+1] == target)
			{
				mid++;
			}
			return mid+1;
		}
		else if(arr[mid] > target)
		{
			end = mid-1;
		}
		else if(arr[mid] < target)
		{
			start = mid+1;
		}
	}
	return end+1;
}

int main()
{
	vector<int> arr = {1, 2, 5, 5};
	cout << ElementsLessThanOrEqualToTarget(arr, 4) << endl;
}
