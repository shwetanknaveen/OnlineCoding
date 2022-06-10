//Problem link - https://leetcode.com/problems/count-primes/
//https://www.geeksforgeeks.org/sieve-of-eratosthenes/
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> notPrime(n,false);
        int ans = 0;
        for(int i=2;i<n;i++)
        {
            if(notPrime[i]) continue;
            int mult = i, fact = 1;
            while(mult<n)
            {
                notPrime[mult] = true;
                mult = i*fact++;
            }
            ans++;
        }
        return ans;
    }
};
