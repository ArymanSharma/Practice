#include <iostream>
#include <vector>

using namespace std;

vector<int> LPS(string pat, int n)
{
	int len = 0, i = 1;
	vector<int> lps(n,0);
	while(i < n)
	{
		if(pat[len] == pat[i])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i] = len;
				i++;
			}
		}
	}
	return lps;
}

vector<int> KMP(string s, string p)
{
	vector<int> lps = LPS(p, p.size()), startingindex;
	for(auto a : lps)
	{
		cout << a << " ";
	}
	cout << endl;
	int i = 0, j = 0;
	while(i < s.size())
	{
		if (s[i] == p[j]) {
            j++;
            i++;
        }
  
        if (j == p.size()) {
            startingindex.push_back(i-j);
            j = lps[j - 1];
        }
  
        else if (i < s.size() && p[j] != s[i])
		{
            if (j != 0)
            {
            	j = lps[j - 1];
			}
            else
            {
            	i = i + 1;
			}
        }
	}
	return startingindex;
}

int main()
{
	string s = "ababcdeababab";
	vector<int> A = KMP(s, "abab");
	cout << "startig index's of pattern found are : ";
	for(auto a : A)
	{
		cout << a << " ";
	}
	cout << endl;
	string t = "AACECAAAA$AAAACECAA";
	vector<int> B = LPS(t, t.size());
	for(auto a : B)
	{
		cout << a << " ";
	}
}
