class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
    //instead of checking for the sum, we can check for modulo, a%3 == 1  b%3==2 if this a and b combines it can be divisible by 3 Right!
    //if there are n number of mudulos of for bunch of element than number of modulo for k-n should be Equal to make them divisible by K
        
        unordered_map<int,int> mp;
        for(auto x : arr)
            mp[((x%k)+k)%k]++;// for -ve-- 2 can combine with 1 and -2 to make a pair that is divisible by 3(right)..-2 can be counted as 1 by adding k and then taking modulo
        
        if(mp[0]%2==1)
            return false;
        
        for(int i = 1;i<k;i++)
            if(mp[i]!=mp[k-i])
                return false;
        return true;
            
    }
};
