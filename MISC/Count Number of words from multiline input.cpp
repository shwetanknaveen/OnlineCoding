//CDAC IDE link - http://parikshak.in/demo.html
/*
Count number of words from a multi line input
Example ->

Input = 
this is sample input
next line

Output = 
6
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    string inp;
    char *word;
    int count = 0;
    
    char delimeter[] = " \n\t\r";//note we have space " " also here as delimeter
    do
    {
        getline(cin,inp);
        word = strtok((char *)inp.c_str(),delimeter);
        /*
        The strtok() function in C++ returns the next token in a C-string (null terminated byte string).
		"Tokens" are smaller chunks of the string that are separated by a specified character, called the delimiting 
		character.
		strtok(char* str, const char* delim);
		str - the string from which we want to get the tokens
		delim - the delimiting character i.e. the character that separates the tokens
		
		The basic_string::c_str() is a builtin function in C++ which returns a pointer to an array that contains a 
		null-terminated sequence of characters representing the current value of the basic_string object. This array includes
		the same sequence of characters that make up the value of the basic_string object plus an additional terminating 
		null-character at the end.
        */
        while(word!=NULL)
        {
            cout<<word<<endl;
            ++count;
            word = strtok(NULL,delimeter);
        /*
        strtok is part of the C library and what it does is splitting a C null-delimited string into tokens separated by any 
		delimiter you specify. The first call to strtok must pass the C string to tokenize, and subsequent calls must specify
		 NULL as the first argument, which tells the function to continue tokenizing the string you passed in first.
        */
        }
        
    }while(inp!="");
    cout<<"\nans = "<<count;
    return 0;
}

