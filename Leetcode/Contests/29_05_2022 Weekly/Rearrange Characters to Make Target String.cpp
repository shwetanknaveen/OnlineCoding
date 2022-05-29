//Problem link - https://leetcode.com/problems/rearrange-characters-to-make-target-string/

//Approach 1 
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> count(26,0);
        for(char c: s)
            count[c-'a']++;
        int ans = 0;
        bool flag;
        while(1)
        {
            flag = false;
            for(char c:target)
            {
                if(count[c-'a']==0)//this character is not available to use
                {
                    flag = true;
                    break;
                }
                count[c-'a'] -= 1;//now this character is used
            }
            if(flag) break;//word can't be formed again
            ans++;
        }
        return ans;
    }
};

//Approach 2
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> req(26,0), avail(26,0);
        for(char c:s)
            avail[c-'a']++;
        for(char c:target)
            req[c-'a']++;
        
        int ans = INT_MAX;
        for(int i=0;i<26;i++)
        {
            if(req[i]!=0)
                ans = min(ans,avail[i]/req[i]);//demand of this character can be fullfilled atmost avail[i]/req[i] number of times
        }
        return ans==INT_MAX?0:ans;
    }
};
