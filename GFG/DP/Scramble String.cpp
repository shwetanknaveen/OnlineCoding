//Problem link - https://www.interviewbit.com/problems/scramble-string/
//Video link - https://www.youtube.com/watch?v=SqA0o-DGmEw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40

bool solve(string a,string b,map<string,bool> &dp)
{
    if(a.compare(b) == 0) return true;//same string hence zero swaps hence it is scramble string
    if(a.length() != b.length()) return false;//strings should be of equal length if they have to be scrambled strings
    int n=a.length();
    if(n<=1) return false;//string is of length 1 and is not equal(crossed first base cond) then it can't be scramble string

    string key = a+"_"+b;//will act as key in dp dp[a_b] will tell that a and b are scramble string or not
    if(dp.find(key)!=dp.end()) return dp[key];
    bool flag = false;
    
    //str.substr(i,l) gives substring of str starting from index i and of length l
    /*
	Here partition is happening at k and resulting into two strings. 
	First string is from index 0 and of length k.
	Second string is from index k and length n-k where n is the length of main string
	*/
    for(int k=1;k<=n-1;k++)
    {
    	//swap at partition k => first part of string a will be scramble string of second part of b and vice versa
        bool cond1 = solve(a.substr(0,k),b.substr(n-k,k),dp) && solve(a.substr(k,n-k),b.substr(0,n-k),dp);
        
		//no swap at partition k => first part of string a will be scramble string of first part of b and vice versa        
        bool cond2 = solve(a.substr(0,k),b.substr(0,k),dp) && solve(a.substr(k,n-k),b.substr(k,n-k),dp);

        if(cond1||cond2)//if it is scramble string either with swap or no swap then it is scramble string
        {
            flag = true;
            break;
        }
    }
    return dp[key] = flag;
}
int Solution::isScramble(const string A, const string B) {
    map<string,bool> dp;
    return solve(A,B,dp);
}
