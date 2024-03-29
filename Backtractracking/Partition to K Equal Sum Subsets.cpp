class Solution {
public:
//currsum is the current sum of subset we are working on and targetsum is the sum we require for each subset
    
	bool dfs(vector<int>& nums,vector<int>visited,int idx,int k,int currsum,int targetsum)
    {
        if(k==1) 
            return true;                                               //if k==1 then all the subsets have been found so return true.
        if(currsum==targetsum) 
            return dfs(nums,visited,0,k-1,0,targetsum);  //this condition means you have found one suset so start from begining for another subset.
        for(int i=idx ; i<nums.size() ; i++)
        {
            if(!visited[i])                                                //if the index is not visited then it can be used in the current subset or bucket.
            {
                visited[i]=true;                                                          //set this index as used to avoid redundancy.
                if(dfs(nums,visited,i+1,k,currsum+nums[i],targetsum)) return true;        //explore the choices
                visited[i]=false;                                                         //for backtrack.
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int>visited(nums.size(),false);
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum%k!=0) 
            return false;
        
        int targetsum=sum/k;
        return dfs(nums,visited,0,k,0,targetsum);
        
    }
};
// instead of visited vector using bitmasking of checking occurences
class Solution {
public:
    bool go(vector<int>&nums,int i,int n,long mask, int k, int csum, int tsum)
    {
        
     
    // Base Condition if There are k-1 groups with sum tsum then last group will also have sum tsum    
        if(k==1)
            return true;
        
   //if group found iterate from start for k-1 groups     
        if(csum == tsum)
        {
           
            return go(nums,0,n,mask,k-1,0,tsum);
        }
		else if(csum>tsum)                              //backtrack if current sum > target sum
            return false;
        
	// try all possible combination which are not visited 
        for(int j=i;j<n;j++)
        {
            if(!(mask&(1<<j)))                          //check if visited
            {
                if(go(nums,j,n,mask|(1<<j),k,csum+nums[j],tsum))        // next combination with j position marked as visited
                    return true;
              
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tsum=0;
        int n = nums.size();
        for(int i:nums) tsum+=i;
        if(tsum%k!=0)
            return false;
        tsum/=k;
      
        return go(nums,0,n, 0,k,0,tsum);
    }
};
