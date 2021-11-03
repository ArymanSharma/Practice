#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Right Solution Approach - First We find the row in which we hve to apply binary search in log(row) time, if there is no such row that MAY contain out target value we just return 0 and if there is, then 
// we will apply binary search to that row and will find out if the elemnt exist or not in log(columns) time so the overall TC = O(log(n)) + O(log(m)) = O(log(m*n));

int searchMatrix(vector<vector<int> > &A, int B) 
{
    int n = A.size(), m = A[0].size();
	int row_s = 0, row_e = n-1, row = -1;
    while(row_s <= row_e)
    {
        int mid = row_s + (row_e - row_s)/2;
        if(A[mid][0] == B or A[mid][m-1] == B)
        {
            return 1;
        }
        else if(A[mid][0] > B)
        {
            row_e = mid-1;
        }
        else if(A[mid][m-1] < B)
        {
            row_s = mid+1;
        }
        else
        {
            row = mid;
            break;
        }
    }
    
    if(row == -1)
    {
    	return 0;
	}
    
    int start = 0, end = m-1;
    while(start <= end)
    {
        int mid = start +(end-start)/2;
        if(A[row][mid] == B)
        {
            return 1;
        }
        else if(A[row][mid] > B)
        {
            end = mid-1;
        }
        else if(A[row][mid] < B)
        {
            start = mid+1;
        }
    }
    return 0;
}

int main()
{
	vector<vector<int>> A = {{3},{29},{36},{63},{67},{72},{74},{78},{85}};
	cout << searchMatrix(A,89) << endl;
}
