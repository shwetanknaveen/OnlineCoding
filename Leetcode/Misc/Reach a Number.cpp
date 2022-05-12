//Problem link - https://leetcode.com/problems/reach-a-number/
//Video link - https://www.youtube.com/watch?v=WJAA6jr8hMM
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int steps = 1,sum = 0;
        while(sum<target)//We keep on adding steps to sum untill sum is less than target
        {
            sum += steps;
            steps++;
        }
        while((sum-target)%2 != 0)//Once sum surpasses target then it means that we must have missed few negative steps. (Video 2:25)
        						//That is sum-2*(some step) = target => sum-target = 2 * (some step) => (sum-target) is divisible by 2.
								//Hence we can keep on increasing the sum untill (sum-target) becomes divisilbe by 2. 
        {
            sum += steps;
            steps++;
        }
        return steps-1;
    }
};
