//Problem link - https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
/*
we need both attack and defence of the player should be less than the other player then only we can say the later person is 
weaker so we need to see two parameter(defence and attack) to give our answer
we can do a thing lets sort the array on one parameter and then we will see how will we handle the other one
if the array is sorted on one parameter we only need to worry about other. As the array is sorted the greater index cant be 
weaker than then smaller index i.e if i > j i cant be weaker than j (as the array is sorted)
so lets iterate from back and store the maximum element we encounter(as if we found a larger element(value of second 
parameter) on right it will be weaker as the second element is less and first one was already less because of sorting so both
strenght and defence is weak)
when ever we encounter this we increased our answer by one

EDGE CASE : if on sorting 2 element have same attack strength we will put the one with greater defence first because 
we only need both parameter to be strictly greater.if we ignore this case we will increase the answer in following case
(5, 2), (5, 4) our code will give answer 1 if we dont handle edge case while the answer should be zero
example:
         -(5,2),(5,4) gives ans 1 (wrong ans as both have strength of 5 which is not strictly increasing
		 we need to tackle this that why we put (5,4) before (5,2) to tackle the case ) 
         
		 -(5,4),(5,2) gives ans 0 (which is correct)
*/
class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        if(v1[0]<v2[0]) return true;//Assure that attack of earlier lying character in properties is smaller
        if(v1[0]==v2[0]) return v1[1]>v2[1];//if attack is same then sort in descending manner of defence
        return false;
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) 
    {
        sort(properties.begin(),properties.end(),cmp);
        int maxDef = INT_MIN,ans = 0;
        for(int i=properties.size()-1;i>=0;i--)
        {
            if(properties[i][1]<maxDef) ans++;
            maxDef = max(maxDef,properties[i][1]);
        }
        return ans;
    }
};
