/**
 * Stack.cpp - This file uses the C++ STL stack API and implements 
 *             a helper function called reverseStack that will 
 *             reverse a given stack.
 *
 * TODO: Include your name and course number here.
 * 	Blair Kiel	
 * 	CS 3330XTIA / T5
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

template <class Object>
void printStack(stack<Object> myStack);

template <class Object>
void reverseStack(stack<Object> &myStack);

int main()
{
   stack<string> myStack;

   myStack.push("423");
   myStack.push("-");
   myStack.push("462");
   myStack.push("*");
   myStack.push("457");
   myStack.push("-");
   myStack.push("259");
   myStack.push("+");
   myStack.push("346");
   myStack.push("*");
   myStack.push("582");

   cout << "The contents of myStack:" << endl;
   printStack(myStack);

   cout << "The reverseStack of myStack:" << endl;
   reverseStack(myStack);
   printStack(myStack);

   cout << "** Press any key to continue **";
   getchar();

   return 0;
} 

template <class Object>
void printStack(stack<Object> myStack)
{
   while (!myStack.empty())
   {
      // Print the top item that is on the stack
      cout << " " << myStack.top() << endl; 

      // Pop the item off of the stack
      myStack.pop();
   }

   cout << endl;

   return;
}

template <class Object>
void reverseStack(stack<Object> &myStack)
{
   // TODO: Implement the details for the reverseStack 
   // function.
  

   stack<string> tempStack;
   string tempString = "";

   while(!myStack.empty()){

      tempString = myStack.top();
      myStack.pop();
      tempStack.push(tempString);
   }

   myStack = tempStack;
   return;
}

