/*https://medium.com/@andyoung/leetcode-1611-minimum-one-bit-operations-to-make-integers-zero-e04c65404bfb
POINTS FROM ABOVE POST:
 1-> 0 (apparently) which has 1 op
10->11->01->0 which has 3ops, in which the last op is the same problem above, so it is 2 + 1 ops
100 -> 101 -> 111 -> 110 -> 010 ->11->01->0 which has 7 ops, starting from 10, it is the same ops as the previous 3 ops, so it is 4 + 2 + 1 ops.
1000 -> 1001 -> 1011 -> 1010 -> 1110 -> 1111 -> 1101 -> 1100 -> 0100> 101 -> 111 -> 110 -> 010 ->11->01->0, which has 15 ops, and again, duplicated ops as above starting from 100, so it is 8 + 4 + 2 + 1 ops.
  
  Take a closer look at the above samples (make good observations), we can find out:
1. Operations to convert number 2^n to 0 tails with all operations to convert number 2^(n-1) to 0
2. Each shortest conversion chain is bidirectional, which is, 2^n => 0 has the same number of operations as 0 => 2^n
3. Intermediate numbers from 2^n to 2^(n-1) contain all numbers between 2^n and 2^(n+1), which demonstrates that any given non-negative integer can be converted to 0
4. With number 2^n, the number of operations is 2^(n+1)-1. Trust your gut feeling, you don’t need a rigorous mathematical proof because you are in a coding interview.

Now let’s check 1010. Please find this number in the operation chain above. Starting from 1000 to 1010, we need 3 operations,
so from 1010 to 0 takes 15–3 = 12 operations. You see? The number of operations to any given integer can be calculated from single bit integers as above, which is super nice because this is exactly what we are looking for: to disassemble a convoluted/complex problem into smaller and simpler ones.

Now we can write an equation for 1010:

minNumberOfOps(1000->0) = minNumberOfOps(1010->0) + minNumberOfOps(1000->1010)
Hmm, we know the answer to minNumberOfOps(1000->0), but what about minNumberOfOps(1000->1010)? 

The 3rd findings above now can help us — **he conversion chain is bidirectional**(100 ko 0 mai convert krne ka move = 0 se 100 convert krne ka move):
minNumberOfOps(1000->1010) = minNumberOfOps(1010->1000) = minNumberOfOps(10->0)
so:
minNumberOfOps(1010->0) = minNumberOfOps(1000->0) -minNumberOfOps(1010–1000)
*/

class Solution {
public:
    int solve(int n)
    {
        if (n <= 1)//base case is 0 and 1 
        {
            return n;
        }
    // Now we find the next bit of the highest set bit
        int msb = 0;
        while ((1 << msb) <= n) 
        {
            msb++;
        }
        int total_moves = (1<<msb) - 1;// for 2^n moves = 2^(n+1) - 1
        
        return total_moves - solve(n - (1<<(msb-1)));//for remaining cal (take above example of 1010)
    }
    int minimumOneBitOperations(int n) 
    {
        return solve(n);
    }
};
