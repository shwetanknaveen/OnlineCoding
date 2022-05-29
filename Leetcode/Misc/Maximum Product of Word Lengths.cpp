//Problem link - https://leetcode.com/problems/maximum-product-of-word-lengths/

//Apporoch 1 -> Brute force
class Solution {
public:
    bool commLett(int &ind1,int &ind2,vector<vector<bool>> &mp)
    {
        for(int i=0;i<26;i++)
        {
            if(mp[ind1][i] && mp[ind2][i]) return true;
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int nWords = words.size();
        vector<vector<bool>> mp(nWords,vector<bool>(26,false));
        for(int i=0;i<nWords;i++)
        {
            for(char c:words[i])
            {
                mp[i][c-'a'] = true;
            }
        }
        int ans = 0;
        for(int i=0;i<nWords;i++)
        {
            for(int j=i+1;j<nWords;j++)
            {
                if(!commLett(i,j,mp))//doesn't share common letter
                {
                    int len1 = words[i].length();
                    int len2 = words[j].length();
                    ans = max(ans,len1*len2);
                }
            }
        }
        return ans;
    }
};

//Apporach 2 -> Optimisation using bit masking

class Solution {
public:
    int maxProduct(vector<string>& words) {
    vector<int> mask(words.size());
    int result = 0;
    for (int i=0; i<words.size(); ++i) {
        for (char c : words[i])
            mask[i] |= 1 << (c - 'a');//set mask for this word
        for (int j=0; j<i; ++j)//check with all other words' masks
            if (!(mask[i] & mask[j]))
                result = max(result, int(words[i].size() * words[j].size()));
    }
    return result;
}
};
