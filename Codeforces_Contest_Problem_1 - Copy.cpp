#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k = 3;
    cin >> t;
    vector<vector<int>> ans;
    
    while(t--)
	{
        
		vector<pair<int, int>> votes(k);
        for(int i = 0 ; i < k ; i++)
		{
            cin >> votes[i].first;
            votes[i].second = i;
        }
        
        vector<int> temp(k);
        sort(votes.begin(), votes.end());
        for(int i = 2 ; i >= 0 ; i--)
        {
        	if(i == 2)
        	{
        		if(votes[i].first == votes[i-1].first)
        		{
        			temp[votes[i].second] = 1;
				}
				else
				{
					temp[votes[i].second] = 0;
				}
			}
			else
			{
				if(votes[i].first == votes[2].first)
				{
					temp[votes[i].second] = 1;
				}
				else
				{
					temp[votes[i].second] = votes[2].first - votes[i].first + 1;
				}
			}
		}
		ans.push_back(temp);
    }
    for(auto a : ans)
    {
    	cout << a[0] << " " << a[1] << " " << a[2] << endl;
	}
}
