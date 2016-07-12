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
	setEntryID();
	setProductType("");
	setTitle("");
	setDescription("");
	setDurationTime("");
	setRentalPrice(0);
	setDateAvailable("");
	setDaysAvailable("");	

}

/** @brief GETTER of ENTRYID
 *
 */
string Media::getEntryID(){

	return entryID;
}

/** @brief SETTER of ENTRYID
 *
 */
void Media::setEntryID(){

	entryID = "";

	//FIRST 3 CHARS
	for (int i = 0; i < 3; ++i){
		entryID += getRandomChar();
	}	


	entryID += "-";

	//SECOND 3 NUMS
	for (int i = 0; i < 3; ++i){
		entryID += getRandomNum();
	}

	entryID += "-";

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
string Media::getDaysAvailable(){

	return daysAvailable;
}

/** @brief SETTER for DAYSAVAILABLE
 *
 */
void Media::setDaysAvailable(string sDays){
	
	daysAvailable = sDays;
	return;
}

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
	string ret = "";
	ret += getEntryID();
	ret += ",";
	ret += getProductType();
	ret += ",";
	ret += getDescription();
	ret += ",";
	ret += getDurationTime();
	ret += ",";
	rentPrice = getRentalPrice();
	ret += to_string(rentPrice);
	ret += ",";
	ret += getDateAvailable();
	ret += ",";
	ret += getDaysAvailable();
	ret += ";";
	return ret;
}
	
