//Question link - https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here
        vector<string> sCopy;
        string currWord = "";
        string ans = "";
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='.')
            {
                sCopy.push_back(currWord);
                currWord = "";
            }
            else
            {
            currWord += S[i];
            }
        }
        sCopy.push_back(currWord);//push last word which wasn't ending with .  
        
        for(int i = sCopy.size()-1;i>=0;i--)
        {
            if(i!=0)
            ans =ans + sCopy[i] + ".";//if it's not the last word in the result then save it with .
            else
            ans = ans + sCopy[i];
        }
        
        return ans;
        
    } 
};
