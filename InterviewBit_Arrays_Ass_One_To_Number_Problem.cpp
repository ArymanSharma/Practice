#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int> &A)
{
    int carry = 1;
    vector<int> ans;
	for(int i = A.size()-1 ; i >= 0 ; i--)
    {
    	int ele = A[i] + carry;
    	if(ele == 10)
    	{
    		carry = 1;
    		ans.push_back(0);
		}
		else
		{
			carry = 0;
			ans.push_back(ele);
		}
	}
	if(carry)
	{
		ans.push_back(carry);
	}
	
	while(ans.back() == 0)
	{
		ans.pop_back();
	}
	reverse(ans.begin(), ans.end());
	
	return ans;
}

int main()
{
	vector<int> A = {9,9,9};
	vector<int> ans = plusOne(A);
	for(auto a : ans)
	{
		cout << a << " ";
	}
	cout << endl;
}
