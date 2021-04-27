class Solution {
public:
    int findLISLength(vector<int>& arr, int n)
    {
        // create an empty ordered set `S`. The i'th element in `S` is defined as the
        // smallest integer that ends an increasing sequence of length `i`
        set<int> S;
        // process every element one by one
        for (int i = 0; i < n; i++)
        {
            // ignore the current element if it is already present in the set
            if (S.find(arr[i]) != S.end())
                continue;
            // insert the current element into the set
            auto ret = S.insert(arr[i]);
            // get an iterator to the inserted item
            auto it = ret.first;
            // if the element is not inserted at the end, then delete the next
            // greater element from the set
            if (++it != S.end()) {
                S.erase(it);
            }
        }
        // length of LIS is the total number of elements in the set
        return S.size();
    }
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        if(n==1)
            return 1;
        
        return findLISLength(nums,n);
    }
};
