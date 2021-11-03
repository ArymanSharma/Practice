#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Print(vector<int> &A)
{
	for(auto a : A)
	{
		cout << a << " ";
	}
	cout << endl;
}
//-----------------------------------------------------------------------------------------------Editorial-------------------------------------------------------------------------------------------------
vector<int> getRowEditorial(int A)
{
    
    vector<int>temp;// to store the resultant row
    int n  = 1;
    for( int col = 0; col <= A ; col++)
	{// nth row will have n + 1 elements in pascal triangle
        temp.push_back(n);
        n = n * (A - col)/(col + 1);// mathematics
    }
    return temp; // resultant vector returned.
    // space complexity O(A).
    // time complexity O(A).
}


//-----------------------------------------------------------------------------------------------MySolution-------------------------------------------------------------------------------------------------

vector<int> getRow(int A)
{
    vector<int> prev_row, cur_row;
    prev_row.push_back(1);
    cur_row = prev_row;
    for(int i = 0 ; i < A+1 ; i++)
    {
        cur_row.clear();
        for(int j = 0 ; j < i+1 ; ++j)
        {
            int ele = 0;
            if(j < 0 or j >= prev_row.size())
            {
                ele += 0;
            }
            else
            {
                ele += prev_row[j];
            }
            if(j-1 < 0 or j-1 >= prev_row.size())
            {
                ele += 0;
            }
            else
            {
                ele += prev_row[j-1];
            }
            cur_row.push_back(ele);
        }
        prev_row = cur_row;
    }
    return prev_row;
}

int main()
{
	vector<int> ans = getRow(5);
	Print(ans);
}
