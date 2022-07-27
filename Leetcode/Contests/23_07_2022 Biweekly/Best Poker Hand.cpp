//Problem link - https://leetcode.com/problems/best-poker-hand/

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int,int> rankCount;
        map<char,int> suitCount;
        int maxSuit = 0,maxRank = 0;
        for(int i=0;i<5;i++)
        {
            rankCount[ranks[i]]++;
            suitCount[suits[i]]++;
            maxSuit = max(maxSuit,suitCount[suits[i]]);
            maxRank = max(maxRank,rankCount[ranks[i]]);
        }
        if(maxSuit>=5) return "Flush";
        else if(maxRank>=3) return "Three of a Kind";
        else if(maxRank==2) return "Pair";
        return "High Card";
    }
};
