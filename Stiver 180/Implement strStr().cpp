//Problem link - https://leetcode.com/problems/implement-strstr/

//Approach 1 ->Brute Force

class Solution {
public:
    int strStr(string haystack, string needle) {
            int len = haystack.length(), patLen = needle.length();
            if(patLen ==0) return 0;
            for(int i = 0;i<len;i++)
            {
                int j;
                for(j=0;j<patLen && (i+j)<len;j++)
                {
                    if(haystack[i+j] != needle[j])
                        break;
                }
                if(j==patLen)//all characters of the pattern matched for string starting from i
                    return i;
            }
            return -1;
    }
};

//Approach 2 -> Using Rabin Karp algorithm

class Solution {
public:
    int strStr(string haystack, string needle) {
        int msbPwrVal = 1;//it will have value = d^(patLen - 1)
            int d = 26;
            int patLen = needle.length(), txtLen = haystack.length();
            if(patLen==0) return 0;
            int mod = 1000;//We have to keep mod as not a very large value
            			//https://stackoverflow.com/questions/68336852/rabin-karp-not-working-for-large-primes-gives-wrong-output
    
            for(int i=0;i<patLen-1;i++)//msbPwrVal = d^(patLen - 1)
            {
                msbPwrVal = (msbPwrVal * d)%mod;
            }
            int txtHash = 0, patHash = 0;
            for(int i=0;i<patLen;i++)
            {
                txtHash = ((d*txtHash)%mod + haystack[i]%mod)%mod;//txtHash = d*txtHash + txt[i]
                											//(a+b)%m = (a%m + b%m)%m
                patHash = ((d*patHash)%mod + needle[i]%mod)%mod;//patHash = d*patHash + pat[i]
                											//(a+b)%m = (a%m + b%m)%m
            }
            for(int i=0;i<=txtLen-patLen;i++)//last window will be starting from index (txtLen-patLen)
            {
                if(txtHash == patHash)
                {
                    int j;
                    for(j=0;j<patLen;j++)
                    {
                        if(haystack[i+j]!=needle[j])
                            break;
                    }
                    if(j==patLen)//matched whole pattern
                        return i;//only first occurence instance index is required hence return it from here only
                }
                //now hash for next window will be calculated and the window in which
                //hash for last window(as next window) will be calculated will start
                //at index = txtLen - patLen - 1
                if(i<(txtLen-patLen))
                {
                    txtHash = (((txtHash%mod-(haystack[i]*msbPwrVal)%mod + mod)%mod * d%mod)%mod + haystack[i+patLen])%mod;
                    //txtHash = (txtHash - (txt[i]*msbPwrVal)) * d + txt[i+patLen]
                    //(ab%m)=((a%m)(b%m))%m
                    //(a-b)% mod = (a%mod - b%mod + mod)%mod
                }
            }
            
            return -1;
    }
};
