#ifndef H_clockType
#define H_clockType

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of a clock
//***********************************************************

#include <iostream>

using namespace std;

class clockType
{
	friend ostream& operator<< (ostream&, const clockType&);	
	
	public:
		void setTime(int hours, int minutes, int seconds);
			//Function to set the time
			//The time is set according to the parameters
			//Postcondition: hr = hours; min = minutes; 
				//               sec = seconds
			//  The function checks whether the values of hours,
			//  minutes and seconds are valid. If a value is invalid, 
			//  the default value 0 is assigned.

		void getTime(int& hours, int& minutes, int& seconds) const;
			//Function to return the time
			//Postcondition: hours = hr; minutes = min;
			//	           seconds = sec

		void printTime() const;
			//Function to print the time
			//Postcondition: Time is printed in the form hh:mm:ss

		void incrementSeconds();
			//Function to increment the time by one second.
			//Postcondition: The time is incremented by one second
			//  If the before-increment time is 23:59:59, the time
			//  is reset to 00:00:00.

		void incrementMinutes();
			//Function to increment the time by one minute.
			//Postcondition: The time is incremented by one minute 
			//  If the before-increment time is 23:59:53, the time
			//  is reset to 00:00:53.

		void incrementHours();
			//Function to increment the time by one hour.
			//Postcondition: The time is incremented by one hour 
			//  If the before-increment time is 23:45:53, the time 
			//  is reset to 00:45:53.

		bool equalTime(const clockType& otherClock) const;
			//Function to compare the two times.
			//Postcondition: Returns true if this time is equal to
			//               otherClock; otherwise, returns false

		clockType(int hours, int minutes, int seconds);
			//Constructor with parameters 
			//The time is set according to the parameters.
			//Postconditions: hr = hours; min = minutes; 
				//                sec = seconds
			//  The constructor checks whether the values of hours, 
			//  minutes, and seconds are valid. If a value is invalid, 
			//  the default value 0 is assigned.

		clockType();
			//Default constructor with parameters 
			//The time is set to 00:00:00.
			//Postcondition: hr = 0; min = 0; sec = 0
			
		bool operator==(const clockType&) const;
		bool operator< (const clockType&) const;
		bool operator> (const clockType&) const;		

	private:
		int hr;  //stores the hours
		int min; //stores the minutes
		int sec; //stores the seconds
};


ostream& operator<< (ostream& osObject, const clockType& clock)
{
	//write the missing code
	return osObject;
}


bool clockType::operator==(const clockType& otherClock) const
{
	//write the missing code
	return false;
}

bool clockType::operator<(const clockType& otherClock) const
{
	//write the missing code
	return false;
}

bool clockType::operator>(const clockType& otherClock) const
{
	//write the missing code
	return false;	
}

void clockType::setTime(int hours, int minutes, int seconds)
{
	if(0 <= hours && hours < 24)
		hr = hours;
	else 
		hr = 0;

	if(0 <= minutes && minutes < 60)
		min = minutes;
	else 
		min = 0;

	if(0 <= seconds && seconds < 60)
		sec = seconds;
	else 
		sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::printTime() const
{  
	if(hr < 10)
	   cout<<"0";
	cout<<hr<<":";

	if(min < 10)
	   cout<<"0";
	cout<<min<<":";

	if(sec < 10)
	   cout<<"0";

   cout<<sec<<endl<<endl;
}

void clockType::incrementHours()
{
	hr++;
	if(hr > 23)
 	  hr = 0;
}

void clockType::incrementMinutes()
{
	min++;
	if(min > 59)
	{
	   min = 0;
	   incrementHours(); //increment hours
	}
}

void clockType::incrementSeconds()
{
    sec++;
	if(sec > 59)
	{
	   sec = 0;
	   incrementMinutes(); //increment minutes
	}
}

bool clockType::equalTime(const clockType& otherClock) const
{
   return(hr == otherClock.hr 
 	    && min == otherClock.min 
          && sec == otherClock.sec);
}

clockType::clockType(int hours, int minutes, int seconds)
{
	setTime(hours, minutes, seconds);
}

clockType::clockType()  //default constructor
{
	setTime(0, 0, 0);
}

#endif
