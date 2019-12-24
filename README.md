All Projects that use C from CSC225, computer organization. Assignment 6 implements a stack data structure that 
allows the user to push and pop numbers onto the stack with underflow and overflow protection. The stack is then visualized in
the command line for the user. The user can then change the stack to display decimal numbers, hex, or ascii.
Assignment 7 was part of a larger project that involved creating a recursive function in assembly language for the LC-3.
There are two functions that we wrote recursively in C that were later translated to assembly. One that counts forwards from 1 
to a desired number, and the other which counts backwards from any number to one. Assignment 8 is my implementation of the built
in grep command for unix. This program takes in a file and a keyword that the user is looking for and then prints out a 
list of occurences of the word in the file. The output contains the longest line in the file, the number of occurrences of the 
word, every line that contains the word along with its position in the line. This program uses a linked list data structure. 
myGrep2.c and wordList2.c are the same program however it is implemented using a linked list of linked lists. It was implemented
this way in order to handle the case where the desired word occurs twice on a line. Using a linked list of linked lists data 
structure ensures the output can print every line of the file a maximum of one time. 
