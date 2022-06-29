//Problem link - https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        int n = people.size(),grOrEqToSkip,i;
        vector<vector<int>> ans(n);
        vector<bool> filled(n,false);
        sort(people.begin(),people.end());
        for(auto v:people)
        {
            grOrEqToSkip = v[1];//How many persons should be ahead of this person having height >= than its height
            for(i=0;grOrEqToSkip;i++)
            {
                if(filled[i])
                {
                    if(ans[i][0]>=v[0]) grOrEqToSkip--;//person already standing in final arrangement has height greater than or equal to this person height hence it will contribute in the count
                }
                else grOrEqToSkip--;//If this slot is empty then obviously it will be taken by someone having >= height
                                    //because people is sorted in ascending order hence it will contribute in count for
                                    //this person of persons having height >= its height
            }
            
            //Now required number of skips has been done, we just need to look for an empty slot from here where we can
            //make this person stand
            while(filled[i])
                i++;
            ans[i] = v;//this person takes ith position in the final arrangement
            filled[i] = true;
        }
        return ans;
    }
};
