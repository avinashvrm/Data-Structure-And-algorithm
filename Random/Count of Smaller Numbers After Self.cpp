class Solution {
public:
    void merge(vector<pair<int,int>> &nums,int l,int mid,int r,vector<int> &res)
    {
        int i = l,j = mid+1,k = 0;
        
        vector<pair<int,int>> temp(r-l+1);
        
        while(i<=mid && j <= r)
        {
            if(nums[i].first <= nums[j].first)
            {
                temp[k] = nums[j];
                k++;
                j++;
            }
            else
            {
                temp[k] = nums[i];
                res[nums[i].second] += r - j + 1;
                i++;
                k++;
            }
        }
        while(i<=mid)
            temp[k++] = nums[i++];
        
        while(j<=r)
            temp[k++] = nums[j++];
        
        for(int i=l;i<=r;i++)
            nums[i] = temp[i-l];
    }
    void mergesort(vector<pair<int,int>> &nums,int i,int j,vector<int> &res)
    {
        if(i<j)
        {
            int mid = (i+j)/2;
            mergesort(nums,i,mid,res);
            mergesort(nums,mid+1,j,res);
            merge(nums,i,mid,j,res);
        }
    }
    vector<int> countSmaller(vector<int>& num)
    {
        int n = num.size();
        if(n==1)
            return {0};
        vector<pair<int,int>> nums;
        for(int i=0;i<num.size();i++)
        {
            nums.push_back({num[i],i});
        }
        
        vector<int> res(n);
        mergesort(nums,0,nums.size()-1,res);
        return res;
    }
};
