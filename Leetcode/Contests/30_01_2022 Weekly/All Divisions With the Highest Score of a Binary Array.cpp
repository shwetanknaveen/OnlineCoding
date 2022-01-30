//Problem link - https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/

class Solution {
public:
    //The division score of an index i is the sum of the number of 0's in numsleft and the number of 1's in numsright
    vector<int> maxScoreIndices(vector<int>& nums) {
        int totZero = 0,totOne = 0;
        vector<pair<int,int>> indScore;//ind,score
        int maxi = INT_MIN;
        for(int i:nums)
        {
            if(i==0)
                totZero++;
            else if(i==1)
                totOne++;
        }
        int score,zeroNotOnLeft,oneNotOnRight;
        zeroNotOnLeft = totZero;//initially all zeroes are on right
        oneNotOnRight = 0;//initially all ones are on right
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            score = (totZero - zeroNotOnLeft) + (totOne - oneNotOnRight);
            maxi = max(maxi,score);
            indScore.push_back(make_pair(i,score));
            if(nums[i] == 0)
                zeroNotOnLeft--;
            else if(nums[i] == 1)
                oneNotOnRight++;
        }
        indScore.push_back(make_pair(n,totZero));//for the last partition
        maxi = max(maxi,indScore[n].second);//for last parition score
        vector<int> ans;
        for(auto p: indScore)
        {
            if(p.second==maxi)//all those partition indices for which score is maximum
                ans.push_back(p.first);
        }
        return ans;
        
    }
};
