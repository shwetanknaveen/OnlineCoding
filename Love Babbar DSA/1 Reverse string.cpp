//Problem link - https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

string reverseWord(string str){
    
  //Your code here
  int length = str.length();
  for(int i=0,j=length-1;i<j;i++,j--)//notice the condition i<j and not i!=j
  swap(str[i],str[j]);
  return str;
}
