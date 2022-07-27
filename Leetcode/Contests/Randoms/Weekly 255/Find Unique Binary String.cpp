//Problem link - https://leetcode.com/problems/find-unique-binary-string/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size(), len = n;
        string ans = "";
        int ind=0,stringNum = 0;
        while(ind<n)
        {
            if(nums[stringNum][ind]=='0') ans.push_back('1');
            else ans.push_back('0');//Push opposite of what is at this index in this num and in this way
            ind++;                  //ans will vary with this num by this bit. Diagonalization approach
            stringNum++;
        }
        return ans;
    }
};
