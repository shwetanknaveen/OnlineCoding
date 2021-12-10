//Problem link - https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
//Video link - https://www.youtube.com/watch?v=II6ziNnub1Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=46

//Case-1 If only number of maximum meetings is to be found
//Just select those meetings which have early ending time


#include <bits/stdc++.h>
using namespace std;

 
class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> meetings;
        for(int i = 0;i<n;i++)
        {
            vector<int> meeting(2,0);
            meeting[0] = end[i];
            meeting[1] = start[i];
            meetings.push_back(meeting);
        }
        sort(meetings.begin(),meetings.end());
        int count=0,lastEnd=-1;
        for(int i=0;i<n;i++)
        {
            if(meetings[i][1]>lastEnd)//if current meeting has to be selected then its start time must be greater than last
            							//meeting's end time
            {
                count++;
                lastEnd = meetings[i][0];
            }
        }
        return count;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  

//Case 2 -> When list of those meetings have to be returned. Here if two meetings have same end time then we keep the order
//of those meetings in sorted result same as there original order

struct meeting {
    int start;
    int end;
    int pos; 
}; 
bool comparator(struct meeting m1, meeting m2) 
{ 
    if (m1.end < m2.end) return true; //sort in increasing order of end time
    else if(m1.end > m2.end) return false; 
    else if(m1.pos < m2.pos) return true; //if same end time then keep the original order same
    return false; 
} 
void maxMeetings(int s[], int e[], int n) {
    struct meeting meet[n]; 
    for(int i = 0;i<n;i++) {//store all the data
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1; 
    }
    
    sort(meet, meet+n, comparator); 
    
    vector<int> answer;
    
    int limit = meet[0].end; //initialise last meeting's end time with first meeting end time
    answer.push_back(meet[0].pos); //first meeting will be done anyway as the meeting room is initially empty
    
    for(int i = 1;i<n;i++) {//start looking from second meeting
        if(meet[i].start > limit) {//for current meeting to happen, its start time should be greater than last meeting's end time
            limit = meet[i].end; //update the last meeting's end time
            answer.push_back(meet[i].pos); 
        }
    }
    for(int i = 0;i<answer.size();i++) {
        cout << answer[i] << " "; 
    }
    
}

