//Problem link - https://leetcode.com/problems/shuffle-an-array/

class Solution {
public:
    vector<int> state,safeState;
    Solution(vector<int>& nums) {
        safeState = state = nums;
    }
    
    vector<int> reset() {
        return state = safeState;
    }
    
    vector<int> shuffle() {
        int n = state.size();
        for(int i=0;i<n;i++)
            swap(state[i],state[rand()%n]);
        return state;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
