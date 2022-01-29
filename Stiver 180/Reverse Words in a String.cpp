//Problem link - https://leetcode.com/problems/reverse-words-in-a-string/


//Approach 1
//Time complexity = O(n) Space complexity = O(n)

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        int len = s.length();
        
        string word;
        for(int i=0;i<len;i++)
        {
            if(s[i] != ' ')//if this is non space character then push it in current word
                word.push_back(s[i]);
            else//this is space
            {
                if(!word.empty())//we have a non empty word to push
                {
                    words.push(word);//push the word
                    word.clear();//clear the word for new word formation
                }
                while(i<len && s[i] == ' ')//advance the pointer to non space character
                    i++;
                i--;//for loop will advance once again and it will miss one character hence reduce 1 from i to compensate that
            }
            
        }
        if(!word.empty())//push the last word as it may not be ended by " "
        words.push(word);
        string ans = "";
        while(!words.empty())//stack will pop in reverse order
        {
            if(words.size() != 1)
                ans += words.top() + " ";//if this is not the last word then add " " after this
            else 
                ans += words.top();
            words.pop();
        }
        return ans;
    }
};

//Approach 2 We traverse from right to left
//Time complexity = O(n) 	Space complexity = O(1)
class Solution {
public:
    string reverseWords(string s) {
        
        int len = s.length();
        
        string word;
        string ans = "";
        for(int i=len-1;i>=0;i--)
        {
            if(s[i] != ' ')//if this is non space character then push it in current word in the beginning as we are traversing from right to left
                word = s[i] + word;
            else//this is space
            {
                if(!word.empty())//we have a non empty word to push
                {
                    ans += word + " "; 
                    word.clear();//clear the word for new word formation
                }
                while(i>=0 && s[i] == ' ')//advance the pointer to non space character on the left
                    i--;
                i++;//for loop will advance once again and it will miss one character hence increase 1 to i to compensate that
            }
            
        }
        if(!word.empty())//push the last word as it may not be ended by " "
        ans += word;
        
        int ansLen = ans.length();
        int i;
        for(i=ansLen-1;i>=0;i--)//remove trailing spaces
            if(ans[i] != ' ')
                break;
        return ans.substr(0,i+1);
    }
};
