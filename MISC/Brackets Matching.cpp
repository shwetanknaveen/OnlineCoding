/*
Brackets are tall punctuation marks used in matched pairs within text, to set apart or interject other text. Brackets refer 
to different types of brackets in different parts of the world and in different contexts.

Write a program which reads a String, which consists of alphabets [a-z, A-Z] and 3 types of brackets listed below:

Parentheses - ()

Square brackets - []

Braces or Curly brackets - {}

And determine whether every open bracket has a matching close bracket. If any open/close bracket doesn’t have a matching 
close/open bracket or any extra open/close bracket then it is to be treated as invalid string.

Following are 3 examples of valid string:

(the[is]{valid})

{the(is[valid])}

(this)(is)(valid)

Following are 4 examples of invalid string:

(the[is]{invalid))

(the[is]{invalid}}

(this](is}{invalid)

[this]{is}(invalid))



Input - 
First line of the input consists of an integer N, followed by N number of strings with each string is on a separate line.

Output - 
mage
For each input string, print “MISSMATCH” if the nesting of brackets are not matching.  "TOO MANY OPENING"  if more opening 
brackets then the closing. "TOO MANY CLOSING" if more closing brackets than the opening brackets.  Else if everything is fine
print "VALID". Finally terminated by newline charater. 

Sample I/O - 

Sample Input:

4

(the[is]{valid})

(the[is]{valid))

{the(is[valid])}

(this](is}{valid)

Sample Output:

VALID

MISSMATCH

VALID

MISSMATCH


*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cin.ignore(1,'\n');//ignore one character->"\n" was taken as first string input
	/*
	https://stackoverflow.com/a/35179922

	Ignore function is used to skip(discard/throw away) characters in the input stream. Ignore file is associated with the 
	file istream. Consider the function below ex: cin.ignore(120,'/n'); the particular function skips the next 120 input 
	character or to skip the characters until a newline character is read.
	*/
	
	string s;
	while(n--)
	{
		getline(cin,s);
		stack<char> stac;
		int val = 0;//0->Valid 1->Missmatch 2->Too many opening 3->Too many closing
		for(int i=0;i<s.length();i++)
		{
			if(s[i] == '(' || s[i] == '{' s[i] == '[' )
				stac.push(s[i]);
			else if(s[i] == ')')
			{
				if(stac.empty())
				{
					val = 3;
					break;
				}
				else
				{
					if(stac.top() == '(')
						stac.pop();
					else
					{
						val = 1;//MISSMATCH
						break;
					}
				}
			}
			else if(s[i] == '}')
			{
				if(stac.empty())
				{
					val = 3;
					break;
				}
				else
				{
					if(stac.top() == '{')
						stac.pop();
					else
					{
						val = 1;//MISSMATCH
						break;
					}
				}
			}
			else if(s[i] == ']')
			{
				if(stac.empty())
				{
					val = 3;
					break;
				}
				else
				{
					if(stac.top() == '[')
						stac.pop();
					else
					{
						val = 1;//MISSMATCH
						break;
					}
				}
			}
			
		}
		if(!stac.empty() && val==0)
			val = 2;//Too many opening as opening brackets are still on stack and there is no violation yet i.e., still val = 0
			
		if(val == 0)
			cout<<"VALID";
		else if(val == 1)
			cout<<"MISMATCH";
		else if(val == 2)
			cout<<"TOO MANY OPENING";
		else if(val == 3)
			cout<<"TOO MANY CLOSING";
			
		if(n != 0)
			cout<<"\n";
	}
	return 0;
}
