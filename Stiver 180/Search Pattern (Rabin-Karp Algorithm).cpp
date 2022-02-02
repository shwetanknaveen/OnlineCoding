//Problem link - https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1/#
//Video link - https://www.youtube.com/watch?v=qQ8vS2btsxI
//Approach 1 - Brute force 
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int len = txt.length(), patLen = pat.length();
            vector<int> ans;
            for(int i = 0;i<len;i++)
            {
                int j;
                for(j=0;j<patLen && (i+j)<len;j++)
                {
                    if(txt[i+j] != pat[j])
                        break;
                }
                if(j==patLen)//all characters of the pattern matched for string starting from i
                    ans.push_back(i+1);//for ans, we have to consider 1 based indexing
            }
            if(ans.empty()) ans.push_back(-1);//we have to return -1 if there is no occurence of patter in the given text
            return ans;
        }
     
};

//Approach 2 Rabin Karp algo and rolling hash (No need to calculate hash from scratch each time)
/*
Formulae for modulus :-
(ab%m)=((a%m)(b%m))%m
(a+b)%m = (a%m + b%m)%m
(a-b)% mod = (a%mod - b%mod + mod)%mod
*/
//Average time complexity -> O(m+n)
//Worst case time complexity -> O(mn)
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int msbPwrVal = 1;//it will have value = d^(patLen - 1)
            int d = 26;
            int patLen = pat.length(), txtLen = txt.length();
            int mod = 1000;//We have to keep mod a smaller value
            			//https://stackoverflow.com/questions/68336852/rabin-karp-not-working-for-large-primes-gives-wrong-output
    
            for(int i=0;i<patLen-1;i++)//msbPwrVal = d^(patLen - 1)
            {
                msbPwrVal = (msbPwrVal * d)%mod;
            }
            int txtHash = 0, patHash = 0;
            for(int i=0;i<patLen;i++)
            {
                txtHash = ((d*txtHash)%mod + txt[i]%mod)%mod;//txtHash = d*txtHash + txt[i]
                											//(a+b)%m = (a%m + b%m)%m
                patHash = ((d*patHash)%mod + pat[i]%mod)%mod;//patHash = d*patHash + pat[i]
                											//(a+b)%m = (a%m + b%m)%m
            }
            vector<int> ans;
            for(int i=0;i<=txtLen-patLen;i++)//last window will be starting from index (txtLen-patLen)
            {
                if(txtHash == patHash)
                {
                    int j;
                    for(j=0;j<patLen;j++)
                    {
                        if(txt[i+j]!=pat[j])
                            break;
                    }
                    if(j==patLen)//matched whole pattern
                        ans.push_back(i+1);
                }
                //now hash for next window will be calculated and the window in which
                //hash for last window(as next window) will be calculated will start
                //at index = txtLen - patLen - 1
                if(i<(txtLen-patLen))
                {
                    txtHash = (((txtHash%mod-(txt[i]*msbPwrVal)%mod + mod)%mod * d%mod)%mod + txt[i+patLen])%mod;
                    //txtHash = (txtHash - (txt[i]*msbPwrVal)) * d + txt[i+patLen]
                    //(ab%m)=((a%m)(b%m))%m
                    //(a-b)% mod = (a%mod - b%mod + mod)%mod
                }
            }
            if(ans.empty()) ans.push_back(-1);
            return ans;
        }
     
};


