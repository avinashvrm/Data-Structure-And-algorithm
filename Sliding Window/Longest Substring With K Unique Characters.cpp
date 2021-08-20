   //Longest Substring With K Unique Characters | Variable Size Sliding Window
   string s="aabacbebebedddbbb";
   
    unordered_map<char,int>mp;
    int i=0;int j=0,k=3,maxer=0;
    
    while(j<s.size())
    {
        mp[s[j]]++;
        if(mp.size()<k)
        {
            j++;
        }
        else if(mp.size()==k)
        {
            maxer=max(maxer,j-i+1);
            j++;
        }
        else
        {
           int in=i;
           while(mp[s[in]]!=0)
           {
               mp[s[i]]--;
               i++;
           }
           mp.erase(mp.find(s[in]));
            
            j++;
        }
        
    }
    cout<<maxer;
}
