//Problem link - https://leetcode.com/problems/expressive-words/

class Solution {
public:
    vector<pair<char,int>> getGroups(string &str)//for str = "heeellooo", it returns <<h,1>,<e,3>,<l,2>,<o,3>> i.e., character in order and there
    {											// count when they occur as group
        vector<pair<char,int>> ans;
        int len = str.length();
        for(int i=0,j=0;i<len && j<len;)
        {
            while(j<len && str[j]==str[i]) j++;//stretch the window on this same group of character
            ans.push_back({str[i],j-i});//from i to (j-1), all characters are same i.e., str[i]
            i=j;//next time window will start from next different character
        }
        return ans;
    }
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char,int>> sGroup = getGroups(s);//this will remain fixed as we can't make any change to this
        int ans = 0;
        for(string word:words)
        {
            bool isStretchy = true;
            vector<pair<char,int>> thisGroup = getGroups(word);
            if(thisGroup.size() != sGroup.size()) isStretchy = false;//all characters should come in same order,count may be different
            else//let's match each group
            {
                for(int i=0;i<thisGroup.size();i++)
                {
                    if(thisGroup[i].first != sGroup[i].first || thisGroup[i].second>sGroup[i].second)//if character in this group doesn't
                    {																				//match for both the strings or count of
                        isStretchy = false;															//this character in this word is greater
                        break;																		//(We can just add characters in this
                    }																				//word but can't delete from it)
                    if(thisGroup[i].second<sGroup[i].second && sGroup[i].second<3)//if this word lacks some count of character then we can
                    {															//stretch the group only if we need more 2 characters finally
                        isStretchy = false;										//for this group
                        break;
                    }
                }
            }
            if(isStretchy) ans++;
        }
        return ans;
    }
};
