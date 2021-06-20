
class Solution {
public:
     int threeSumClosest(vector<int>& num, int target) 
     {
        int n = num.size();
        sort(num.begin(), num.end());//sorting to use two pointer approach
        int mn_diff = INT_MAX;
        int ans = 0;
        
        for (int i = 0; i < n-2; i++)
        {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1]))//a can't be same as previous value 
            {
                
                int lo = i+1, hi = n-1;
                while (lo < hi) 
                {
                    int sum = num[lo] + num[hi] + num[i];
                    if (abs(target-sum) <= mn_diff )
                    {
                        
                        mn_diff = abs(target-sum);
                        ans = num[i] + num[lo] + num[hi];
                        //cout<<mn_diff<<" -> "<<num[i]<<" "<<num[lo]<<" "<<num[hi]<<endl;
                        
                    } 
                    
                    if (sum > target)
                        hi--;
                    else
                        lo++;
               }
            }
        }
        return ans;
    }
};
