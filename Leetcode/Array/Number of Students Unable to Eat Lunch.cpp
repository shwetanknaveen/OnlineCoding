//Problem link - https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        bool atLeastOneGot = true;
        int sandTop = 0;
        while(atLeastOneGot)//as long as atleast one guy is getting desired sandwich in one go
        {
            atLeastOneGot = false;
            for(int i=0;i<students.size() && sandTop<sandwiches.size();i++)
            {
                if(students[i]==sandwiches[sandTop])
                {
                    students[i] = -1;//This student is now removed from the queue
                    sandTop++;//look for next sandwich in the stack
                    atLeastOneGot = true;//in processing the whole queue for once, atleast one got the desired sandwich
                }
            }
        }
        int ans=0;
        for(int i:students)//how many didn't get desired sandwich
            if(i!=-1) ans++;
        return ans;
    }
};
