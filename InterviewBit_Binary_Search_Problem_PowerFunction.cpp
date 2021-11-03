#include <iostream>
#include <vector>

using namespace std;

int rem(int A, int n, int d)
{
	int res = 1;
	for(int i = 0 ; i < n ; ++i)
	{
		res = res*A;
	}
	return res%d;
}

int main()
{
	cout << rem(7,8,3) << endl;
}
