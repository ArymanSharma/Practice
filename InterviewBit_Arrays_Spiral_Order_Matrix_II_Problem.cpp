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

PrintMatrix(vector<vector<int>> &A)
{
	for(auto a : A)
	{
		for(auto b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}
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

vector<vector<int> > generateMatrix(int A)
{
    int num = 1;
    vector<vector<int>> matrix(A, vector<int>(A, 0));

    for(int i = 0 ; i < (A+1)/2 ; ++i)
    {
        int row = i, col = i;
        while(col < A and matrix[row][col] == 0)
        {
            matrix[row][col] = num;
            num++;col++;
        }
        col--;
        row++;
        while(row < A and matrix[row][col] == 0)
        {
            matrix[row][col] = num;
            num++;row++;
        }
        row--;
        col--;
        while(col >= 0 and matrix[row][col] == 0)
        {
            matrix[row][col] = num;
            num++;col--;
        }
        col++;
        row--;
        while(row >= 0 and matrix[row][col] == 0)
        {
            matrix[row][col] = num;
            num++;row--;
        }
    }
    return matrix;
}

int main()
{
	vector<vector<int>> ans = generateMatrix(5);
	PrintMatrix(ans);
}
