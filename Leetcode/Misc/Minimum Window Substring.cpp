//Problem link - https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) 
    {
        int sLen = s.length(), tLen = t.length();
        if(sLen<tLen) return "";//s can't contain all the characters of t
        unordered_map<char,int> need,presInS;
        unordered_set<char> presSet;//contains all the characters which are present in present window with count>=required
        for(char c:t) need[c]++;
        int miniLen = INT_MAX;
        string ans;
        /*
        Window first expands on right side with help of j. If in this process, it makes up all required characters then stores the ans (min)
        and starts shrinking from left until it can shrink from left such that after shrinking it still holds all the characters with their
        right count
        */
        for(int i=0,j=0;i<sLen && j<sLen;)
        {
            presInS[s[j]]++;
            if(need.count(s[j])!=0 && presInS[s[j]]==need[s[j]]) presSet.insert(s[j]);//this character with its right count has been found
            if(presSet.size()==need.size())//found all the characters needed
            {
                if(j-i+1<miniLen)//store the best answer
                {
                    miniLen = j-i+1;
                    ans = s.substr(i,miniLen);
                }
                while(presSet.size()==need.size())//shrink the window from left untill it contains all the character required
                {
                    presInS[s[i]]--;
                    if(need.count(s[i])!=0 && presInS[s[i]]<need[s[i]]) presSet.erase(s[i]);
                    i++;
                }
                if(j-(i-1)+1<miniLen)//after shrinking, i-1 was the left index of window which holded all the characters required
                {
                    miniLen = j-(i-1)+1;
                    ans = s.substr(i-1,miniLen);
                }
            }
            j++;//after this window has shrunk from left or in otherwise case also, j has to keep on expanding on its right
        }
        return ans;
    }
};
