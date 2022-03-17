/*
You are given a list of movies and ratings (out of 5) by different viewers and need to find out the most popular movie based on 
the ratings. Write a C/C++/Java program to find out the movie that has the maximum rating sum. 

Input - 
Input Specification:  

Each line will contain the name of the movie and rating, separated by ‘#’ 

The input will be terminated by “THE END”.

Output - 
Output Specification: 

Print the name and rating sum of the movie which have the highest rating sum. 
If two movies have same highest rating sum, print the movie which comes first in dictionary order .

Sample Input/Output 

Input

URI # 5

Gully Boy # 5

Badla # 5

Kabir Singh # 5

THE END

Output

Badla 5
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
	//sorted map will contain movie name in lexicographically order as key is string
	map<string,int> ratings;
	string inp;
	int rat;
	string movie;
	while(getline(cin>>ws,inp))// cin>>ws means takes white spaces also
	{
		if(inp == "THE END")
			break;
		stringstream s(inp);
		getline(s,movie,'#');
		s>>rat;
		ratings[string(movie)] += rat;
	}
	int maxiRat = 0;
	string movName;
	map<string,int>::iterator itr;
	for(itr = ratings.begin();itr != ratings.end(); itr++)
	{
		if(itr->second > maxiRat)
		{
			maxiRat = itr->second;
			movName = itr->first;
		}
	}
	cout<<movName<<" "<<maxiRat;
	return 0;
}
