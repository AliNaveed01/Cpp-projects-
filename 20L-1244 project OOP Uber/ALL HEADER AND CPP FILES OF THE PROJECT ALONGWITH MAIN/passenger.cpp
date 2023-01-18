#include"passenger.h"
#include"trip.h"

passenger::passenger() :USER(), pay(NULL)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////

passenger::passenger(string name, date DOB, string email, string phone_number, payment pay) : USER(name, DOB, email, phone_number), pay(NULL)
{
	this->p = pay;
}
/////////////////////////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& out, passenger& p)
{
	p.USER::print();
	out << p.p;
	if (p.currenttrip == nullptr)
		out << "Currently not riding\n";
	else
		out << p.currenttrip->getstat() << endl;
	return out;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

trip* passenger::bookRide(string A, string B)
{

	if (currenttrip != nullptr && currenttrip->getstat() == "looking for ride")
	{
		cout << "Cannot do two rides at once \n" << endl;
		return nullptr;
	}
	trip* newTrip = new trip;
	string stat = newTrip->getstat();
	if (stat == "Complete" || stat == "")
	{
		count++;
		newTrip->change_status("looking for ride");
		newTrip->dat = new date;
		newTrip->set_pickup_location(A);
		newTrip->set_dropoff_location(B);
		newTrip->Passanger = this; //assigns a pessenger to the trip.
		currenttrip = newTrip;

		tripsHistory.push_back(currenttrip);
		return newTrip;
	}
	
	else
	{
		cout << "Cannot do two rides at once \n" << endl;
	}
	return nullptr;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void passenger::rateDriver(trip* t, float rating)
{
	string check = t->getstat();
	if (check == "Complete")
	{
		t->rateDriver(rating);
	}

	else
	{
		cout << "Error Cannot rate driver. Trip is not complete." << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void passenger::cancelRide()
{
	string stat = currenttrip->getstat();
	if (stat == "looking for driver" || stat == "InProgress")
	{
		currenttrip->change_status("cancelled");
	}
	else
		cout << "Cannot cancel ride \n" << endl;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
float passenger::getAvgRating()
{
	int totalTrips = tripsHistory.size(), ratedRides =0;
	float totalRating = 0;
	for (int i = 0; i < totalTrips; i++) {
		if (tripsHistory[i]->getstat() == "Complete")
		{
			totalRating += tripsHistory[i]->passanger_rating;
			ratedRides++;

		}
	}

	return (totalRating * 1.0) / ratedRides;
}


////////////////////////////////////////////////////////////////////////////////
void passenger::printTrips()
{
	int totalTrips = tripsHistory.size();
	for (int i = 0; i < totalTrips; i++)
		cout << *tripsHistory[i];
}


//////////////////////////////////////////////////////////////////////////////////
passenger::passenger(string name, date DOB, string email, string phone_number) : USER(name, DOB, email, phone_number), pay(NULL)
{

}

/////////////////////////////////////////////////////////////////////////////////
float passenger::getHighestRating()
{
	float highest = 0;
	int totalTrips = tripsHistory.size();
	for (int i = 0; i < totalTrips; i++)
	{
		
		if (tripsHistory[i]->passanger_rating > highest)
			highest = tripsHistory[i]->passanger_rating;
	}

	return highest;
}

////////////////////////////////////////////////////////////////////////////////////
string passenger::getName()
{
	return USER::getName();
}