#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Right Solution Approach - First we apply the normal Binary Serch and when we find the element we will iterate to left and right till we find the same number; TC = log(n)

vector<int> searchRange(const vector<int> &A, int B) 
{
    int start = 0, end = A.size()-1;
    vector<int> ans;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(A[mid] == B)
        {
            int s = mid, e = mid;
            while(s-1 >= 0 and A[s-1] == B)
            {
                s--;
            }
            ans.push_back(s);
            while(e+1 < A.size() and A[e+1] == B)
            {
                e++;
            }
            ans.push_back(e);
            return ans;
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
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

int main()
{
	vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	vector<int> ans = searchRange(arr, 10);
	cout << "[" << ans[0] << "," << ans[1] << "]" << endl;
}
