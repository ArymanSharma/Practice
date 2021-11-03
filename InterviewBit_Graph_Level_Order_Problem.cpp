#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
   	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

Print(vector<vector<int>> A)
{
	for(int i = 0 ; i < A.size() ; ++i)
	{
		for(int j = 0 ; j < A[i].size() ; ++j)
		{
			cout << A[i][j] << " ";
		}
		cout << endl ;
	}
}

vector<vector<int> > levelOrder(TreeNode* A)
{
    vector<vector<int>> ans;
    vector<int> temp;
    queue<TreeNode*> q;

    q.push(A);

    while(!q.empty())
    {
        temp.clear();
        int size = q.size();
        for(int i = 0 ; i < size ; ++i)
        {
            TreeNode* f = q.front();
            temp.push_back(f->val);
            if(f->left != NULL)
            {
                q.push(f->left);
            }
            if(f->right != NULL)
            {
                q.push(f->right);
            }
            q.pop();
        }
        ans.push_back(temp);
    }
    return ans;
}


int main()
{
	TreeNode* t = new TreeNode(3);
	t->left = new TreeNode(9);
	t->right = new TreeNode(20);
	t->right->left = new TreeNode(15);
	t->right->right  = new TreeNode(7);
	
	
	vector<vector<int>> A = levelOrder(t);
	Print(A);
}
