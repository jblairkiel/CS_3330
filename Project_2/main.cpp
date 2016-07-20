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

string toDollar(float fPrice){

	string tempPrice;
        string sPrice = to_string(fPrice);
        int counter1 = 0;
        tempPrice += '$';
        while (true){
                if(sPrice[counter1] == '.'){
                        tempPrice += '.';
                        counter1++;
                        for(int i = 0; i < 2; i++){
                                tempPrice += sPrice[counter1+i];
                        }
                        return tempPrice;
                }
                tempPrice += sPrice[counter1];
                counter1++;
        }
}
//Check if a list contains an element
bool listContains(list<string> pList, string sWord){
	
	list<string>::iterator it;
	bool foundFlag = false;
	for (it = pList.begin(); it != pList.end(); it++){

		string item = (*it);
		if(sWord.compare(item) == 0){
			return true;
		}
	}
	return false;
}

/** @brief Verifies that a given ID is valid by not already being used
*
*/
bool validID(string sID, list<Media> mList){

	if(mList.size() != 0){
		list<Media> tempManager;
		list<Media>::iterator it;
		for (it = mList.begin(); it != mList.end(); it++){

			Media item = (*it);
			if(sID.compare(item.getEntryID()) == 0){
				return false;
			}
		}
		return false;
	}
	else{
		return true;	
	}
}

/** @brief Verifies a string is in the correct price format for two decimal cents
*
*/
bool validPrice(string iString){

	int point = 0;
	string price;

	try{
		while(iString[point] != '.'){
			if(!isdigit(iString[point])){
				return false;
			}
			price += iString[point];
			point++;	
		}

		//Check Year
		for(int i = 0; i < 2; i++){
			price += iString[point];
			point++;
		}

		if(point != iString.length()){
			return false;	
		}

		return true;


	}
	catch (exception& e){
		return false;	
	}
}

/** @brief Verifies a string is in the correct Date format 'mm/dd/yyyy'
*
*/
bool validDate(string iString){

	int point = 0;
	string month;
	string day;
	string year;

	try{

		//Check Month
		for (point; point < 2; point++){
			month += iString[point];
		}

		if( (12 < stoi(month)) || (0 > stoi(month))){
			return false;
		}
		
		//Check for '/'
		if(iString[point] != '/'){
			return false;
		}
		point++;

		//Check Day
		for (point; point < 5; point++){
			day += iString[point];
		}

		if( (31 < stoi(day)) || (0 > stoi(day))){
			return false;
		}
	
		//Check for '/'
		if(iString[point] != '/'){
			return false;
		}
		point++;

		//Check Year
		for (point; point < 10; point++){
			year+= iString[point];
		}
		if( (0 > stoi(year)) || (9999 < stoi(year))){
			return false;
		}

		//Check length
		if(iString.length() != 10){
			return false;
		}
		return true;

	}
	catch (exception& e){
		return false;	
	}
}

/** @brief Verifies a string is in the correct time format 'hh:mm:ss'
*
*/
bool validTime(string iString){

	int point = 0;
	string hours;
	string minutes;
	string seconds;

	try{

		//Check Hours
		for (point; point < 2; point++){
			hours += iString[point];
		}

		if( (12 < stoi(hours)) || (0 > stoi(hours))){
			return false;
		}
	
		//Check for ':'
		if(iString[point] != ':'){
			return false;
		}
		point++;	

		//Check Minutes	
		for (point; point < 5; point++){
			minutes += iString[point];
		}

		if( (60 < stoi(minutes)) || (0 > stoi(minutes))){
			return false;
		}

		//Check for ':'
		if(iString[point] != ':'){
			return false;
		}
		point++;

		//Check Seconds
		for (point; point < 8; point++){
			seconds+= iString[point];
		}

		if( (60 < stoi(seconds)) || (0 > stoi(seconds))){
			return false;
		}
	
		//Check length
		if(iString.length() != 8){
			return false;
		}

		return true;

	}
	catch (exception& e){
		return false;	
	}
}

/** @brief Edits the entry item by the give entryID
 *
 */
list<Media> editMediaEntry(string entryID, list<Media> mList, list<string> sList){

	if(mList.size() != 0){
		string temp;
		double tempDub;
		float tempFloat;
		bool foundFlag = false;
		list<Media> tempList; 
		list<Media>::iterator it;
		for (it = mList.begin(); it != mList.end(); it++){

			Media item = (*it);
			if(entryID.compare(item.getEntryID()) == 0){
				cout << "Editing Media Entry:\n";
				cout << item.asString() + "\n\n";

				//Editing Fields
				cout << "\nEdit 'Product Type' (movie, music, television, news or radio): ";
				getline(cin, temp);
				while(!listContains(sList, temp)){
					cout << "\nEnter valid Product Type (movie, music, television, news or radio): ";
					getline(cin, temp);
				}
				item.setProductType(temp);



				cout << "\nEdit 'Media Title': ";
				getline(cin, temp);
				item.setTitle(temp);

				cout << "\nEdit 'Media Description': ";
				getline(cin, temp);
				item.setDescription(temp);

				cout << "\nEdit 'Media Duration Time' (hh:mm:ss): ";
				getline(cin, temp);
				while(!validTime(temp)){
					cout << "\nEnter valid Media Duration Time (hh:mm:ss): ";
					getline(cin, temp);	
				}
				item.setDurationTime(temp);

				cout << "\nEdit 'Media Rental Price': ";
				getline(cin, temp);
				tempDub = atof(temp.c_str());
				tempFloat = (float) tempDub;
				item.setRentalPrice(tempFloat);

				cout << "\nEdit 'Media Date Available': ";
				getline(cin, temp);
				while(!validDate(temp)){
					cout << "\nEnter valid Media Date Available (mm/dd/yyyy): ";
					getline(cin, temp);	
				}
				item.setDateAvailable(temp);

				cout << "\nEdit 'Media Days Available': ";
				getline(cin, temp);
				item.setDaysAvailable(temp);

				foundFlag = true;
				tempList.push_front(item);
			}
			else{
				tempList.push_front(item);
			}
		}
		if(!foundFlag){
			cout << string(100, '\n');
			cout << "No Media with EntryID:'" + entryID + "' exists in the List\n";
			return mList;
		}
		else{
			return tempList;
		}
	}
	else{
		cout << string(100, '\n');
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
				cout << string(100, '\n');
				cout << "Deleted Media Entry:\n";
				cout << item.asString() + "\n";
				foundFlag = true;
			}
			else{
				tempManager.push_front(item);
			}
		}
		if(!foundFlag){
			cout << string(100, '\n');
			cout << "No Media with EntryID:'" + entryID + "' exists in the List\n";
		}
		return tempManager;
	}
	else{
		cout << string(100, '\n');
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
				cout << string(100, '\n');
				cout << "Found Media Entry:\n";
				cout << item.printString() + "\n";
				return;
			}
		}
		cout << string(100, '\n');
		cout << "No Media with EntryID:'" + entryID + "' exists in the List\n";
	}
	else{
		cout << string(100, '\n');
		cout << "The List is empty!\n";
	}
	return;

}

list<Media> newMediaEntry(list<Media> mList, list<string> sList){
	string temp; 
	double tempDub;
	float tempFloat;

	Media newItem = Media();
	newItem.generateEntryID();
	while(validID(newItem.getEntryID(), mList)){
		newItem.generateEntryID();
	}

	cout << "\nProduct Type (movie, music, television, news or radio): ";
	getline(cin, temp);
	while(!listContains(sList, temp)){
		cout << "\nEnter valid Product Type (movie, music, television, news or radio): ";
		getline(cin, temp);
	}
	newItem.setProductType(temp);

	cout << "\nMedia Title: ";
	getline(cin, temp);
	newItem.setTitle(temp);

	cout << "\nMedia Description: ";
	getline(cin, temp);
	newItem.setDescription(temp);

	cout << "\nMedia Duration Time (hh:mm:ss): ";
	getline(cin, temp);
	while(!validTime(temp)){
		cout << "\nEnter valid Media Duration Time (hh:mm:ss): ";
		getline(cin, temp);	
	}
	newItem.setDurationTime(temp);

	cout << "\nMedia Rental Price: ";
	getline(cin, temp);
	tempDub = atof(temp.c_str());
	tempFloat = (float) tempDub;
	newItem.setRentalPrice(tempFloat);

	cout << "\nMedia Date Available (mm/dd/yyyy): ";
	getline(cin, temp);
	while(!validDate(temp)){
		cout << "\nEnter valid Media Date Available (mm/dd/yyyy): ";
		getline(cin, temp);	
	}
	newItem.setDateAvailable(temp);

	cout << "\nMedia Days Available: ";
	getline(cin, temp);
	newItem.setDaysAvailable(temp);

	mList.push_front(newItem);
	cout << string(100, '\n');
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

	//Initialize random time seed and other variables
	srand(time(0));
	string programFile = "test.dat";

	list<Media> mediaManager;
	//allows uppercase or lowercase
	string productTypeArray[] = {"Movie", "movie", "Music", "music", "Television", "television", "News", "news", "Radio", "radio"};
	list<string> productTypeList (productTypeArray, productTypeArray + sizeof(productTypeArray) / sizeof(string));
		

	//Read in file
	mediaManager = readInFile(programFile, mediaManager);


	bool sFlag = true;
	string entryID;
	string uInput;
	cout << string(100, '\n');
	cout << "Blair Kiel's Media Streaming Service\n";
	cout << "====================================\n";
	cout << "NOTE: AVOID USING COMMAS IN INPUT   \n";

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
			float rentalTotal = 0;
			int mediaCount = 0;
			cout << string(100, '\n');
			cout << "Current Media Streaming Service Contents\n";
			cout << "========================================\n\n";
			cout << "EntryID | Product Type | Title | Description | Duration Time | Rental Price | Date Available | Days Available \n\n";
            		if (mediaManager.size() != 0){
                		list<Media>::iterator it;
                		for (it = mediaManager.begin(); it != mediaManager.end(); it++){
                    			Media item = (*it);
					rentalTotal += item.getRentalPrice();
					mediaCount++;
                    			cout << item.printString() + '\n';
                		}
           		} 
            		else{
				cout << "The List Is Empty!\n";
		    	}
			cout << "\nMedia Items in Streaming Service: " + to_string(mediaCount) + '\n';
			cout << "Total Rental Cost: " + toDollar(rentalTotal) + '\n';
			cout << '\n';
		}

		//Create new entry
		else if (uInput == "2"){

			mediaManager = newMediaEntry(mediaManager, productTypeList);
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
			mediaManager = editMediaEntry(entryID, mediaManager, productTypeList);
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

