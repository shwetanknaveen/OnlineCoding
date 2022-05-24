/*
Problem
A company named Gooli has issued a new policy that their employees account passwords must contain:

At least 7 characters.
At least one uppercase English alphabet letter.
At least one lowercase English alphabet letter.
At least one digit.
At least one special character. There are four special characters: #, @, *, and &.
The company has asked all the employees to change their passwords if the above requirements are not satisfied. Charles, an employee at Gooli,
really likes his old password. In case his old password does not satisfy the above requirements, Charles will fix it by appending letters, 
digits, and special characters. Can you help Charles to find the shortest possible new password that satisfies his company's requirements?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of two lines. The first line of 
each test case contains an integer N, denoting the length of the old password. The second line of each test case contains the old password 
of length N. Old password contains only digits, letters, and special characters.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is a valid new password, 
obtained by possibly fixing the old password in the way that Charles wants and satisfying the company's requirements.

It is guaranteed that at least one solution exists. If there are multiple solutions, you may output any one of them.

Limits
Time limit: 20 seconds.
Memory limit: 1 GB.
1=T=100.
Test Set 1
7=N=104.
The old password contains only digits.

Test Set 2
1=N=104.
The old password contains only digits, letters, and special characters.

Sample Input
2
7
1234567
10
1111234567

Sample Output
Case #1: 1234567aA&
Case #2: 1111234567@Rc
*/

#include<bits/stdc++.h>
using namespace std;
void fixUpCase(string &s)
{
	s.push_back('A');
}
void fixDownCase(string &s)
{
	s.push_back('a');
}
void fixDigit(string &s)
{
	s.push_back('1');
}
void fixSpecChar(string &s)
{
	s.push_back('@');
}
void fixSevChar(string &s)
{
	while(s.length()<7)
		s.push_back('1');
}
int main()
{
    int n;
    cin>>n;
    vector<string> inp;
    int temp = n;
    while(temp--)
    {
        int len;
        cin>>len;
        char c;
        string s;
        while(len--)
        {
        	cin>>c;
        	s.push_back(c);
		}
		inp.push_back(s);
    }
    for(int i=0;i<n;i++)
    {
        bool upCase,downCase,dig,specChar;
        upCase=downCase=dig=specChar=false;
        
        for(char c:inp[i])
        {
        	if(c>='a' && c<='z') downCase = true;
        	if(c>='A' && c<='Z') upCase = true;
        	if(c>='0' && c<='9') dig = true;
        	if(c=='#' ||c=='@' ||c=='*' ||c=='&') specChar = true;
		}
		if(!upCase) fixUpCase(inp[i]);
		if(!downCase) fixDownCase(inp[i]);
		if(!dig) fixDigit(inp[i]);
		if(!specChar) fixSpecChar(inp[i]);
		if(inp[i].length()<7) fixSevChar(inp[i]);
		cout<<"Case #"<<i+1<<": "<<inp[i];
		if(i!=n-1) cout<<"\n";
    }
    return 0;
}
