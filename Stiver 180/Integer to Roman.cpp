//Problem link - https://leetcode.com/problems/integer-to-roman/

//Code 1
class Solution {
public:
    pair<int,string> getChar(int i)//pair<> = <remaining value,char>
    {
        if(i>=1000 || i>=900)//=>i>1000
        {
            if(i>=1000)
            {
                return make_pair(i-1000,"M");
            }
            return make_pair(i-900,"CM");
        }
        else if(i>=500 || i>=400)
        {
            if(i>=500)
            {
                return make_pair(i-500,"D");    
            }
            return make_pair(i-400,"CD");
        }
        else if(i>=100 || i>=90)
        {
            if(i>=100)
            {
                return make_pair(i-100,"C");    
            }
            return make_pair(i-90,"XC");
        }
        else if(i>=50 || i>=40)
        {
            if(i>=50)
            {
                return make_pair(i-50,"L");    
            }   
            return make_pair(i-40,"XL");
        }
        else if(i>=10 || i>=9)
        {
            if(i>=10)
            {
                return make_pair(i-10,"X");    
            }
            return make_pair(i-9,"IX");
        }
        else if(i>=5 || i>=4)
        {
            if(i>=5)
            {
                return make_pair(i-5,"V");    
            }
            return make_pair(i-4,"IV");
        }
        else
        {
            return make_pair(i-1,"I");
        }
    }
    string intToRoman(int num) {
        string ans = "";
        pair<int,string> temp;
        while(num!=0)
        {
            
            temp = getChar(num);
            ans = ans + temp.second;
            num = temp.first;
        }
        return ans;
    }
};

//Code 2 => More neat code

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> chars = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans = "";
        int n = values.size();
        for(int i=0;i<n;i++)
        {
            while(num>=values[i])
            {
                num -= values[i];
                ans += chars[i];
            }
        }
        return ans;
    }
};
