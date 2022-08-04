//Problem link - https://leetcode.com/problems/mirror-reflection/

//Why we make either of one odd -> https://www.youtube.com/watch?v=_xIBOUWEq1c
//How to decide the return cases -> https://www.youtube.com/watch?v=vjh7gttj_kk&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=16
class Solution {
public:
    int mirrorReflection(int p, int q) 
    {
        while(!(p&1) && !(q&1))//both are even
        {
            p >>= 1;
            q >>= 1;
        }
        if(!(p&1) && (q&1)) return 2;
        else if((p&1) && (q&1)) return 1;
        return 0;
    }
};
