//Problem link - https://leetcode.com/problems/course-schedule-iii/

class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        return v1[1]<v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;//max heap
        int totalTime = 0;
        sort(courses.begin(),courses.end(),cmp);//the job which has to get completed early comes first
        for(auto &c:courses)
        {
            if(c[1]-c[0]<0) continue;//this course needs to start before 1st day which is not possible
            totalTime += c[0];
            if(totalTime>c[1])//it means it is exceeding the deadline hence we need to remove the largest job
            {
                if(pq.top() > c[0])//if removing the largest job creates space for this job then remove it
                    //this course c will have deadline >= the deadline of the course on top of pq
                {
                    totalTime -= pq.top();
                    pq.pop();
                    pq.push(c[0]);
                }
                else totalTime -= c[0];//even removing the largest job doesn't create space for this one hence this job can't be added
            }
            else//there is no need to remove anything and this job can be accomodated
                pq.push(c[0]);
        }
        return pq.size();//all the jobs which can be done are in the priority queue
    }
};
