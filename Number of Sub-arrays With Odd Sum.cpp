class Solution {
public:
    /*int numOfSubarrays(vector<int>& arr) 
    {
        // arr: [1,3,1,5]   
        //intially-- iterater over the array -- odd/even? cnt++| 0 --- take a cummulative sum array sum[] 
        
        int mod = (int)1e9+7;
        int n = arr.size();
        vector<int> sum(n);
        int count = arr[0]%2==1 ?1:0;
      
        sum[0] = arr[0];
        for(int i=1 ;i<n; i++)
        {
            if(arr[i]%2==1)
                count++;
            
            sum[i] = sum[i-1] + arr[i];
            
            if(sum[i]%2==1)
                count++;
        }
        count%=mod;
        //iterate in my cummulative sum arr and cal and checking if subarray is odd or not if odd cnt++
        for(auto x:sum)
            cout<<x<<" ";
        for(int i =1; i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                count+=(sum[j]-sum[i-1])%2==1? 1:0;
            }
            count%=mod;
        }
        return count;
    }*/
    
    Above is O(N2)
    
    O(N) Solution:
    int numOfSubarrays(vector<int>& nums) 
    {
        int MOD=1000000007;
        int n=nums.size();
        if(n==0)return 0;
        
        long long pre_sum=0;
        int  odd_sum_count=0;
        int even_sum_count=0;
        int ans=0;
        // for single number subarray to be counted if it is odd 
        even_sum_count=1;
        
        for(int i=0;i<n;++i)
        {
            
            pre_sum+=nums[i];
            
            if(pre_sum % 2==0)
            {
                //if total sum upto this index from start is even 
                // we know that odd + odd =even we dont want even+even because we have to find odd sum subarrays
                //so we have to find the number of times the sum became odd previously and add it to answer
                ans+=odd_sum_count;
                even_sum_count++;
            }
            else
            {
               // here sum is odd
                // posibilities 1) odd+even or 2) even +odd
                //we only need case 2 for answer
                ans+=even_sum_count;
                odd_sum_count++;    
            }
            ans=ans%MOD;
        }
        return ans;
        
    }
};
