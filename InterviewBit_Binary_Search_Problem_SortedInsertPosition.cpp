#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Right Solution Approach - We apply the normal Binary Search; TC = log(n)

int searchInsert(const vector<int> &A, int B) 
{
    int start = 0, end = A.size()-1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(A[mid] == B)
        {
            return mid;
        }
        else if(A[mid] > B)
        {
            end = mid-1;
        }
        else if(A[mid] < B)
        {
            start = mid+1;
        }
    }

    if(end == -1)
    {
    	if(A[start] > B)
    	{
    		return start;
		}
		return start+1;
	}
	else if(start == A.size())
	{
		if(A[end] < B)
    	{
    		return end+1;
		}
		return end;
	}
	else
	{
		if(A[start] < B)
		{
			return start+1;
		}
		else if (A[start] > B and A[end] < B)
		{
			return start;
		}
		else
		{
			return end;
		}
	}
}

int main()
{
	vector<int> arr = {3, 4, 18, 19, 20, 27, 28, 31, 36, 42, 44, 71, 72, 75, 82, 86, 88, 97, 100, 103, 105, 107, 110, 116, 118, 119, 121, 122, 140, 141, 142, 155, 157, 166, 176, 184, 190, 199, 201, 210, 212, 220, 225, 234, 235, 236, 238, 244, 259, 265, 266, 280, 283, 285, 293, 299, 309, 312, 317, 335, 341, 352, 354, 360, 365, 368, 370, 379, 386, 391, 400, 405, 410, 414, 416, 428, 433, 437, 438, 445, 453, 457, 458, 472, 476, 480, 485, 489, 491, 493, 501, 502, 505, 510, 511, 520, 526, 535, 557, 574, 593, 595, 604, 605, 612, 629, 632, 633, 634, 642, 647, 653, 654, 656, 658, 686, 689, 690, 691, 709, 716, 717, 737, 738, 746, 759, 765, 775, 778, 783, 786, 787, 791, 797, 801, 806, 815, 820, 822, 823, 832, 839, 841, 847, 859, 873, 877, 880, 886, 904, 909, 911, 917, 919, 937, 946, 948, 951, 961, 971, 979, 980, 986, 993};
	cout << arr[148] << " " << arr[149] << endl; 
	int ans = searchInsert(arr, 902);
	cout << ans << endl;
}
