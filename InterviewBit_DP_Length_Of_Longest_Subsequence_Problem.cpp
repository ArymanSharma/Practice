#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

Print(vector<int> &A)
{
	for(auto a : A)
	{
		cout << a << " ";
	}
	cout << endl;
}

int longestSubsequenceLength(const vector<int> &A)
{
    int i = 0;
    vector<int> increasing(A.size(),1);
    for(int i = 1 ; i < A.size() ; ++i)
    {
        int j = i-1, max_val = 0;
        while(j >= 0)
        {
            if(A[j] < A[i])
            {
                max_val = max(max_val, increasing[j]);
            }
            j--;
        }
        increasing[i] += max_val;
    }
    Print(increasing);
    
    vector<int> decreasing(A.size(),1);
    for(int i = A.size()-2 ; i >= 0 ; --i)
    {
        int j = i+1, max_val = 0;
        while(j < A.size())
        {
            if(A[j] < A[i])
            {
                max_val = max(max_val, decreasing[j]);
            }
            j++;
        }
        decreasing[i] += max_val;
    }
    Print(decreasing);
    
    int ans = 0;
	for(int i = 0 ; i < increasing.size() ; ++i)
    {
    	ans = max(ans,increasing[i]+decreasing[i]-1);
	}
    return ans;
}

int main()
{
	vector<int> A = {1, 3, 5, 6, 4, 8, 4, 3, 2, 1};
	cout << longestSubsequenceLength(A) << endl;
}
