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

