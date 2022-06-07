//Problem link - https://leetcode.com/contest/weekly-contest-296/problems/min-max-game/

//Approach 1 -> Linear space
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> pres;
        while(pres.size()!=1)
        {
            for(int i=0;i<nums.size();)
            {
                pres.push_back(min(nums[i],nums[i+1]));
                i = i+2;
                if(i>=nums.size()) break;
                pres.push_back(max(nums[i],nums[i+1]));
                i = i+2;
            }
            nums.clear();
            nums = pres;
            if(pres.size()!=1)
            pres.clear();
        }
        return pres[0];
    }
};

//Approach 2-> Constant space
class Solution {
public:
    int minMaxGame(vector<int>& arr) {
        
        int n = arr.size();
        
        while( n > 1 ){
            for( int i=0, j = 0 ; i < n; i+=2, j++ ){
                if( j&1 )
                    arr[j] = max( arr[i], arr[i+1] );
                else
                    arr[j] = min( arr[i], arr[i+1] );
            }
            n /= 2;
        }
        return arr[0];
    }
};
