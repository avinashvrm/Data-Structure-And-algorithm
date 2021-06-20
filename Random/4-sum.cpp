class Solution {
public:
 vector<vector<int>> fourSum(vector<int>& nums, int target) {
       // T = O(n^3) & S = O(1)
        vector<vector<int>> res;
        
        int n = nums.size();  
        sort(nums.begin(), nums.end());  
        for(int i = 0; i < n; i++) 
        {    // i pointer from 0 to n
            for(int j = i+1; j < n; j++) 
            {  // j pointer from i+1 to n
                int rem = target - nums[i] - nums[j]; // remaining value to find
                int front = j+1;   // left pointer  just after j
                int back = n-1;    // right pointer at last index
                
                while(front < back) 
                { // loop till front and back pointer donot cross over
                    int two_sum = nums[front] + nums[back]; 
                    if (rem == two_sum)
                    {
                        res.push_back({nums[i],nums[j],nums[front],nums[back]});
                        while(front < back && nums[front] == nums[front+1]) 
                            front++;
                        while(front < back && nums[back] == nums[back-1]) 
                            back--;
                        front++;
                        back--;
                    }
                    else if(two_sum < rem) 
                        front++;  
                               
                    else  
                        back--; 
                }
                // processing the duplicates of number 2
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
             // processing the duplicates of number 1
                while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return res;
    }
};
