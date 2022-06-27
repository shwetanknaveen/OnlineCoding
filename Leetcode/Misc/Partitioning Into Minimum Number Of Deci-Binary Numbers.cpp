//Problem link - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution {
public:
    int minPartitions(string n) {
        char ans = '0';
        for(char c:n)
            ans = max(ans,c);
        
        return ans-'0';
    }
};
