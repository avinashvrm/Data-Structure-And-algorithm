class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); //sorting to use two pointer approach
        
        // a will be fixed and we for each a we can search for band c -- a+b+c=0,b+c = -a
        for (int i = 0; i < (int)(num.size())-2; i++)
        {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1]))//a can't be same as previous value 
            {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];//b+c = -a
                
                while (lo < hi) 
                {
                    if (num[lo] + num[hi] == sum)
                    {
                        
                        res.push_back({num[i],num[lo],num[hi]});
                        
                        while (lo < hi && num[lo] == num[lo+1])//avoiding all the dupli
                            lo++;
                        while (lo < hi && num[hi] == num[hi-1]) 
                            hi--;
                        
                        lo++; hi--;
                    } 
                    
                    else if (num[lo] + num[hi] < sum)
                        lo++;
                    else
                        hi--;
               }
            }
        }
        return res;
    }
};
