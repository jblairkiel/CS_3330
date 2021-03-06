#ifndef MEDIA_H_
#define MEDIA_H_

#include <string>

using namespace std;

class Media{

	private:

		string entryID;
		string productType;
		string title;
		string description;
		string durationTime;
		float rentalPrice;
		string dateAvailable;
		int daysAvailable;

	public:

		Media();

		//GETTERS and SETTERS
		string getEntryID();
		void setEntryID(string sID);
		void generateEntryID();

		string getProductType();
		void setProductType(string sType);
		
		string getTitle();
		void setTitle(string sTitle);
		
		string getDescription();
		void setDescription(string sDescription);

		string getDurationTime();
		void setDurationTime(string sTime);
		
		float getRentalPrice();
		string getRentalDollar();
		void setRentalPrice(float fPrice);
	
		string getDateAvailable();
		void setDateAvailable(string sDate);

		int getDaysAvailable();
		void setDaysAvailable(string sDays);

		//HELPERS
		
		char getRandomChar();
		char getRandomNum();

		string asString();
		string printString();

};

#endif
