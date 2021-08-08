/*
Q. Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Logic:
 - Do number ka xor maximum jabi hoga jb number a ke bits ur number b ke bits are all different.
 - so ek number lena h and check krna h, array m aesa koi element exist krta h jiske maximum bits iss number se diff ho
 - most significant bit se chalu krna h check krna
 - prefix search type hoga tho Trie use krna hoga, and most importantly binary representation hoga number ka tho 31 bit ka banega matlab 31 node

*/
class Solution {
public:
    struct Trie
    {
       Trie *child[2];
       int val = 0;
    };

    
    void insert(int x, Trie *root)
    {
    	
        Trie* curr = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (x >> i) & 1;//scan all the 31 position of x(element in array) and find out if its 1 or 0
            if(curr->child[bit] == NULL)//if there's isn't a node than construct one
                curr->child[bit] = new Trie();
            
            curr = curr->child[bit];
        }
        curr->val = x;
        
    }
    
    int findAns(int x, Trie *root)
    {
        Trie* curr = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (x >> i) & 1;
           
            if(curr->child[!bit]!=NULL)//opposite bit value chahiye apne ko, that's why checking if there exist a node of our desired val,if not settle for whats there(else statement)
                curr = curr->child[!bit];
           
            else if(curr->child[bit]!=NULL)
                curr=curr->child[bit];
        }
        return curr->val;  
    }
    
    int findMaximumXOR(vector<int>& nums) 
    {
        
        int ans = INT_MIN;
        
        Trie* root = new Trie();
        
        for(auto n:nums)
            insert(n, root);
        
        
        for(auto n:nums)
        {
            int res = findAns(n, root);
            ans = max(ans, n^res);
        }
        return ans;
    }
};
