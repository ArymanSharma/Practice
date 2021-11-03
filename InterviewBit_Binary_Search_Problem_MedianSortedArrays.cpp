#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &A, vector<int> &B)
{
    int m = A.size(), n = B.size();
    
    if(m < n) return findMedianSortedArrays(B, A);
    
    int l = 0, h = 2*n;
    
    while(l <= h)
    {
        int mid = l + (h-l)/2;
        int mid1 = m+n - mid;
        
        double L1 = (mid1 == 0) ? INT_MIN : A[(mid1-1)/2];
        double R1 = (mid1 == m*2) ? INT_MAX : A[(mid1)/2];
        double L2 = (mid == 0) ? INT_MIN : B[(mid-1)/2];
        double R2 = (mid == n*2) ? INT_MAX : B[(mid)/2];
        
        if (L1 > R2) l = mid + 1;		
        else if (L2 > R1) h = mid - 1;	
        else return (max(L1,L2) + min(R1, R2)) / 2;	
    }
}

int main()
{
	vector<int> A = {1,4,5,7,10};
	vector<int> B = {8,12};
	cout << findMedianSortedArrays(A,B) << endl;
}
