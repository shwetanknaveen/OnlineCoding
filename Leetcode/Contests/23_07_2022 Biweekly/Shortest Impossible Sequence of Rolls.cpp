//Problem link - https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        vector<int> found(k+1,0);
        int total = 0;
        int size = 1;
        for(int i:rolls)
        {
            if(found[i]==size-1)//For last place in the current size of sequence we haven't found i uptil here
            {                   //that's why its count is (size-1)
                total++;//For last place in the current size of sequence we have found total number of different numbers
                found[i]++;
            }
            if(total==k)//For last place in the current size of sequence we haven found all numbers from 1 to k
            {
                size++;//Now let's see the next size of sequence whether it's possible or not
                total = 0;//total count for this new position is zero i.e., we haven't found any number for this
            }
        }
        return size;
    }
};
