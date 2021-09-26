/*
Given an array of  positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative
(as close to zero as possible). 
Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.

Constraints:

 1 <= n <= 100
Sum of all the elements will not exceed 10,000.

Example:

A = [15, 10, 6]
ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )

A = [14, 10, 4]
ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)

Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there are not minimum

https://stackoverflow.com/questions/58056287/dynamic-programming-flip-minimum-signs-of-array-elements-to-get-minimum-sum-of
*/
int Solution::solve(const vector <int>&A) 
{
   int sum=0, n=A.size();
   if(n<2) 
      return 0;
   for(int i=0;i<n;i++)
       sum+=A[i];

   sum=sum/2;
   pair<bool,long long> dp[n+1][sum+1];
   
   
   // intialization
   long long int ans=INT_MAX;
   for(int i=0;i<=n;i++)
      dp[i][0]={true,0};

   for(int i=1;i<=sum;i++)
       dp[0][i]={false,INT_MAX};
       // if no of elements is equal to zero and we need positive sum
       // so it is not possible to get that using any number of elements 
       // since no of elements are 0 and infinite no of flips can also
       // not produce the sum because the no of elements are zero itself 
       
    // knapsack approach
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=sum;j++)
       {
           if(j>=A[i-1]) // if current sum is possible by considering the current element 
           {
              dp[i][j].first=dp[i-1][j].first||dp[i-1][j-A[i-1]].first;

              if(dp[i][j].first==false)
                 dp[i][j].second = INT_MAX;
               else                                                                         // had to minimise the number of flips therefore storing minimum 
                  dp[i][j].second = min(dp[i-1][j].second,1+dp[i-1][j-A[i-1]].second);
         
           }// if not possible then store the previous information
           else dp[i][j]=dp[i-1][j];
       
       }
   
   }
int f=0;
for(int i=sum;i>=1;i--)// iterating from backside to get the minimum sum possible
// since we want to divide them into subsets as close to totalsum/2 to minimise 
//difference
{
    for(int j=1;j<=n;j++)
    {
        if(dp[j][i].first==true)// if sum is possible
        {
            ans=min(ans,dp[j][i].second); f=1;// for number of flips
        }
    }
    if(f==1) break;// found subset with closest sum as possible to totalsum/2 therefore
    // we are breaking from here
    
}

return ans;
}
