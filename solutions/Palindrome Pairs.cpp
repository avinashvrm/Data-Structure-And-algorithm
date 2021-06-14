//Given a list of unique words, 
//return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.

class Solution {
public:
                                                                                    //  Input: words = ["abcd","dcba","lls","s","sssll"]
                                                                                    //  Output: [[0,1],[1,0],[3,2],[2,4]]
                                                                                    //  Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>> res;
        unordered_map<string, int> map;

        for (int i = 0; i < words.size(); ++i) 
        {
            map.insert({words[i], i});
        }

        // Empty String case
        if (map.find("")!=map.end()) 
        {
            int blankIdx = map[""];
            for (int i = 0; i < words.size(); ++i) 
            {
                if (i != blankIdx && isPalindrome(words[i])) 
                {
                    res.push_back({blankIdx,i});
                    res.push_back({i,blankIdx});
                }
            }
        }

        // Reflection case
        for (int i = 0; i < words.size(); ++i) 
        {
            string reversed = words[i];
            reverse(reversed.begin(),reversed.end());
            if (map.find(reversed)!=map.end()) 
            {
                int reversedIdx = map[reversed];

                if (reversedIdx != i) 
                {
                    res.push_back({i,reversedIdx});
                }
            }
        }


        // Tricky case
        for (int i = 0; i < words.size(); ++i) 
        {
            string cur = words[i];
            for (int cut = 1; cut < cur.size(); ++cut) 
            {
                string left = cur.substr(0, cut);
                string right = cur.substr(cut);
                
                if (isPalindrome(left)) 
                {
                    string reversedRight = right;
                    reverse(reversedRight.begin(),reversedRight.end());
                    if (map.find(reversedRight)!=map.end()) 
                    {
                        res.push_back({map[reversedRight],i});
                    }
                }
                if (isPalindrome(right)) 
                {
                    string reversedLeft = left;
                    reverse(reversedLeft.begin(),reversedLeft.end());
                    if (map.find(reversedLeft)!=map.end()) 
                    {
                        res.push_back({i,map[reversedLeft]});
                    }
                }
            }
        }
        return res;
    }

    private: 
        bool isPalindrome(string &word) 
        {
            int i = 0, j = word.size() - 1;
            while(i < j) 
            {
                if (word[i++] != word[j--]) 
                    return false;
            }
            return true;
        }
};
