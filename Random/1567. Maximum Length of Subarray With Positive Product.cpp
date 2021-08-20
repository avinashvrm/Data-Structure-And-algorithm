/*  We can have only two possibilities in a subarray

    The count of negative number is even ,product will be +ve
    Count of negative numberis odd ,product will be -ve
  1.if we have even number of negative 
       multiply of even negative numbers are positive, so add both n and p and take max of res 
    
    2.if we have negative numbers and count of these are odd ,
       Lets say subarray -> {1,2,-1,2,3,1,-1,2,3,4,-1,2,3} , I am taking 3 negative numbers
       We know that odd-1 = even
       We have stored starting of negative number index in n_s
       and end of negative number index in n_e

       For this example n_s=2 , n_e = 10
       So here two cases, if we left a negative number of n_s index then 
       total count of negative numbers will be odd-1=even negative numbers 
       i.e subarray will be {2,3,1,-1,2,3,4,-1,2,3}

       Or if we left a negative number of n_e index than
       total count of negative numbers will be odd-1=even negative numbers 
       i.e subarray will be {1,2,-1,2,3,1,-1,2,3,4}

       So max length will be any one from these two only
       So we will take max length of these two
*/
class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        int n = nums.size();
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            int st_n = -1;
            int en_n = -1;
            int neg = 0;
            int pos = 0;
            int j = i;
            for(;j<n;j++)
            {
                if(nums[j]<0 && st_n==-1)
                    st_n = j;
                if(nums[j]<0)
                {
                    neg++;
                    en_n = j;
                }
                if(nums[j]>0)
                    pos++;
                if(nums[j]==0)
                    break;    
            }
            if(neg%2==0)
                mx=max(mx,neg+pos);
            else
            {
                mx = max(mx,en_n-i);
                mx = max(mx,j-st_n-1);
            }
            i=j;
        }
        return mx;
    }
};
