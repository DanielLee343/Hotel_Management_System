# Summary of Project

### This program's goal is to create a system that simulate how a hotel system works using C language. 



**Administers are able to:**

·View hotel's information

·View information for every individual room

·View information for every individual customer

·View customers' information

·Register for check in

·Request for changing a room

·Register for check out

·View main menu



**We use a typedef data structure to store the information of customers and rooms.**



**Essential algorithm:**

·We use a type of integer 'currentCount' to store the number of rooms being registered. If and only if currentCount <= # of max room are we able to let new customer check in.

·Imply the use of Message Tree Mechanism like 'flag' and 'index' to control the program properly.



**UI design:**

The program is based on CMD terminal so we are not supposed to create any user interface for it. However, considering for the operating experience of a administer, I did some improvement.

·Add some '*' to split up functions shown on CMD.

·Use a loading progress bar to simulate the actual environment.

·Use the function getch() and clear the screen after every operation.



**Problems and solution:**

1.P(Problem):

When I finished the first coding work, in most situation, I could not modify the elements in data structure properly, nor could I copy the right data into file and store it finely. This was because of some logical mistakes. 

S(Solution):

For example, if I want to find every item that could match in the database, 'break' cannot be added inside the loop, or it will get out of the loop when the program find the very first item that could match.



2.P:

In the operation of counting, I always encounter the situation that there are several middle brackets nesting with each other, which made it harder to distinguish every bracket properly.

S:

Imply other variable to stand for a complex variable, e.g. instead of int x = a[b[c]]; we use e = b[c]; x = a[e] to make things clearer and readable.



3.P:

I did not open the file at the beginning of the program but instead, open and close the file inside every function, which result in a high usage of CPU.

S:

Open the file at the beginning of the program and close it when the administer choose the shut down the program.



**Things I learned from the project:**

Frankly speaking, this is the very first individual project after I went into university and somehow stands for a break through towards official programming field. When I first got the handout, I was nervous and at a loss. My first 12 hours for this project was in vain because I knew nothing to do about it. So later I asked my cousin for help, he told me to write down what I could think about step by step and then try to figure out how to implement it. Although I encountered many problems during the process of coding and testing, I overcame them all through the help of my teacher and my cousin and of course, mainly through the endeavor of mine.



After the project, I found out the experience that only after I get the overall picture of the program shall I begin to code. And also, try to do debugging very often. There is no way to finish any program without a single bug inside it and we cannot wait for bugs to accumulate, e.g. test the program after writing several lines and see if it runs well.