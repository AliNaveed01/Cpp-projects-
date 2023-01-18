#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include "payment.h"
#include "driver.h"
#include "date.h"
#include "passenger.h"
#include "trip.h"
using namespace std;


/////////////////////////////////////////////////////

ostream& operator<<(ostream& out, const trip& t)
{
	out << "Status: " << t.status << endl;
	out << "Date: " << *t.dat << endl;
	out << "Pick Up Location: " << t.pickup_location << endl;
	out << "Drop Off Location: " << t.dropoff_location << endl;
	if (t.Passanger != nullptr)
		out << "Passanger Name: " << t.Passanger->getName() << endl;  
	if (t.Driver != nullptr)
		out << "Driver Name: " << t.Driver->getName() << endl;      //error
	if (t.status == "Complete")
	{
		out << "Passanger Rating: " << t.passanger_rating << endl;
		out << "Driver Rating: " << t.driver_rating << endl << endl;
	}
	return out;
}

//Module 3 
vector< USER* > usersArr;
void readUsers(string st);
void printUsers() ;
USER mostHighlyRatedUser() ;
driver mostHighlyRatedDriver() ;
passenger mostHighlyRatedPassenger();

const int SIZE1 = 20;
//an array of trips to keep pointers of all the trips of uber application
//This array will keep data of all the trips ever created. 
trip** uberTrips = new trip * [SIZE1];
int n = 0;

void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if (n < SIZE1 - 1 && t != nullptr)
	{
		uberTrips[n++] = t;
	}
}
void printUberTrips() //function to print uberTrips
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << *uberTrips[i] << endl;
	}
}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	readUsers("data.txt");
	printUsers();

	passenger* shahmeer = dynamic_cast<passenger*>(usersArr[0]);
	passenger* ibrahim = dynamic_cast<passenger*>(usersArr[2]);
	passenger* mustafa = dynamic_cast<passenger*>(usersArr[3]);
	passenger* sana = dynamic_cast<passenger*>(usersArr[5]);

	driver* meher = dynamic_cast<driver*>(usersArr[1]);
	driver* ali = dynamic_cast<driver*>(usersArr[4]);
	driver* noor = dynamic_cast<driver*>(usersArr[6]);

	trip* trip1 = shahmeer->bookRide("A", "B");
	meher->pickARide(trip1);
	meher->endARide();
	shahmeer->rateDriver(trip1, 5);
	meher->ratePassanger(trip1, 2);


	trip1 = ibrahim->bookRide("C", "D");
	meher->pickARide(trip1);
	meher->endARide();
	ibrahim->rateDriver(trip1, 4);
	meher->ratePassanger(trip1, 3);

	trip1 = sana->bookRide("E", "F");
	meher->pickARide(trip1);
	meher->endARide();
	sana->rateDriver(trip1, 5);
	meher->ratePassanger(trip1, 4);


	USER user = mostHighlyRatedUser();
	user.print();

	cout << endl;

	passenger highP = mostHighlyRatedPassenger();
	cout << highP << endl;

	driver highD = mostHighlyRatedDriver();
	cout << highD << endl;
	

	passenger* p1 = new passenger("P1", date(10, 10, 1990), "ali@yahoo.com", "0334564334", payment("111-222-333-333", "card"));
	driver* d1 = new driver("D1", date(16, 1, 1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");



	////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
	cout << *p1 << endl;
	cout << *d1 << endl;

	addToUberTrips(p1->bookRide("A", "B"));// will create a new trip and add it to uberTrips array
	cout << *uberTrips[n - 1];// will print this trip

	trip* tempPtr = p1->bookRide("C", "D");
	if(tempPtr != nullptr)
		addToUberTrips(p1->bookRide("C", "D"));//prints error as p1 has already booked a ride

	d1->pickARide(uberTrips[n-1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress

	d1->ratePassanger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete

	cout << *p1 << endl;
	cout << *d1 << endl;

	d1->endARide(); //will change the status of uberTrip[0] to Complete

	d1->ratePassanger(uberTrips[n - 1], 5); //will set rating of passenger
	p1->rateDriver(uberTrips[n - 1], 4); //will set rating of driver
	cout << *uberTrips[n - 1] << endl;
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->pickARide(uberTrips[n - 1]);//prints error as the ride is completed
	cout << "-------------------------------------" << endl << endl;








	//////Test case 2: User books, driver picks, user cancels, ratings are not applicable to cancelled ride
	addToUberTrips(p1->bookRide("C", "D"));
	d1->pickARide(uberTrips[n - 1]);
	cout << *p1 << endl;
	cout << *d1 << endl;
	p1->cancelRide();
	p1->cancelRide();//error as there is no current ride
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl << endl;

	////Test Case 3: User Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
	addToUberTrips(p1->bookRide("D", "E"));
	p1->cancelRide();
	d1->pickARide(uberTrips[n - 1]); //error as this ride is not looking for driver
	d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;

	//Test Case 4: getting avg ratings adn print trip funnction
	//Adding some more test data
	addToUberTrips(p1->bookRide("X", "Y"));
	d1->pickARide(uberTrips[n - 1]);
	d1->endARide();
	d1->ratePassanger(uberTrips[n - 1], 3);
	p1->rateDriver(uberTrips[n - 1], 5);

	addToUberTrips(p1->bookRide("X", "Y"));
	d1->pickARide(uberTrips[n - 1]);
	d1->endARide();
	d1->ratePassanger(uberTrips[n - 1], 6);//error as the rating is not between 1 and 5 
	d1->ratePassanger(uberTrips[n - 1], 4);
	d1->ratePassanger(uberTrips[n - 1], 3);// will upate the passanging rating from 4 to 3
	p1->rateDriver(uberTrips[n - 1], 1);

	p1->printTrips();
	cout<< endl << endl;
	d1->printTrips();

	cout << "\n Passengers Ratings \n";
	cout << p1->getAvgRating()<<endl;
	cout << d1->getAvgRating()<<endl;

	delete d1;
	delete p1;
	delete[]uberTrips;
	d1 = nullptr;
	p1 = nullptr;
	uberTrips = nullptr;
}


void readUsers(string st)
{
	char userType;
	int day, month, year;
	string name, email, phone;
	date readDate;
	
	fstream fin(st.c_str(),ios::in);
	if ( !fin.is_open() )
		cout << "Error cannot open file\n";
	else
	{
		while ( !fin.eof() )
		{
			fin >> userType;

			fin.ignore();

			getline(fin, name, ',');


			fin >> day;
			fin.ignore();
			fin >> month;
			fin.ignore();
			fin>> year;

			fin.ignore();

			getline(fin, email, ',');
			getline(fin, phone);

			if (userType == 'p')
			{
				passenger* p1 = new passenger(name, date(day, month, year), email, phone);
				usersArr.push_back(p1);
				p1 = nullptr;
			}

			else if (userType == 'd')
			{
				driver* d1 = new driver(name, date(day, month, year), email, phone);
				usersArr.push_back(d1);
				d1 = nullptr;
			}
		}
		fin.close();
	}
	
	
}

void printUsers()
{
	for (int i = 0; i < usersArr.size(); i++)
	{
		usersArr[i];
	}
	for (auto i : usersArr)
	{
		passenger* p2 = dynamic_cast <passenger*> (i); //i is USER*
		if (p2 != nullptr)
			cout << *p2;

		driver* d2 = dynamic_cast<driver*>(i); //i is User*
		if (d2 != nullptr)
			cout << *d2;
		cout << endl;
	}
}


USER mostHighlyRatedUser() 
{
	float highest = 0;
	USER* heighestPtr = nullptr;
	for (auto i : usersArr)
	{
		if (i->getHighestRating() > highest) // i is user*,
		{
			highest = i->getHighestRating();
			heighestPtr = i;
		}
	}
	if (heighestPtr == nullptr)
		exit(0);
	return *heighestPtr;
}


driver mostHighlyRatedDriver()
{
	float highest = 0;
	driver* ptr = nullptr;
	for (auto i : usersArr)
	{
		driver* d2 = dynamic_cast<driver*>(i);
		if (d2 != nullptr)
		{
			if (d2->getHighestRating() > highest)
			{
				highest = d2->getHighestRating();
				ptr = d2;
			}
		}
	}

	if (ptr == nullptr)
		exit(0);
	return *ptr;
}

passenger mostHighlyRatedPassenger()
{
	float highest = 0;
	passenger* ptr = nullptr;
	for (auto i : usersArr)
	{
		passenger* d2 = dynamic_cast<passenger*>(i);
		if (d2 != nullptr)
		{
			if (d2->getHighestRating() > highest)
			{
				highest = d2->getHighestRating();
				ptr = d2;
			}
		}
	}

	if (ptr == nullptr)
		exit(0);
	return *ptr;
}