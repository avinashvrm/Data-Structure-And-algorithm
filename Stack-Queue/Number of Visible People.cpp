/*A person can see another person to their right in the queue if everybody in between is shorter than both of them.
More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Input: heights = [10,6,8,5,11,9]
Output:          [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them. */
//Using stack(Monotonic), iterating from backward and cal if there are ele in st which are hreater than the top of stack (means they can see this(st.top) ele.
//since person after thtat ele cannot see that ele so we pop that element 
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i] > st.top())
            {
                st.pop();
                ans[i]++;
            }
            if(!st.empty())
                ans[i]++;
            st.push(arr[i]);
        }
        return ans;
    }
};
