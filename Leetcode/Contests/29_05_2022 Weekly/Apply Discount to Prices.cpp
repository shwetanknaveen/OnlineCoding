//Problem link - https://leetcode.com/problems/apply-discount-to-prices/

class Solution {
public:
	bool isPrice(string &word)
    {
        if(word[0]!='$' || word.size()==1) return false;//$ should be in start and there should be atleast one number ahead of it
        for(int i=1;i<word.length();i++)
        {
            if(word[i]>='0' && word[i]<='9') continue;
            return false;
        }
        return true;
    }
    string discountPrices(string sent, int dis) {
        vector<string> words;
        string thisWord;
        for(char &c:sent)
        {
            if(c==' ')
            {
                words.push_back(thisWord);
                thisWord = "";
                continue;
            }
            thisWord.push_back(c);
        }
        words.push_back(thisWord);//push the last word which has no space
        string ans;
        for(int i=0;i<words.size();i++)
        {
            double thisPrice;
            if(isPrice(words[i]))//if this word is price
            {
                thisPrice = stod(words[i].substr(1,words[i].size()-1));//convert the price into double value after removing $ character
                thisPrice = thisPrice - (dis/100.0)*thisPrice;//apply the discount
                string str = to_string(thisPrice);//convert the double value into string
                int strLen = str.length();
                
                //Since normally, the double number has 6 digits after decimal hence to round of upto two decimal places, we check the third
                //digit after decimal and then set second digit after decimal accordingly
                if(str[strLen-4]>'5' && str[strLen-5]!='9') str[strLen-5] = char(int(str[strLen-5])+1);
                str = str.substr(0,strLen-4);//drop of 4 character in last after decimal
                ans += "$" + str + " ";//append this price with preceding $ sign and space after
            }
            else//this is not a price word hence simply push it with a " "
            {
                ans += words[i] + " ";
            }
        }
        ans.pop_back();//pop the last extra " "
        return ans;
    }
};
