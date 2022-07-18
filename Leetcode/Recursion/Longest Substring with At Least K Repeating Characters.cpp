//Problem link - https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution {
public:
    int helper(string &s,int &k,int start,int end)
    {
        if(end-start+1<k) return 0;//if this substring from start to end itself is shorter than k then it won't be possible
        vector<int> freqInWind(26,0);
        for(int i=start;i<=end;i++)
            freqInWind[s[i]-'a']++;
        
        for(int i=start;i<=end;i++)//Find invalid characters in the window -> Having less frequency than k
        {
            if(freqInWind[s[i]-'a']<k)
            {
                int j = i+1;
                while(j<=end && freqInWind[s[j]-'a']<k) j++;//Skip all invalid characters
                return max(helper(s,k,start,i-1),helper(s,k,j,end));//We have to split leaving invalid characters and there is an invalid character at ith index
            }
        }
        
        return end-start+1;//no invalid character in the window was found
        
    }
    int longestSubstring(string s, int k) {
        return helper(s,k,0,s.length()-1);
    }
};
