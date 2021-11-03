#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string reverse(string &s)
{
	stack<int> st;
	for(int i = 0 ; i < s.size() ; ++i)
	{
		if(s[i] == '(')
		{
			st.push(i);
		}
		else if(s[i] == ')')
		{
			reverse(s.begin() + st.top() + 1, s.begin() + i);
			st.pop();
		}
	}
	
	string ans = "";
	for(auto a : s)
	{
		if(a != '(' and a != ')')
		{
			ans += a;
		}
	}
	return ans;
}

int main()
{
	string s = "(skeeg(for)skeeg)";
	cout << reverse(s) << endl;
}
