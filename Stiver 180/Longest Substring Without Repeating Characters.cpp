//Problem link - https://leetcode.com/problems/longest-substring-without-repeating-characters/
//Video link - https://www.youtube.com/watch?v=qtVh-XEpsJo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=27

//Approach 1 -> Jumping the left pointer one by one until it surpasses the already occuring character
//Time Complexity -> O(2n)	Space complexity -> O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0,left=0,right=0;
        unordered_set<char> chars;
        while(right<n)
        {
            if(chars.find(s[right]) == chars.end())
            {
                chars.insert(s[right]);
                maxi = max(maxi,right-left+1);//upto here, string from left to right contains all unique characters
                right++;//we will check next right character
            }
            else
            {
                while(chars.find(s[right]) != chars.end())
                    chars.erase(s[left++]);//keep on erasing the characters pointed by left and keep incrementing left
                    						//until it passes that character which is pointed by right and causing duplicacy
            }
        }
        return maxi;
    }
};

//Approach 2 -> Jumping the left pointer DIRECTLY such that it surpasses the already occuring character
//Time Complexity -> O(n)	Space complexity -> O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0,left=0,right=0;
        unordered_map<char,int> chars_index;
        while(right<n)
        {
            
                if(chars_index.find(s[right]) != chars_index.end())//character pointed by right is already there in set(map)
                {
                    left = max(chars_index[s[right]]+1,left);
                	//we need unique character from left to right but if that already occuring
                	//character is on left of current left, then we don't update our current
                	//left that's why we took max()
                }    
                chars_index[s[right]] = right;//update as when was the character saw by right was seen for the last time at what index
                maxi = max(maxi,right-left+1);//first calculate the length then increase right so that to look forward
                right++;
            
        }
        return maxi;
    }
};
