long log ans = LLONG_MIN;
long long sum = 0;
long long MaxSum(vector<vector<int>> &tree, int root, vector<int> &A, vector<int> &visited)
{
    if(tree[root].size() == 1)
    {
        return A[root];
    }
    long long c_sum = 0;
    for(int i = 0 ; i < tree[root].size() ; ++i)
    {
        long long temp = MaxSum(tree, tree[root][i]), A);
        c_sum = c_sum + temp;
        ans = max(ans, (sum*(sum-temp))%(1e9+7));
    }
    return c_sum + A[root];
}

int deleteEdge(vector<int> &A, vector<vector<int> > &B)
{
    long long sum = 0;
    visited<bool> &visited(A.size(), false);
    for(auto a : A)
    {
        sum += a;
    }
    for(int i = 0 ; i < B.size() ; ++i)
    {
    	
	}
    long long lol = MaxSum(tree, 0, A);
    return sum
}
