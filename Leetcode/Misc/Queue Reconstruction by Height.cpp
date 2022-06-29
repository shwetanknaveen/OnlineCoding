//Problem link - https://leetcode.com/problems/queue-reconstruction-by-height/

//Approach 1
/*
To satisfy the condition of rank for any person, all the taller persons and all the persons having same height having
lower rank (second index value is smaller) should be already present in the queue so that this person can be inserted at the right position. For e.g.,tallest person having second index value as 0 should be inserted first because if 
some other person having same height but second value as 1 comes, then it can be inserted behind the tallest person
having value 0
*/

class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        if(v1[0]>v2[0]) return true;//first sort as per descending order of height
        else if(v1[0]==v2[0]) return v1[1]<v2[1];//if height is same then sort as per asceding value of second index
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> ans;
        for(auto v:people)
            ans.insert(ans.begin()+v[1],v);//insert as per the second index value of this person because all the
                                            //persons having taller height or persons having equal height having
                                            //lower second index value would already been inserted hence this person
                                            //will automatically get inserted at the right place
        return ans;
    }
};
//Approach 2
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
