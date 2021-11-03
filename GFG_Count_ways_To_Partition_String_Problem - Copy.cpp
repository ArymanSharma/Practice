#include <bits/stdc++.h>
using namespace std;
 
// Function to find count of ways to partition
// the string such that each partition
// contains exactly two 0s.
int totalWays(int n, string str)
{
 
    // Stores indices of 0s in
    // the given string.
    vector<int> IdxOf0s;
 
    // Store the count of ways to partition
    // the string such that each partition
    // contains exactly two 0s.
    int cntWays = 1;
 
    // Iterate over each characters
    // of the given string
    for (int i = 0; i < n; i++) {
 
        // If current character is '0'
        if (str[i] == '0') {
 
            // Insert index
            IdxOf0s.push_back(i);
        }
    }
 
    // Stores total count of 0s in str
    int M = IdxOf0s.size();
    if (M == 0 or M % 2)
	{
        return 0;
    }
 
    // Traverse the array, IdxOf0s[]
    for (int i = 2; i < M; i += 2)
	{
        // Update cntWays
        cntWays = cntWays * (IdxOf0s[i] - IdxOf0s[i - 1]);
    }
 
    return cntWays;
}
 
// Driver Code
int main()
{
    string str = "00100100111110101010100";
    int n = str.length();
    cout << totalWays(n, str);
    return 0;
}
