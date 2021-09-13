//Question link- https://www.hackerrank.com/contests/iiit-bangalore-1/challenges/caesar-cipher-1/problem
//Seniors coding test 1 question
/*
Julius Caesar protected his confidential information by encrypting it using a cipher. Caesar's cipher shifts each letter by a number of letters. If the shift takes you past the end of the alphabet, just rotate back to the front of the alphabet. In the case of a rotation by 3, w, x, y and z would map to z, a, b and c.

Original alphabet:      abcdefghijklmnopqrstuvwxyz
Alphabet rotated +3:    defghijklmnopqrstuvwxyzabc
*/
#include<bits/stdc++.h>
using namespace std;

string caesarCipher(string s, int k) {
    int size = s.length();
    int a = int('a');
    int A = int('A');
    //int() returns the ASCII value of the character
    //char() gives the character value at the given ASCII
    for(int i=0;i<size;i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i] <='Z'))//check if the digit is alphabet
        {
        	if(s[i]>='a' && s[i]<='z')
        	s[i] = char((int(s[i]) - a + k)%26+a);//int(s[i]) - a tells that which alphabet it is then we add k and take %26 then convert again to char after adding 'a' ASCII value because it should be an alphabet
        	else
        	s[i] = char((int(s[i]) - A + k)%26+A);//int(s[i]) - A tells that which alphabet it is then we add k and take %26 then convert again to char after adding 'A' ASCII value because it should be an alphabet
        
    	}
    }
    return s;
}

int main()
{
	string s;
	cin>>s;
	cout<<caesarCipher(s,3);
	
	return 0;
}
