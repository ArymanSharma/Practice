#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lis(const vector<int> &A)
{
    if(A.size() == 0)
    {
        return 0;
    }
    vector<int> lisTillIndex(A.size(),1);
    int ans = 1;
    for(int i = 0 ; i < A.size() ; ++i)
    {
        int j = i-1, max_val = 0;
        while(j >= 0)
        {
            if(A[j] < A[i])
            {
                max_val = max(max_val, lisTillIndex[j]);
            }
            j--;
        }
        lisTillIndex[i] += max_val;
        ans = max(ans,lisTillIndex[i]);
    }
    return ans;
}

int main()
{
	vector<int> A = {84, 80, 27};
	cout << lis(A) << endl;
}
