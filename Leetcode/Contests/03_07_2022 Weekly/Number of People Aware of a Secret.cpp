//Problem link - https://leetcode.com/problems/number-of-people-aware-of-a-secret/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int day = 1,count = 1,mod = 1e9+7;
        queue<pair<int,int>> nKnowOnDay;//<How many know the secret -> On which day>
        nKnowOnDay.push(make_pair(1,1));
        for(int i=2;i<=n;i++)
        {
            //Make all those forget the secret who have to forget
            while(!nKnowOnDay.empty() && i-forget == nKnowOnDay.front().second)
            {
                nKnowOnDay.pop();
            }
            queue<pair<int,int>> temp = nKnowOnDay;
            int howManyWillTellToday = 0;
            while(!temp.empty() && i-delay >= temp.front().second)
            {
                howManyWillTellToday =(howManyWillTellToday%mod + temp.front().first%mod)%mod;
                temp.pop();
            }
            if(howManyWillTellToday != 0)
                nKnowOnDay.push(make_pair(howManyWillTellToday,i));
            
        }
        int ans = 0;
        while(!nKnowOnDay.empty())
        {
            ans = (ans%mod + nKnowOnDay.front().first%mod)%mod;
            nKnowOnDay.pop();
        }
        return ans;
    }
};
