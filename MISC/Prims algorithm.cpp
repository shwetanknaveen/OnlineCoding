/*
Consider a university having a very big campus spread in acres of land. The university is undergoing computerization. All the 
departments (at-most 50) are to be connected to form the intranet of the university. You have to write a program, implementing 
Prims algorithm, which will suggest the network topology and also minimise the total length of cable for connecting all the 
departments. Input to the program will be names of all the departments and straight line distances between the departments 
(Only those pairs of departments between which cable can be laid will be given). Output of the program should be the minimum 
length of the cable required.

Input - 
The first line will contain 2 natural numbers, N and M, separated by a blank space. N indicated the number of departments in 
the university and M indicates the number of pairs of departments where the cables can be laid. The following M lines will 
specify the distances between M pairs of departments as dept1 dept2 distance
Where dept1 and dept2 are names of the departments (maximum 20 characters) and distance is a positive integer (>0). Assume that
the given distances between each pairs of departments will be unique and these M lines will contain atleast one pair for each 
department.

Output - 
The first line of the output will be names of the departments as they are included in the solution separated by blank space. 
If two or more departments are included at a time then their names should be printed in the alphabetic order. The next line 
will be the minimum length of cable required to form the intranet, terminated with a new line character.

Sample I/O - 
Input

7 10

physics chemistry 8

biology physics 9

biology office 15

chemistry office 4

chemistry sanskrit 5

sanskrit office 7

english office 16

english sanskrit 19

english cs 12

sanskrit cs 6

Output

chemistry office sanskrit cs physics biology english

44

 

 
*/
