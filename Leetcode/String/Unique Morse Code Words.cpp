//Problem link - https://leetcode.com/problems/unique-morse-code-words/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string> mp = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	    unordered_set<string> allCodes;
	    for(auto word:words)
	    {
	        string thisCode = "";
	        for(char c:word)
	        {
	            thisCode += mp[c-'a'];
	        }
	        allCodes.insert(thisCode);
	    }
	    return allCodes.size();
    }
    
};
