//https://leetcode.com/problems/remove-k-digits/
class Solution {
public:
//                                                                                                 Input: num = "1432219", k = 3
//                                                                                                 Output: "1219"
//                                                                                                 Input: num = "10200", k = 1
//                                                                                                 Output: "200"
    string removeKdigits(string nums, int k) 
    {
        int n = nums.size();
        if(n==1 && k>=1)
            return "0";
        string st="";//treating string as stack
        for(int i=0;i<n;i++)
        {
            while(st.size() && st.back() > nums[i] && k)
            {
                st.pop_back();
                k--;
            }  
            st.push_back(nums[i]);
        }
        while(st.size() && k--)
            st.pop_back();//112--11--if k>0 peeche se hata skte
        while(st[0]=='0')//handling zeros as we have pushed zeros also
        {
            st.erase(st.begin());
        }
        return st.size()>0?st : "0";
    }
};
