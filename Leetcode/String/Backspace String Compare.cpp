//Problem link - https://leetcode.com/problems/backspace-string-compare/


//Approach 1->Using extra space
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string newS,newT;
        for(char c:s)
        {
            if(c=='#' && !newS.empty())
                newS.pop_back();
            else if(c!='#') newS.push_back(c);
        }
        for(char c:t)
        {
            if(c=='#' && !newT.empty())
                newT.pop_back();
            else if(c!='#') newT.push_back(c);
        }
        return !newS.compare(newT);//.compare() returns 0 when strings are equal
    }
};

//Approach 2 Using two pointers

class Solution {
public:
    bool backspaceCompare(string s, string t) {
      int l1 = s.length()-1, l2 = t.length()-1,toSkipS=0,toSkipT=0;
        
      while(l1>=0 || l2>=0)//If any of the string is left to process
      {
          while(l1>=0)//We can process s
          {
              if(s[l1]=='#')
              {
                  toSkipS++;
                  l1--;
              }
              else if(toSkipS>0)
              {
                  l1--;
                  toSkipS--;
              }
              else break;//Now the character pointed by l1 will be compared if l1 points to index>=0
          }
          
          while(l2>=0)//We can process t
          {
              if(t[l2]=='#')
              {
                  toSkipT++;
                  l2--;
              }
              else if(toSkipT>0)
              {
                  l2--;
                  toSkipT--;
              }
              else break;//Now the character pointed by l2 will be compared if l2 points to index>=0
          }
          if((l1>=0) != (l2>=0)) return false;//if one of the string has been exhausted but the other one is still remaining
          
          if(l1>=0 && l2>=0)//If both point to some genuine index
          {
              if(s[l1] != t[l2]) return false;//and characters at those indices are not equal
              else//both characters are equal
              {
              	l1--;
              	l2--;
			  }
          }
      }
        return true;
    }
};
