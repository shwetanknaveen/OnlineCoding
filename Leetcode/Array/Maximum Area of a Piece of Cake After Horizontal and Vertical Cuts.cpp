//Problem link - https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxHeight,maxWidth,mod = 1e9+7;
        maxHeight = maxWidth = 0;
        
        //Although there is no explicit cut in begining and last of height and width but they will also form a cut
        //piece hence inserting those cuts
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        for(int i=0;i<horizontalCuts.size()-1;i++)
            maxHeight = max(maxHeight,horizontalCuts[i+1]-horizontalCuts[i]);
        for(int i=0;i<verticalCuts.size()-1;i++)
            maxWidth = max(maxWidth,verticalCuts[i+1]-verticalCuts[i]);
        long prod = (maxHeight%mod);//for preventing overflow
        prod *= (maxWidth%mod);
        
        return (prod)%mod;
    }
};
