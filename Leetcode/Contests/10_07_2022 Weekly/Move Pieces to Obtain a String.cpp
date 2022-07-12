//Problem link - https://leetcode.com/problems/move-pieces-to-obtain-a-string/

class Solution {
public:
    bool canChange(string start, string target) 
    {
        int i = 0,j = 0,n = target.length();//it's given that start and target have same length
        while(i<n || j<n)
        {
            //Skip the '_' characters
            while(i<n && start[i]=='_') i++;
            while(j<n && target[j]=='_') j++;
            
            if(j==n || i==n)
            {
                return (i==n && j==n);//both strings should exhaust together
            }
            if(start[i] != target[j]) return false;
            
            //Now we are sure that start[i] = target[j]
            if(target[j]=='L')
            {
                if(i<j) return false;//L at i index in start can be shifted towards its left only but here
                                    //j index in target is on right
            }
            else//=> target[j]='R'
            {
                if(i>j) return false;//R at i index in start can be shifted towards its right only but here
                                    //j index in target is on left
            }
            i++;
            j++;
        }
        return true;
    }
};
