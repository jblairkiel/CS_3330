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

	//Initialize random time seed	
	srand(time(0));
	string programFile = "media_list.dat";

	//Read in file


	bool sFlag = true;
	string uInput;
	cout << "Blair Kiel's Media Streaming Service\n";
	cout << "====================================\n";
	cout << "                                    \n";

	//Main Program Loop
	while(sFlag){
		
		cout << "1: Show all Media Items\n";
		cout << "2: Enter new Media Item\n";
		cout << "3: Delete Media Item (by Entry ID)\n";
		cout << "4: Search for Media Item (by Entry ID)\n";
		cout << "5: Edit Media Item (by Entry ID)\n";
		cout << "6: Exit Program (Saves Data then Exits)\n";
		cout << "Please enter a command (1-6):\n";
		getline(cin, uInput);
	
		if(uInput == "1"){

		}
		else if (uInput == "2"){

		}
		else if (uInput == "3"){

		}
		else if (uInput == "4"){

		}
		else if (uInput == "5"){

		}
		else if (uInput == "6"){
			saveFile();
			sFlag = false;
		}
		else{
			cout << "Please enter a valid input!"
		}
		
	}

	return 0;
}


void saveFile(){
	
	ofstream 

}
