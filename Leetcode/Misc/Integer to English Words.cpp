//Problem link - https://leetcode.com/problems/integer-to-english-words/

class Solution {
public:
    string getStringFromThreeDig(int n,unordered_map<int,string> &mp)
    {
        string ans = "";
        if(n/100 != 0)//For e.g., 123 give One Hundered
        {
            ans += mp[n/100] + mp[100];
            n = n%100;
        }
        if(n<20 && n>10)//If remaining number is 11<=num<=19 then just return that word for it
        {
            ans += mp[n];
            return ans;
        }
        if(n/10 != 0)//If some other number is remaining like 79 , it will give (79/10)*10 = 70 = Seventy and 9 will remain
        {
            ans += mp[(n/10)*10];
            n = n%10;
        }
        ans += mp[n];//If single digit is remaining, it will add its word. If 0 is remaining then it will add "" i.e., nothing
        return ans;
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";//Zero is dealt separately
        
    unordered_map<int,string> mp = {{1000000000, "Billion "}, {1000000, "Million "}, {1000, "Thousand "}, {100, "Hundred "},
    {90, "Ninety "},{80, "Eighty "},{70, "Seventy "},{60, "Sixty "}, 
    {50, "Fifty "}, {40, "Forty "}, {30, "Thirty "}, {20, "Twenty "},
    {19, "Nineteen "}, {18, "Eighteen "}, {17, "Seventeen "}, {16, "Sixteen "}, {15, "Fifteen "},
    {14, "Fourteen "}, {13, "Thirteen "}, {12, "Twelve "}, {11, "Eleven "}, {10, "Ten "},
    {9, "Nine "},{8, "Eight "},{7, "Seven "},{6, "Six "}, {5, "Five "}, {4, "Four "}, {3, "Three "}, {2, "Two "}, {1, "One "},{0,""}};
    
    vector<int> divPlace = {1000000000,1000000,1000,1};
    string ans = "";
    for(int i=0;i<4 && num;i++)
    {
        if(num/divPlace[i])
        {
            ans += getStringFromThreeDig(num/divPlace[i],mp);//Like for num=1000, it will get "One " and below line will add "thousand ";
            if(divPlace[i] != 1) ans += mp[divPlace[i]];//Except 1, all others have word values like 1000 has thousand
            num = num%divPlace[i];
        }
    }
    ans.pop_back();//Delete the last one extra space
    return ans;
    }
};
