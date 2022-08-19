//Problem link - https://leetcode.com/problems/split-array-into-consecutive-subsequences/

class Solution {
public:
    struct cmp
    {
        //We write comparator for priority queue in the reverse way as we write for normal sorting functions
        bool operator()(pair<int,int> &p1,pair<int,int> &p2)
        {
            if(p1.first<p2.first) return true;//max heap for first of pair
            if(p1.first==p2.first)
            {
                if(p1.second>p2.second) return true;
                return false;
            }
            return false;
        }
    };
    bool isPossible(vector<int>& nums) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> allSets;
        //<least number in the set,size of this set>
        //We will keep priority queue as max heap for first of pair and min heap for second of pair
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(allSets.empty())//there hasn't been any subsequence formed yet
            {
                allSets.push(make_pair(nums[i],1));
            }
            else
            {
                auto p = allSets.top();
                allSets.pop();
                if(p.first-1==nums[i])//if the least element of this mini set formed which is on top of pq is 1 greater than this number then insert this number in this mini set
                {
                    p.first--;//now it's least element will be one less
                    p.second++;//this number got added in this set hence this set size increased by 1
                    allSets.push(p);
                }
                else if(p.first==nums[i])
                {
                    allSets.push(p);//just push the set which we popped off
                    allSets.push({nums[i],1});//make new set for this number
                }
                else if(p.second >= 3) i++;//remove the mature set and check for this number again that in which set it can be added
                else return false;//this number can't be added in any set
            }
        }
        while(!allSets.empty())
        {
            if(allSets.top().second<3) return false;
            allSets.pop();
        }
        return true;
    }
};
