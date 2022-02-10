/*
Question - Given a numeric pad 2d-array of mobile keypad from (2-9) [[“abc”][def][“ghi”][“jkl”][“mno”][“pqrs”][“tuv”][“wxyz”]] 
and a string ex BAD find the number sequence representing the string and then find how many numbers of words can be formed by 
that combination. Return that number

O(n) time ans O(1) space
Algorithm: 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    private: 
        map<char,int> keypadMapping;
    public:
        Solution(){
            vector<string> keyPad = {"abc","def","ghi","jkl","mnop","qrst","uvw","xyz"};
            for(int index = 0; index<keyPad.size(); index++){
                keypadMapping['2'+index] = keyPad[index].size();//how many characters are there at key (2+index)
                for(char letter:keyPad[index]) keypadMapping[letter] = index+2;
            }
        }
        
        string getNumberSequence(string word){
            string numberSequence = "";
            for(char letter:word) numberSequence += keypadMapping[letter]+'0';
            return numberSequence;
        }
        
        int getWordCount(string numberSequence){
            if(numberSequence=="") return 0; 
            int wordCount = 1;
            for(char digit:numberSequence) wordCount *= keypadMapping[digit];
            return wordCount;
        }
};

int main(){
    Solution s;
    cout<<s.getNumberSequence("abcd")<<endl;
    cout<<s.getWordCount("2253")<<endl;
    return 0;
}

