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
