//Problem link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

//Approach 1
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stac;
        for(char c:s)
        {
            if(!stac.empty())
            {
                if(c==stac.top().first)//if this character is same as what is on the top of stack
                {
                    stac.push(make_pair(c,stac.top().second+1));//this character will be pushed with its count increased by 1
                }
                else
                {
                    stac.push(make_pair(c,1));//this character is different than what is on the top of stack
                }
            }
            else
            {
                stac.push(make_pair(c,1));//if stack is empty then we have to simply push this character with its count = 1
            }
            if(stac.top().second==k)//After pushing the last character, if its count is k then we have to remove k characters from stack
            {
                int count = k;
                while(count--)
                    stac.pop();
            }
        }
        string ans;
        while(!stac.empty())//store the ans after all possible removals
        {
            ans.push_back(stac.top().first);
            stac.pop();
        }
        reverse(ans.begin(),ans.end());//We used stack, hence we have to reverse the obtained string
        return ans;
    }
};

//Approach 2

string removeDuplicates(string s, int k) {
    vector<int> count(s.size());
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            count[i] = 1;
        } else {
            count[i] = count[i - 1] + 1;
            if (count[i] == k) {
                s.erase(i - k + 1, k);
                i = i - k;
            }
        };
    }
    return s;
}
