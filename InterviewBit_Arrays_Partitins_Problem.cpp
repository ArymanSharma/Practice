#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Print(vector<long long int> &A)
{
	for(auto a : A)
	{
		cout << a << " ";
	}
	cout << endl;
}

//--------------------------------------------------------------------------------Efficient Solution---------------------------------------------------------------------------------------------------------

int solve(int A, vector<int> &B)
{
    if(B.size() < 3)
    {
        return 0;
    }

    vector<long long int> suffix, prefix;
    long long int sum = 0;
    int ways = 0;
    for(int i = 0 ; i < B.size() ; ++i)
    {
        sum += (long long int)B[i];
        suffix.push_back(sum);
    }
    Print(suffix);
    
    if(suffix.back()%3 != 0)
    {
        return 0;
    }

    sum = 0;
    for(int i = B.size()-1 ; i >= 0 ; i--)
    {
        sum += (long long int)B[i];
        prefix.push_back(sum);
    }
    reverse(prefix.begin(), prefix.end());
    Print(prefix);

    for(int i = 0 ; i < suffix.size() ; ++i)
    {
        if(suffix[i] == sum/3)
        {
            int j = i+2;
            while(j < prefix.size())
            {
                if(prefix[j] == sum/3)
                {
                    ways++;
                }
                j++;
            }
        }
    }
    return ways;
}


int main()
{
	vector<int> A = {1, 2, 3, 0, 3};
	cout << solve(5, A) << endl;
	//Print(ans);
}
