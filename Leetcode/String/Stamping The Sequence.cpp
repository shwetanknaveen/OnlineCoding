//Problem link - https://leetcode.com/problems/stamping-the-sequence/
//Video link - https://www.youtube.com/watch?v=EtalsGoNrBI
//target len = N, stamp len = M  ==> T(n) = O(N x (N-M))
//We will be going backwards by converting all characters of target to '?'.
class Solution {
public:
    bool canReplace(string &stamp,string &target,int startPos)
    {
        for(int i=0;i<stamp.length();i++)
        {
            if(stamp[i] != target[startPos+i] && target[startPos+i] != '?')//We can replace if character of stamp matches or target has already '?'
                return false;
        }
        return true;
    }
    void replace(string &target,int lenOfStamp,int startPos,int &count)
    {
        for(int i=0;i<lenOfStamp && count!=target.length();i++)
        {
            if(target[startPos+i] != '?') count++;//this alphabet is now converted to '?'
            target[startPos+i] = '?';
        }
    }
    vector<int> movesToStamp(string stamp, string target) 
    {
        int count = 0;//How many chars in target are now '?'
        vector<int> ans;
        bool changed;
        vector<bool> stamped(target.length(),false);
        while(count != target.length())//untill all chars of target are converted to '?'
        {
            changed = false;//let's say in this pass no stamp was possible
            for(int startPos=0;(startPos+stamp.length())<=target.length();startPos++)
            {
                if(!stamped[startPos] && canReplace(stamp,target,startPos))//if stamp wasn't put here earlier
                {
                    replace(target,stamp.length(),startPos,count);
                    changed = true;
                    stamped[startPos] = true;
                    ans.push_back(startPos);
                    if(count==target.length())//no more stamping needed as now all target chars are '?' 
                        break;
                }
            }
            if(!changed) return {};
        }
        if(ans.size()>10*target.length()) return {};//It is given that conversion should take atmost 10*targetLen stamps
        reverse(ans.begin(),ans.end());//As we proceeded in reverse manner
        return ans;
    }
};
