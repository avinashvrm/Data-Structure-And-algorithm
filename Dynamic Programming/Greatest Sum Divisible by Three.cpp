/*
Given an array nums of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.
Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
Example 3:

Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
 

Constraints:

1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4
*/
class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		int mod0=0; // %3==0
		int mod1=0;// %3==1
		int mod2=0; // %3==2
		for(int i=0;i<nums.size();i++)
        {
			int Oldmod0=mod0;
			int Oldmod1=mod1;
			int Oldmod2=mod2;
            
			if((Oldmod0+nums[i])%3==0){
				mod0=max(mod0,Oldmod0+nums[i]);
			}
			else if((Oldmod0+nums[i])%3==1){
				mod1=max(mod1,Oldmod0+nums[i]);
			}
			else if((Oldmod0+nums[i])%3==2){
				mod2=max(mod2,Oldmod0+nums[i]);
			}


            if((Oldmod1+nums[i])%3==0){
				mod0=max(mod0,Oldmod1+nums[i]);
			}
			else if((Oldmod1+nums[i])%3==1){
				mod1=max(mod1,Oldmod1+nums[i]);
			}
			else if((Oldmod1+nums[i])%3==2){
				mod2=max(mod2,Oldmod1+nums[i]);
			}



			if((Oldmod2+nums[i])%3==0){
				mod0=max(mod0,Oldmod2+nums[i]);
			}
			else if((Oldmod2+nums[i])%3==1){
				mod1=max(mod1,Oldmod2+nums[i]);
			}
			else if((Oldmod2+nums[i])%3==2){
				mod2=max(mod2,Oldmod2+nums[i]);
			}
		}

		return mod0;
	}
};
