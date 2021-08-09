// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
/*logic:
 - starting with a index 0 and moving ahead by tracing max elemrnt and cal sum using max_ele
 - repeating recursively
*/
class Solution {
public:
    int solve(vector<int>& arr, int index,int k,int* memo,int n )
    {    
        if(index>=n)
            return 0;
        
        if(memo[index]!=-1)
            return memo[index];
        
        int max_ele = INT_MIN;
        int sum = INT_MIN;
        for(int i = index;i<min(n,index+k);i++)
        {
            max_ele = max(max_ele,arr[i]);
            int curr_sum = max_ele*(i-index+1);
            sum = max(sum,curr_sum + solve(arr,i+1,k,memo,n));
        }
        return memo[index] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n = arr.size();
        int memo[n+1];
        memset(memo,-1,sizeof(memo));
        return solve(arr,0,k,memo,n);
    }
};
