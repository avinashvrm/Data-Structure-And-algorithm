class Solution {
public:
    int n,mod=1e9+7;
    vector<int> v;
    int find(int i, string &s)
    {
        if(i==n) return 1;
        if(i>n)  return 0;
        if(v[i]!=-1) return v[i];
        if(s[i]=='0') return 0;
        
        int c=0;
        /*
        if current value is 1, there are following ways
        
        1.  Take single digit 1 and move to next index i+1 
        2.  Take two digits here, (11,12--19 all are valide) and move to i+2 
        3.  If next digit is * , then * -> [1,9]. So, iterate 1 to 9 and take everytime 2 digit
            ie, if * ->1 then it will be 11
                if * ->2 then it will be 12
                .
                .
                if * ->9 then it will be 19
             
        */
        if(s[i]=='1')
        {
            //taking single digit and move to i+1
            c+=find(i+1,s); c%=mod;
            
            //if next is * , 9 possibilities, take two digit and move to i+2
            if(i+1<n && s[i+1]=='*')
            {
                for(int k=1;k<=9;k++)
                {
                    c+=find(i+2,s);
                    c%=mod;
                }
            }
            
            //else next may be any on from [0,9], so take two digit and move to i+2
            else 
                c+=find(i+2,s);
            
            c%=mod;
        }
        /*
        if current value is 2, there are following ways
        
        1.  Take single digit 2 and move to next index i+1 
        2.  Take two digits here, (21,22--26 all are valide) and move to i+2 , we can't take 27,28 etc
        3.  If next digit is * , then * -> [1,9]. So, iterate 1 to 6 only and take everytime 2 digit
            ie, if * ->1 then it will be 21
                if * ->2 then it will be 22
                .
                .
                if * ->6 then it will be 26
                
             We cant take 27 because it will be invalid   
             
        */
        //if s[i]==2
        else if(s[i]=='2')
        {
            //taking single digit and move to i+1
            c+=find(i+1,s);
            c%=mod;
            
            //if next is *, we can only take 1 to 6 because [21,22,23,24,25,26] is only valid
            //so, iterate 6 times and assume taking two digit "2*" and move to i+2 
            if(i+1<n && s[i+1]=='*')
            {
                for(int k=1;k<=6;k++)
                {
                    c+=find(i+2,s); c%=mod;
                } 
            }
            
            //else if next digit is less than 7 then we can take this
            //it will make [21,22,23,24,25,26]
            else if(i+1<n && s[i+1]<='6') 
                c+=find(i+2,s);
            
            c%=mod;
        }
        
        //if s[i] is *
        else if(s[i]=='*')
        {
            //taking * as 1, 
            //it will be same case s[i]=1, which is upper case
            c+=find(i+1,s); 
            c%=mod;
            
            if(i+1<n && s[i+1]=='*')
            {
                for(int k=1;k<=9;k++)
                {
                    c+=find(i+2,s);
                    c%=mod;
                }
            }
            else 
                c+=find(i+2,s); c%=mod;        
            //taking * as 2,
            //it will be same case s[i]=2, which is upper case
            c+=find(i+1,s);
            c%=mod;
            if(i+1<n && s[i+1]=='*')
            {
                for(int k=1;k<=6;k++)
                {
                    c+=find(i+2,s); c%=mod;
                } 
            }
            else if(i+1<n && s[i+1]<='6') 
                c+=find(i+2,s); c%=mod;
            
            //taking * as >2
            //you can only take single digit, we have taken 1 and 2, so start from 3 to 9
            for(int k=3;k<=9;k++)
            {
                c+=find(i+1,s); c%=mod;
            }
        }
        
        //else we have digit greater than 2
        //so we can take single digit only and move to i+1
        else
        {
           c+=find(i+1,s); c%=mod;
        }
        
        //take mod every time and memoize it and return result
        return v[i]=c%mod;
    }
    int numDecodings(string s) {
        
        //finding size of given string
        n=s.size();
        
        //use for memoization
        v=vector<int> (n+1,-1);
        
        //let's find ways from 0th index
        return find(0,s);
    }
};
