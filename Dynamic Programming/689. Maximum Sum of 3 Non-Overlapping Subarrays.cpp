//https://www.youtube.com/watch?v=mXeT7-oZeQQ&ab_channel=Pepcoding
// This is basically extension of two non - overlapping maximum sum problem
class Solution {
public:
    int n,k;
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        n = nums.size();
        
        vector<int> dp1(n);
        vector<int> dp2(n);
        
        int sum = 0;
        for(int i=0;i<n;i++)//for dp1 
        {
            if(i<k)
            {
                sum+=nums[i];
                dp1[i] = sum;
            }
            else
            {
                sum+=nums[i]-nums[i-k];
                dp1[i] = max(dp1[i-1],sum);
            }
        }
        //for dp2 cnsiderring from last
        sum = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(n-i<=k)
            {
                sum+=nums[i];
                dp2[i] = sum;
            }
            else
            {
                sum+=nums[i]-nums[i+k];
                dp2[i] = max(dp2[i+1],sum);
            }
        }
        
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i]  = pre[i-1]+nums[i];
            //cout<<pre[i]<<" ";
        }
        // for(int i=0;i<n;i++)//for dp1 
        //     cout<<dp1[i]<<"  "<<dp2[n-i-1]<<endl;
        // cout<<endl;
        sum=0;
        int res = 0;
        int j=k;
        int ls=0,rs=0;
        int l,m,r;
        l=m=r=-1;
        vector<int> ans(3);
        for(int i=k;i<n-(2*k)+1;i++)
        {            
            sum = dp1[i-1]+dp2[i+k] + (pre[i+k-1] - pre[i-1]);
            if(sum>res)
            {
                res = sum;
                ls = dp1[i-1];
                rs = dp2[i+k];
                m = i;
            }
        }
         // cout<<res<<endl;
         // cout<<ls<<" "<<rs<<endl;
        for(int i = k-1;i<m;i++)
        {
            if(pre[i] - (i-k<0?0:pre[i-k])==ls)
            {
                l = i-k+1;
                break;
            }
        }
        for(int i = m+(2*k)-1;i<n;i++)
        {
            if(pre[i] - pre[i-k]==rs)
            {
                r = i-k+1;
                break;
            }
        }
        
        ans = {l,m,r};
        return ans;
    }
};
