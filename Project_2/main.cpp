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
 */

/** @brief Edits the entry item by the give entryID
 *
 */
list<Media> editMediaEntry(string entryID, list<Media> mList){

	if(mList.size() != 0){
		string temp;
		double tempDub;
		float tempFloat;
		list<Media>::iterator it;
		for (it = mList.begin(); it != mList.end(); it++){

			Media item = (*it);
			if(entryID.compare(item.getEntryID()) == 0){
				cout << "Editing Media Entry:\n";
				cout << item.asString() + "\n\n";

				//Editing Fields
				cout << "\nNew 'Product Type': ";
				getline(cin, temp);
				item.setProductType(temp);

				cout << "\nNew 'Media Title': ";
				getline(cin, temp);
				item.setTitle(temp);

				cout << "\nNew 'Media Description': ";
				getline(cin, temp);
				item.setDescription(temp);

				cout << "\nNew 'Media Duration Time': ";
				getline(cin, temp);
				item.setDurationTime(temp);

				cout << "\nNew 'Media Rental Price': ";
				getline(cin, temp);
				tempDub = atof(temp.c_str());
				tempFloat = (float) tempDub;
				item.setRentalPrice(tempFloat);

				cout << "\nNew 'Media Date Available': ";
				getline(cin, temp);
				item.setDateAvailable(temp);

				cout << "\nNew 'Media Days Available': ";
				getline(cin, temp);
				item.setDaysAvailable(temp);

				return mList;
			}
		}
		cout << "No Media with EntryID:'" + entryID + "' exists in the List\n";
	}
	else{
		cout << "The List is empty!\n";
	}
	return mList;
}


list<Media> deleteMediaEntry(string entryID, list<Media> mList){

	
	if(mList.size() != 0){
		list<Media> tempManager;
		list<Media>::iterator it;
		bool foundFlag = false;
		for (it = mList.begin(); it != mList.end(); it++){

			Media item = (*it);
			if(entryID.compare(item.getEntryID()) == 0){
				cout << "Deleted Media Entry:\n";
				cout << item.asString() + "\n";
				foundFlag = true;
			}
			else{
				tempManager.push_front(item);
			}
		}
		if(!foundFlag){
			cout << "No Media with EntryID:'" + entryID + "' exists in the List\n";
		}
		return tempManager;
	}
	else{
		cout << "The List is empty!\n";
	}
	return mList;

}

void searchForMedia(string entryID, list<Media> mList){

	if(mList.size() != 0){
		list<Media>::iterator it;
		for (it = mList.begin(); it != mList.end(); it++){

			Media item = (*it);
			if(entryID.compare(item.getEntryID()) == 0){
				cout << "Found Media Entry:\n";
				cout << item.asString() + "\n";
				return;
			}
		}
		cout << "No Media with EntryID:'" + entryID + "' exists in the List\n";
	}
	else{
		cout << "The List is empty!\n";
	}
	return;

}

list<Media> newMediaEntry(list<Media> mList){
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

	mList.push_front(newItem);
	return mList;
}


void saveFile(string fileName, list<Media> mList){

	ofstream oFile;
	oFile.open(fileName);

	if(mList.size() != 0){
		list<Media>::iterator it;
		for (it = mList.begin(); it != mList.end(); it++){

			Media item = (*it);
			oFile << item.asString() + "\n";
		}
		oFile.close();
	}
	else{
		cout << "The List is empty!\n";
	}
	return;

}

list<Media> readInFile(string fileName, list<Media> mList){

	string line = "";
	double tempDub;
	Media newItem = Media();

	ifstream inFile;
	inFile.open(fileName);

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
			//cout << str + '\n';

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
			newItem.setRentalPrice(tempDub);
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
			//cout << newItem.asString();
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
	string programFile = "test.dat";
	list<Media> mediaManager;

	//Read in file
	mediaManager = readInFile(programFile, mediaManager);


	bool sFlag = true;
	string entryID;
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
            		if (mediaManager.size() != 0){
                		list<Media>::iterator it;
                		for (it = mediaManager.begin(); it != mediaManager.end(); it++){
                    			Media item = (*it);
                    			cout << item.asString() + '\n';
                		}
           		} 
            		else{
				cout << "The List Is Empty!\n";
		    	}
		}

		//Create new entry
		else if (uInput == "2"){

			mediaManager = newMediaEntry(mediaManager);
		}

		//Delete existing entry
		else if (uInput == "3"){
			cout << "Entry ID to delete: ";
			getline(cin, entryID);
			mediaManager = deleteMediaEntry(entryID, mediaManager);
		}

		//Search for Media entry
		else if (uInput == "4"){

			cout << "Entry ID to search for: ";
			getline(cin, entryID);
			searchForMedia(entryID, mediaManager);
		}

		//Edit Media Item
		else if (uInput == "5"){
			cout << "Entry ID to edit: ";
			getline(cin, entryID);
			mediaManager = editMediaEntry(entryID, mediaManager);
		}
		
		//Exit and Save Program
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

