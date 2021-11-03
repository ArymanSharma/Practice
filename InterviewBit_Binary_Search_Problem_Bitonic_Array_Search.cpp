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

int BitonicSearch(vector<int> &arr, int target) // TC = O(log(n)), The problem if to find a element in an bitonic array in O(log(n)) time.
{
	int start = 0, end = arr.size()-1, mid, peak = -1;
	while(start <= end) // First We will find the peak of the bitonic array in log(n) time and then we will apply binary search on both the subrrays to find the element as they both will be monotonic.
	{
		mid = start + (end-start)/2;
		if(arr[mid+1] < arr[mid] and arr[mid] > arr[mid-1])
		{
			peak = mid;
			if(arr[peak] == target)
			{
				return peak;
			}
			break;
		}
		else if(arr[mid+1] > arr[mid] and arr[mid] > arr[mid-1])
		{
			start = mid+1;
		}
		else if(arr[mid+1] < arr[mid] and arr[mid] < arr[mid-1])
		{
			end = mid-1;
		}
	}
	
	start = 0, end = peak;
	while(start <= end) // Binary Search on the left part which is monotonically increasing
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
	
	start = peak, end = arr.size()-1;
	while(start <= end)  // Binary Search on the right part which is monotonically dereasing
	{
		mid = start + (end-start)/2;
		if(arr[mid] == target)
		{
			return mid;
		}
		else if(arr[mid] > target)
		{
			start = mid+1;
		}
		else if(arr[mid] < target)
		{
			end = mid-1;
		}
	}
	return -1;
}

int main()
{
	vector<int> arr = {10, 1, 4, 7, 10, 9 ,8, 6 ,5 ,3, 2};
	cout << BitonicSearch(arr,4) << endl;
}
