#include "Media.h"
#include <ctime>
#include <cstdlib>

/** @brief Constructor for Data type of Media streamer
 * 
 */
using namespace std;

	const char alpha[] = "ABCDE""FGHIJ""KLM""NOPQRST""UVWXYZ";
	const char num[] = "012""3456""789";
	int alphaLen = sizeof(alpha)-1;
	int numLen = sizeof(num)-1;

Media::Media(){

	//Initialize all fields
	/**
	setEntryID("");
	setProductType("");
	setTitle("");
	setDescription("");
	setDurationTime("");
	setRentalPrice(0);
	setDateAvailable("");
	setDaysAvailable("");	
	*/

}

/** @brief GETTER of ENTRYID
 *
 */
string Media::getEntryID(){

	return entryID;
}

void Media::setEntryID(string sID){
	entryID = sID;
	return;		
}

/** @brief SETTER of ENTRYID
 *
 */
void Media::generateEntryID(){

	entryID = "";

	//FIRST 3 CHARS
	for (int i = 0; i < 3; ++i){
		entryID += getRandomChar();
	}	


	entryID.append("-");

	//SECOND 3 NUMS
	for (int i = 0; i < 3; ++i){
		entryID += getRandomNum();
	}

	entryID.append("-");

	//LAST 2 NUMS
	for (int i = 0; i< 2; ++i){
		entryID += getRandomChar();
	}	
	return;
}


/** @brief GETTER for PRODUCTTYPE
 *
 */
string Media::getProductType(){

	return productType;
}

/** @brief SETTER for PRODUCTTYPE
 *
 */
void  Media::setProductType(string sType){

	productType = sType;	
	return;
}

/** @brief GETTER for TITLE
 *
 */
string Media::getTitle(){

	return title;
}

/** @brief SETTER for TITLE
 *
 */
void Media::setTitle(string sTitle){

	title = sTitle;
	return;
}

/** @brief GETTER for DESCRIPTION 
 *
 */
string Media::getDescription(){

	return description;	
}

/** @brief SETTER for DESCRIPTION
 *
 */
void Media::setDescription(string sDescription){

	description = sDescription;
	return;
}

/** @brief GETTER for DURATIONTIME
 *
 */
string Media::getDurationTime(){
	
	return durationTime;
}

/** @brief SETTER for DURATIONTIME
*
*/
void Media::setDurationTime(string sTime){

	durationTime = sTime;
	return;
}


/** @brief GETTER for rentalPrice
 *
 */
float Media::getRentalPrice(){
	
	return rentalPrice;
}

string Media::getRentalDollar(){

	string tempPrice;
	float fPrice = getRentalPrice();
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
/** @brief SETTER for rentalPrice
 *
 */
void Media::setRentalPrice(float fPrice){
	
	rentalPrice = fPrice;
	return;
}

/** @brief GETTER for DATEAVAILABLE
 *
 */
string Media::getDateAvailable(){

	return dateAvailable;
} 

/** @brief SETTER for DATEAVAILABLE
 *
 */
void Media::setDateAvailable(string sDate){
		
	dateAvailable = sDate;
	return;
}

/** @brief GETTER for DAYSAVAILABLE
 *
 */
int Media::getDaysAvailable(){

	return daysAvailable;
}

/** @brief SETTER for DAYSAVAILABLE
 *
 */
void Media::setDaysAvailable(string sDays){
	
	int sInt = stoi(sDays);
	daysAvailable = sInt;
	return;
}

/**HELPERS**/

char Media::getRandomChar(){

	return alpha[rand() % alphaLen];
}

char Media::getRandomNum(){

	return num[rand() % numLen];	
}


/** @brief The string representation of the Media Entry
 *
 */
string Media::asString(){

	float rentPrice;
	int sInt;
	string ret = "";
	ret.append(getEntryID());
	ret.append(",");
	ret.append(getProductType());
	ret.append(",");
	ret.append(getTitle());
	ret.append(",");
	ret.append(getDescription());
	ret.append(",");
	ret.append(getDurationTime());
	ret.append(",");
	rentPrice = getRentalPrice();
	ret.append(to_string(rentPrice));
	//ret.append(getRentalPrice());
	ret.append(",");
	ret.append(getDateAvailable());
	ret.append(",");
	sInt = getDaysAvailable();
	ret.append(to_string(sInt));
	ret.append(";");
	return ret;
}
	
string Media::printString(){

	float rentPrice;
	int sInt;
	string ret = "";
	ret.append(getEntryID());
	ret.append(" | ");
	ret.append(getProductType());
	ret.append(" | ");
	ret.append(getTitle());
	ret.append(" | ");
	ret.append(getDescription());
	ret.append(" | ");
	ret.append(getDurationTime());
	ret.append(" | ");
	ret.append(getRentalDollar());
	//ret.append(getRentalPrice());
	ret.append(" | ");
	ret.append(getDateAvailable());
	ret.append(" | ");
	sInt = getDaysAvailable();
	ret.append(to_string(sInt) + " Days");
	return ret;

}
