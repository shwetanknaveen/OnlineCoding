/*
Given a snippet of text containing alphabets, numbers and punctuation, you have to write a C/C++/JAVA programs to find out
whether any of english alphabets are missing in the paragraph.

Input - List of words separated by space/tab/newlines , Input is terminated as word “endpara”, 
Note: Assume that endpara will never be the part of snippet.

Output - 
Print the missing Alphabets in the paragraph in the ascending order in CAPITAL separated by space. 
If none of the alphabet is missing, print “NONE”.

Sample I/O - 
Input
The quick brown fox jumps over a lazy dog. endpara

Output
NONE
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string word = "";
	char c;
	vector<int> missing(26,0);
	while(1)
	{
		c = getchar();
		if(c == ' ' || c == '\t' || c== '\n')//delimeter
		{
			for(int i=0;i<word.length();i++)//mark all characters found in the last word
			{
				if(toupper(word[i])>='A' && toupper(word[i])<='Z')
				{
					missing[toupper(word[i]) - 'A'] = 1;
				}
				word = "";//get ready for the new word
			}
		}
		else//not delimeter
		{
			word.push_back(c);
			if(word.compare("endpara")==0)
				break;
		}
	}
	string ans = "";
	for(int i=0;i<26;i++)
	{
		if(missing[i] == 0)//this character wasn't in input
		{
			ans.push_back(char(i+'A'));
		}
	}
	
	for(int i=0;i<ans.length();i++)
	{
		cout<<ans[i];
		if(i != ans.length()-1)
			cout<<" ";
	}
	if(ans.empty())
		cout<<"NONE";
	return 0;
}
