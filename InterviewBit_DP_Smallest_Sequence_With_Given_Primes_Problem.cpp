#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solve(int A, int B, int C, int D)
{
    vector<int> ans = {A,B,C};
    sort(ans.begin(), ans.end());
    int p1 = 1, p2 = 1, p3 = 1;
    A = ans[0], B = ans[1], C = ans[2];
    ans.clear();

    while(D--)
    {
        int a = p1*A, b = p2*A, c = p3*A;
        if(a < b and a < c)
        {
            p1 = a;
            ans.push_back(p1);
        }
        else if(b < a and b < c)
        {
            p2 = b;
            ans.push_back(p2);
        }
        else if(c < a and c < b)
        {
            p3 = c;
            ans.push_back(p3);
        }
    }
    return ans;
}

int main()
{
	vector<int> ans = solve(2,3,5,5);
	for(auto a : ans)
	{
		cout << a << " ";
	}
	cout << endl;
}
