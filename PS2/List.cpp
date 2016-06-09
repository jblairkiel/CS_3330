/**
 * List.cpp - This file uses the C++ STL list API and implements a 
 *            predicate function called isInList that will determine
 *            if a given element is in a given list.
 *
 * TODO: Include your name and course number here.
 * 	Blair Kiel
 * 	CS 3330XTIA / T5
 */

#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

template <class Object>
void printList(list<Object> myList);

template <class Object>
bool isInList(Object element, list<Object> myList);

int main()
{
   list<int> myList;

   myList.push_back(282);
   myList.push_back(471);
   myList.push_back(786);
   myList.push_back(277);
   myList.push_back(646);
   myList.push_back(832);
   myList.push_back(571);
   myList.push_back(792);
   myList.push_back(567);
   myList.push_back(348);

   cout << "myList:" << endl;
   printList(myList);

   cout << "172 is in list (0=false, 1=true): " << isInList(172, myList) << endl;
   cout << "178 is in list (0=false, 1=true): " << isInList(178, myList) << endl;
   cout << "282 is in list (0=false, 1=true): " << isInList(282, myList) << endl;
   cout << "471 is in list (0=false, 1=true): " << isInList(471, myList) << endl;
   cout << "571 is in list (0=false, 1=true): " << isInList(571, myList) << endl;
   cout << "775 is in list (0=false, 1=true): " << isInList(775, myList) << endl;

   cout << "\n** Press any key to continue **\n";
   getchar();

   return 0;
} 

template <class Object>
void printList(list<Object> myList)
{
   // Use an iterator to walk the list. Print the value of 
   // for each node.
   typename list<Object>::iterator node;
   for (node = myList.begin(); node != myList.end(); ++node)
   {
      // Get the contents of each node
      Object value = (*node);   

      // Print the value of the node
      cout << " " << value; 
   }

   cout << endl << endl;

   return;
}

template <class Object>
bool isInList(Object element, list<Object> myList)
{
   bool found = false;

   // Use an iterator to walk through the list: mylist
   // as done in the printList() method. If value 
   // equals element then return true or set the found 
   // vairable equal to true and break out of the loop.

   typename list<Object>::iterator node;
   for (node = myList.begin(); node != myList.end(); ++node)
   {
	Object value = (*node);

	if(value == element){
	   found = true;
        }
   }	

   return found;
}

