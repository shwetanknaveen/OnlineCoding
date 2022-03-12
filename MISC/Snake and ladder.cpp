/*
Snakes and ladders is a very popular game. It's a 10x10 maze, with cells numbered from 0 to 99, and filled with snakes and 
ladders, as shown below in the figures. Every player gets a chance to play and advance in the maze, depending on the number 
they get on the dice when thrown.

The advancement is in the increasing order from 0 to 99. All players start from cell numbered 0 (zero) and attempt to reach to 
cell numbered 99. The player who reaches first to cell number 99, is the winner. If the game is stopped in between, the player 
closest to cell 99 in number is the winner. Assume that both players will never be on the same cell when the game is stopped.

If a player after tossing the dice lands on a cell, where the snake opens it's mouth, then the player gets a penalty to 
retreat to the tail of the snake. While, if the player reaches the foot of a ladder, then the player climbs directly to the 
top of the ladder. In the example figure here, the snake has its mouth on cell 96 and its tail on cell 13, while the ladder 
has foot on cell 26 while its top is on cell 87.

If there is another snake (or ladder) waiting at the tail of a snake, a player slide down (or climb up) that second snake 
(or ladder), and so on as required. A cell will never have a mouth of a snake and a foot of a ladder simultaneously.

As such, the snake and ladder are similar, in that when a player lands on a particular cell, they transport the player to 
another cell. Except for the fact that, snake take a player away from finishing line, while ladder takes a player closer.
Write a program to simulate the game. There will be two players, named A and B, who toss the dice alternately. The program 
should output the name of the player at the highest position (closest to 99), along with the player's cell number.

Input - 
The first line of input will contain a single integer N, stating the number of snakes and ladders.
Next N lines each will contain a pair of integers. Each pair will describe either a snake or ladder by its start cell and an 
end cell. For example, for a snake, start cell will be higher than end cell. Refer to the first sample input case which 
describes the board in the figure above.
Following line of input has a single integer D, indicating the number of moves (dice throws) made by both players A and B.
Last line contains D integers, each indicating a dice throw, alternately made by A and B. First throw is made by player A. 
Each dice throw is an integer between 1 to 6.

Output - 
Your program should output the name of the winner (A or B) followed by the players position
at the end of game, with a single space in between.

Sample I/O - 
Input:
2
26 87
96 13
18
4 1 3 2 6 3 6 3 2 4 4 2 1 1 5 2 4 6


Output:
B 24

 

Input:
3
13 98
98 0
6 13
10
5 1 3 3 1 1 4 1 6 1


Output:
B 1



*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,val;
	cin>>n;
	int start,end;
	map<int,int> snake,ladder;
	while(n--)
	{
		cin>>start>>end;
		if(start>end)
		{
			snake[start] = end;
		}
		else
		{
			ladder[start] = end;
		}
	}
	vector<int> moves;
	cin>>n;
	while(n--)
	{
		cin>>val;
		moves.push_back(val);
	}
	bool aChance = true;
	int aFinal = 0, bFinal = 0;
	string winner = "";
	for(int i=0;i<moves.size();i++)
	{
		if(aChance)
		{
			aFinal += moves[i];
			bool changeFlag = true;
			while(changeFlag)//after taking ladder or bitten by snake, there is again same possibity for ladder/snake from new position
			{
				if(snake.find(aFinal) != snake.end())
				{
					aFinal = snake[aFinal];
					changeFlag = true;
				}
				else if(ladder.find(aFinal) != ladder.end())
				{
					aFinal = ladder[aFinal];
					changeFlag = true;
				}
				else
				{
					changeFlag = false;
				}
			}
			if(aFinal >= 99)
			{
				winner = "A 99";
				break;
			}
		}
		else
		{
			bFinal += moves[i];
			bool changeFlag = true;
			while(changeFlag)
			{
				if(snake.find(bFinal) != snake.end())
				{
					bFinal = snake[bFinal];
					changeFlag = true;
				}
				else if(ladder.find(bFinal) != ladder.end())
				{
					bFinal = ladder[bFinal];
					changeFlag = true;
				}
				else
				{
					changeFlag = false;
				}
			}
			if(bFinal >= 99)
			{
				winner = "B 99";
				break;
			}
		}
		aChance = !aChance;
	}
	if(!winner.empty())//One of them have reaced 99
		cout<<winner;
	else//None of them reached 99
	{
		if(aFinal>bFinal)
			cout<<"A "<<aFinal;
		else
			cout<<"B "<<bFinal;
	}
	return 0;
}
