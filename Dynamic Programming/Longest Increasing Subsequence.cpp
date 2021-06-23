class Solution {
public:
    int findLISLength(vector<int>& arr, int n)
    {
        // create an empty ordered set `S`. The i'th element in `S` is defined as the
        // smallest integer that ends an increasing sequence of length `i`
        set<int> S;
        // process every element one by one
        for (int i = 0; i < n; i++)
        {
            // ignore the current element if it is already present in the set
            if (S.find(arr[i]) != S.end())
                continue;
            // insert the current element into the set
            auto ret = S.insert(arr[i]);
            // get an iterator to the inserted item
            auto it = ret.first;
            // if the element is not inserted at the end, then delete the next
            // greater element from the set
            if (++it != S.end()) {
                S.erase(it);
            }
        }
        // length of LIS is the total number of elements in the set
        return S.size();
    }
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        if(n==1)
            return 1;
        
        return findLISLength(nums,n);
    }
};

//LCS Approch---First copy thr vector in another than remove all the repeating numbers than apply LCS

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        
        vector<int> vec(nums);
        sort(vec.begin(), vec.end());
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );//REMOVES ALL THE DUPLICATE NUMBERS
        int m = vec.size();
        int dp[n+1][m+1];
        for(int i = 0; i<=n; i++)
        {
            for(int j = 0; j<=m; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] =0;
                else if(nums[i-1]==vec[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
        
    }
};

/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h> 
using namespace std; 
	
/* lis() returns the length of the longest increasing 
subsequence in arr[] of size n */
int lis( int arr[], int n ) 
{ 
	int lis[n]; 

	lis[0] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 

	// Return maximum value in lis[] 
	return *max_element(lis, lis+n); 
} 
	
/* Driver program to test above function */
int main() 
{ 
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Length of lis is %d\n", lis( arr, n ) ); 
	return 0; 
}

