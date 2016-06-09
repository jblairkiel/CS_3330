/**
 *	g.cpp - This progam implements the g() gunction 
 *         as described in the handout.
 *
 *           Blair Kiel	- CS 33330 XTIA 16/T5
 *            
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int g(int n);

int main(int argc, char **argv)
{
   cout << "g(-24) is " << g(-24) << endl;
   cout << "g(-9) is " << g(-9) << endl;
   cout << "g(-5) is " << g(-5) << endl;
   cout << "g(0) is " << g(0) << endl;
   cout << "g(6) is " << g(6) << endl;
   cout << "g(25) is " << g(25) << endl;
   cout << "g(32) is " << g(32) << endl;
   cout << "g(47) is " << g(47) << endl;

   cout << "\n** Press any key to continue **\n\n";
   getchar();

   return 0;
}

int g(int n)
{
	if(n > 0){
		return ( g(n-1) + ((3*n) -1) );
	}
	else if(n < 0){
		return ( g(-n-1) - (3*n) -1 );
	}
	else{
   		return 0;
	}
}
