#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <list>
#include "Media.h"


using namespace std;
/*! \file */
/** @brief The main function that runs the program.
 *
 */



void saveFile(string fileName, list<Media> mList){
	
	ofstream oFile;
	oFile.open(fileName);
	
	list<Media>::iterator it;
	for (it = mList.begin(); it != mList.end(); it++){
	
		Media item = (*it);
		oFile << item.asString();
	}
	oFile.close();
	return;

}

list<Media> readInFile(string fileName, list<Media> mList){

	string line;
	int pCount = 0;
	double tempDub;
	float tempFloat;
	Media newItem = Media();

	ifstream inFile; 
	inFile.open("media_list.dat");
	
	if(inFile.is_open()){
		while(getline(inFile,line)){

			int point = 0;
			string str;
			
			while(line[point] != ','){
				str += line[point];
				point++;
			}

			Media newItem = Media();
			newItem.setEntryID(str);
			str = "";
			point++;

			while (line[point] != ','){
				str += line[point];
				point++;
			}
//			cout << str + '\n';

			point++;
			newItem.setProductType(str);
			str = "";

			while (line[point] != ','){
				str += line[point];
				point++;
			}

			newItem.setTitle(str);
			str = "";
			point++;

			while (line[point] != ','){
				str += line[point];
				point++;
			}

			newItem.setDescription(str);
			str = "";
			point++;

			while (line[point] != ','){
				str += line[point];
				point++;
			}

			newItem.setDurationTime(str);	
			str = "";
			point++;

			while (line[point] != ','){
				str += line[point];
				point++;
			}

			tempDub = atof(str.c_str());
			tempFloat = (float) tempDub;	
			newItem.setRentalPrice(tempFloat);
			str = "";
			point++;

			while (line[point] != ','){
				str += line[point];
				point++;
			}

			newItem.setDateAvailable(str);
			str = "";
			point++;

			while(line[point] != ';'){
				str += line[point];
				point++;
			}
			newItem.setDaysAvailable(str);	
			cout << newItem.asString();
			mList.push_front(newItem);
			str = "";
			line = "";
			
		}
		inFile.close();
	}
	return mList;
}

int main(int argc, char* argv[]){

	//Initialize random time seed	
	srand(time(0));
	string programFile = "media_list.dat";
	list<Media> mediaManager;

	//Read in file
	mediaManager = readInFile(programFile, mediaManager);


	bool sFlag = true;
	string uInput;
	cout << "Blair Kiel's Media Streaming Service\n";
	cout << "====================================\n";
	cout << "                                    \n";

	//Main Program Loop
	while(sFlag){
		
		cout << "\n";
		cout << "1: Show all Media Items\n";
		cout << "2: Enter new Media Item\n";
		cout << "3: Delete Media Item (by Entry ID)\n";
		cout << "4: Search for Media Item (by Entry ID)\n";
		cout << "5: Edit Media Item (by Entry ID)\n";
		cout << "6: Exit Program (Saves Data then Exits)\n";
		cout << "Please enter a command (1-6):\n";
		getline(cin, uInput);
	
		//Display all available entries
		if(uInput == "1"){
				
			list<Media>::iterator it;
			for (it = mediaManager.begin(); it != mediaManager.end(); it++){
		
				Media item = (*it);
				cout << item.asString() + '\n';
			}	

		}
		//Create new entry
		else if (uInput == "2"){
	
			string temp;
			double tempDub;
			float tempFloat;

			Media newItem = Media();
			newItem.generateEntryID();
			
			cout << "\nProduct Type: ";
			getline(cin, temp);
			newItem.setProductType(temp);
		
			cout << "\nMedia Title: ";
			getline(cin, temp);
			newItem.setTitle(temp);

			cout << "\nMedia Description: ";
			getline(cin, temp);	
			newItem.setDescription(temp);
	
			cout << "\nMedia Duration Time: ";
			getline(cin, temp);
			newItem.setDurationTime(temp);

			cout << "\nMedia Rental Price: ";
			getline(cin, temp);
			tempDub = atof(temp.c_str());
			tempFloat = (float) tempDub;	
			newItem.setRentalPrice(tempFloat);

			cout << "\nMedia Date Available: ";
			getline(cin, temp);
			newItem.setDateAvailable(temp);
			
			cout << "\nMedia Days Available: ";
			getline(cin, temp);
			newItem.setDaysAvailable(temp);
	
			mediaManager.push_front(newItem);

		}
		else if (uInput == "3"){

		}
		else if (uInput == "4"){

		}
		else if (uInput == "5"){

		}
		else if (uInput == "6"){
			saveFile(programFile, mediaManager);
			sFlag = false;
			break;
		}
		else{
			cout << "Please enter a valid input!";
		}
		
	}

	return 0;
}

