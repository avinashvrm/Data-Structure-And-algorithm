//https://www.techiedelight.com/increasing-subsequence-with-maximum-sum/

//arr = [ 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 ] = 8 + 12 + 14 = 34
//memoize below code
#include <iostream>
#include <climits>
using namespace std;
 
// Function to find the maximum sum of an increasing subsequence
int MSIS(int arr[], int i, int n, int prev, int sum)
{
    // Base case: nothing is remaining
    if (i == n) {
        return sum;
    }
 
    // case 1: exclude the current element and process the
    // remaining elements
    int excl = MSIS(arr, i + 1, n, prev, sum);
 
    // case 2: include the current element if it is greater
    // than the previous element
    int incl = sum;
    if (arr[i] > prev) {
        incl = MSIS(arr, i + 1, n, arr[i], sum + arr[i]);
    }
 
    // return the maximum of the above two choices
    return max(incl, excl);
}
 
int main()
{
    int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "The maximum sum of increasing subsequence is " <<
            MSIS(arr, 0, n, INT_MIN, 0);
 
    return 0;
}

//BOTTM UP


#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
 
// Iterative function to find the maximum sum of an increasing subsequence
int MSIS(int arr[], int n)
{
    // array to store subproblem solutions. `sum[i]` stores the maximum
    // sum of the increasing subsequence that ends with `arr[i]`
    int sum[n] = { 0 };
 
    // base case
    sum[0] = arr[0];
 
    // start from the second array element
    for (int i = 1; i < n; i++)
    {
        // do for each element in subarray `arr[0…i-1]`
        for (int j = 0; j < i; j++)
        {
            // find increasing subsequence with the maximum sum that ends with
            // `arr[j]`, where `arr[j]` is less than the current element `arr[i]`
 
            if (sum[i] < sum[j] && arr[i] > arr[j]) {
                sum[i] = sum[j];
            }
        }
 
        // include `arr[i]` in MSIS
        sum[i] += arr[i];
    }
 
    int msis = INT_MIN;
    for (int x: sum) {
        msis = max(msis, x);
    }
 
    return msis;
}
 
int main()
{
    int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "The maximum sum of increasing subsequence is " <<
            MSIS(arr, n);
 
    return 0;
