//Problem link - https://leetcode.com/problems/longest-valid-parentheses/

//Approach 1 -> Using stack
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stac;//this stack will keep indices of the parenthesis in the string s
        stac.push(-1);//We keep -1 initially so that if say s = () then when we encounter ) at index = 1 we pop one value from stack and see
        			//-1 on top of stack and put ans as max(0,1-(-1)) = 2
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') stac.push(i);
            else	//	')' is encountered
            {
                stac.pop();
                if(!stac.empty())//if stack is not empty after popping the top value then it means that there we valid number of open ( were
                				//seen so that this ) can be accomodated
                {
                    ans = max(ans,i-stac.top());
                }
                else
                {
                    stac.push(i);//if stack becomes empty then push this index so that this will act as index after which valid parenthesis
                    			//substring starts. It can be understood better with example
                }
            }
        }
        return ans;
    }
};

//Apporach 2-> Using DP
//dp[i] => Maximum length of valid parentheses considering string upto index i
class Solution {
public:
    int longestValidParentheses(string s) 
	{
        int mx_ans = 0;
        vector<int> dp( s.length(), 0 );
        for( int i=1; s[i] ; i++ )
		{
            if( s[i] == ')' )//When closing parenthesis is encountered then only there is possibility of some valid parenthesis substring
			{
                if( s[i-1] == '(' )//last character was opening parenthesis
				{
                    if( i > 1 )//these two parenthesis contribute value of 2 to the valid length and previous value is added
                        dp[i] = dp[i-2] + 2;
                    else
                        dp[i] = 2;
                }
                else if( i > dp[i-1] && s[ i - dp[i-1] - 1] == '(' )//if last character wasn't '(' then there may be a valid length of paren
                													//-thesis just before it and there lies a '(' for this ')' before that length
																	//the condition (i - dp[i-1] - 1)>=0 => i >= dp[i-1] + 1
				{
                    dp[i] = dp[i-1] + 2;//this set will contribute 2 in length
                    if( i - dp[i-1] >= 2 )//()()_(()) here we see that valid length before _ has to be added in valid length after _
                        dp[i] += dp[ i - dp[i-1] - 2 ];
                }
                mx_ans = max( mx_ans, dp[i] );
            }
        }
        return mx_ans;
    }
};
