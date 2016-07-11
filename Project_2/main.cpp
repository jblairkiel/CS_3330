#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include "Media.h"


using namespace std;
/*! \file */
/** @brief The main function that runs the program.
 *
 */

int main(int argc, char* argv[]){

	
	srand(time(0));

	Media mTest = Media();	
	cout << mTest.getEntryID() + '\n';

	Media mTest2 = Media();
	cout << mTest2.getEntryID() +  '\n';

	Media mTest3 = Media();
	cout << mTest3.getEntryID() + '\n';


	return 0;
}
