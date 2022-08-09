//Problem link - https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

//Approach 1 Brute Force
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

//Approach 2 Order of students doesn't matter because students can keep on rotating and collect from top

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int countOfOne = 0,countOfZero = 0;
        for(int i:students)
        {
            if(i==0) countOfZero++;
            else countOfOne++;
        }
        int top = 0;
        while(top<sandwiches.size())
        {
            if(sandwiches[top]==0)
            {
                if(countOfZero>0)
                {
                    countOfZero--;
                    top++;
                }
                else break;
            }
            else
            {
                if(countOfOne>0)
                {
                    countOfOne--;
                    top++;
                }
                else break;    
            }
        }
        return countOfZero + countOfOne;
    }
};
