#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList(ListNode* head)
{
	ListNode* temp = head;
	while(temp)
	{
		cout << temp->val <<" ";
		temp = temp->next;
	}
	cout << endl;
}

ListNode* Solve(ListNode* A)
{
	if(!A)
	{
		return A;
	}
	
	ListNode *first = nullptr, *second = nullptr, *third = nullptr, *head = nullptr, *end = nullptr, *hundreds = nullptr, *hundreds_end = nullptr;
	first = A;
	second = first->next;
	if(second)
	{
		third = second->next;
	}
	
	while(first or second or third)
	{
		if(first and second and third and first->val == second->val and third->val == 100)
		{
			first->val = 100;
			second->val = second->val + second->val/10;
			
			if(second->val == 100)
			{
				if(!hundreds)
				{
					hundreds = first;
					hundreds_end = third;
				}
				else
				{
					hundreds_end->next = first;
					hundreds_end = third;
				}
			}
			else
			{
				if(!head)
				{
					head = second;
					end = second;
					end->next = nullptr;
				}
				else
				{
					end->next = second;
					end = second;
					end->next = nullptr;
				}
				
				if(!hundreds)
				{
					hundreds = first;
					hundreds_end = first;
					hundreds_end->next = third;
					hundreds_end = third;
				}
				else
				{
					hundreds_end->next = first;
					hundreds_end = first;
					hundreds_end->next = third;
					hundreds_end = third;
				}
			}
		}
		else
		{
			if(first)
			{
				if(first->val == 100)
				{
					if(!hundreds)
					{
						hundreds = first;
						hundreds_end = first;
					}
					else
					{
						hundreds_end->next = first;
						hundreds_end = first;
					}
				}
				else
				{
					if(!head)
					{
						head = first;
						end = first;
					}
					else
					{
						end->next = first;
						end = first;
					}
				}
			}
			
			if(second)
			{
				if(second->val == 100)
				{
					if(!hundreds)
					{
						hundreds = second;
						hundreds_end = second;
					}
					else
					{
						hundreds_end->next = second;
						hundreds_end = second;
					}
				}
				else
				{
					if(!head)
					{
						head = second;
						end = second;
					}
					else
					{
						end->next = second;
						end = second;
					}
				}
			}
			
			if(third)
			{
				if(third->val == 100)
				{
					if(!hundreds)
					{
						hundreds = third;
						hundreds_end = third;
					}
					else
					{
						hundreds_end->next = third;
						hundreds_end = third;
					}
				}
				else
				{
					if(!head)
					{
						head = third;
						end = third;
					}
					else
					{
						end->next = third;
						end = third;
					}
				}
			}
		}
		
		if(third)
		{
			first = third->next;
		}
		else
		{
			first = nullptr;
		}
		
		if(first)
		{
			second = first->next;
		}
		else
		{
			second = nullptr;
		}
		
		if(second)
		{
			third = second->next;
		}
		else
		{
			third = nullptr;
		}
	}
	
	if(end)
	{
		end->next = hundreds;
		if(hundreds_end)
		{
			hundreds_end->next = nullptr;
		}
	}
	else
	{
		head = hundreds;
		if(hundreds_end)
		{
			hundreds_end->next = nullptr;
		}
	}
	return head;
}

int main()
{
	vector<int> A;
	vector<ListNode*> r;
	int n, N;
	cin >> N;
	
	while(N--)
	{
		A.clear();
		cin >> n;
		
		string ans, num = "";
		cin.ignore();
		std::getline(std::cin, ans);
		for(int i = 0 ; i < ans.size() ; ++i)
		{
			if(ans[i] == ' ' and num != "")
			{
				A.push_back(stoi(num));
				num = "";
			}
			else
			{
				num += ans[i];
			}
		}
		if(num != "")
		{
			A.push_back(stoi(num));
		}
		
		ListNode* head = nullptr, *temp = nullptr;
		for(int i = 0 ; i < n ; ++i)
		{
			if(!head)
			{
				temp = new ListNode(A[i]);
				head = temp;
			}
			else
			{
				temp->next = new ListNode(A[i]);
				temp = temp->next;
			}
		}
		r.push_back(head);
		//PrintList(head);
	}
	
	for(auto head : r)
	{
		ListNode* res = Solve(head);
		PrintList(res);
	}
		
	return 0;
}
