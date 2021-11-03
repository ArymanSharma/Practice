#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> arr, int target) // Iterative Method
{
	int start = 0, mid, end = arr.size()-1;
	while(start <= end)
	{
		mid = start + (end-start)/2;
		
		if(arr[mid] == target)
		{
			return mid;
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
	return -1;
}

int main()
{
	vector<int> arr = {1,3,4,54,55,345,444,3333};
	cout << BinarySearch(arr, 444) << endl;
}
