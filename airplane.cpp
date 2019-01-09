#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;



void createPlaneSection(vector<bool>& psection, int n);
void CreatePlane(vector<bool>& fc, vector<bool>& ec);
void displaySeatingSectionChart(vector<bool> v);
void displayPlaneChart(vector<bool> fc, vector<bool> ec);
char translateSeatStatus(bool b);
void displayBookingMenu();
int getMenuChoice();
int getEmptySeat(vector<bool> v);
int reserveSeat(vector<bool>& v, int seat);
int bookseat(vector<bool>& fc, vector<bool>& ec, int choice);
bool bookseat1(vector<bool>& fc, vector<bool>& ec, int& actualSeat, int choice);
void printBoardingPass(vector<bool> fc, vector<bool> ec,int choice, int seat);
void ars();
bool isSeatEmpty(vector<bool> v, int s);

int main()
{
  ars();
  return 0;
}


void ars()
{
vector<bool> first, economy;
CreatePlane(first, economy);
displayPlaneChart(first, economy);
int choice;
int aseat;

    do {
        displayBookingMenu();
        choice = getMenuChoice();
        // if (choice !=3)
        // {
        aseat = bookseat(first, economy, choice);
        displayPlaneChart(first, economy);
        printBoardingPass(first, economy, choice, aseat);
        cout << endl;
        cout << "Would you like to book another seat?" << endl;
        cout << endl;
    // }
 }
 while (choice != 3);

    cout << "Thank you, have a nice day!"<<endl;
    exit(0);

displayPlaneChart(first, economy);
printBoardingPass(first, economy, choice, aseat);


}

void displayBookingMenu()
{
    cout << "------------------------------" << endl;
    cout << "     Flight Booking Menu      " << endl;
    cout << "------------------------------" << endl;
    cout << "1. First Class (seats 1 to 20)" << endl;
    cout << "2. Economy Class (seats 21 to 50)" << endl;
    cout << "3. Quit Menu " << endl;

}

int getMenuChoice()
{
    int choice;

    cout << "Enter Your Choice: ";
    cin >> choice;

    while((choice < 1 || choice > 3) && (!cin.fail()))
    {
        cout << "Please enter a valid number";
        cin >> choice;
    }
    if(cin.fail())
        exit(1);

    return choice;
}

void createPlaneSection(vector<bool>& psection, int n)
{
    //creating an empty vector, n will be declared somewhere else.
    vector<bool> ps;
    for(int i=0; i < n; i++)
        ps.push_back(false);
    psection = ps;
}

void CreatePlane(vector<bool>& fc, vector<bool>& ec)
{
    const int fcsize = 20;
    const int ecsize = 30;
    createPlaneSection(fc,fcsize);
    createPlaneSection(ec,ecsize);
}


void displaySeatingSectionChart(vector<bool> v, int k)
{
    const char open = '-';
    const char closed = 'x';

    for (int i = 0; i<v.size();i++)
    {
        cout<< (k + i) << ":";
        if (v[i] == true)
        cout << closed <<" ";
        else
        cout<< open <<" ";
    }
}

void displayPlaneChart(vector<bool> fc, vector<bool> ec)
{
    int fcsize= fc.size();
    cout<<endl;
    cout<< "Plane Seating Chart: "<<endl;
    cout<<endl;
    cout<< "First Class Chart: "<<endl;

    displaySeatingSectionChart(fc,1);
    cout<< endl<<endl;
    cout<<"Economy Class Chart: "<<endl;
    displaySeatingSectionChart(ec,fcsize + 1);
    cout<<endl<<endl;
}

int getEmptySeat(vector<bool> v)
{
  int Full = -1;
  for (unsigned int i = 0; i< v.size(); i++)
  {
      if (v.at(i) == false)
       return i;

  }
  return Full;
}


int reserveSeat(vector<bool>& v, int seat)
 {
  int vsize = v.size();
  if((seat< 0) || (seat >= vsize))
  {
      cout << "Failed Reservations: " << seat << endl;
      return (-1);
  }
  if(v.at(seat) == true)
  {
      cout<< "Seat" << seat << "is occupied." <<endl;
      return(-1);
  }
  v.at(seat)= true;
  return 1;
 }

int bookseat(vector<bool>& fc, vector<bool>& ec, int choice)
{
    int rseat;

    if (choice==1)
      bookseat1(fc,ec, rseat,1);
    else
      bookseat1 (ec,fc, rseat,2);
    return rseat;
}

bool isSeatEmpty(vector<bool> v, int s)
{
    int vsize = v.size();
    if (s < 0 || s >= vsize )
       return false;
    if (v.at(s) == true)
    {   cout << endl;
         cout << "Sorry, this seat is unavailable." << endl;
         cout << endl;
       return false;}
    else
        return true;
}

bool bookseat1(vector<bool>& fc, vector<bool>& ec, int& actualSeat, int choice)
{
    cout << "Which seat would you like? ";//try later
    int seat;  // maybe not needed!!!
    cin >> seat;// try later
    bool avail;
    avail = isSeatEmpty(fc, seat-1);
    if (avail)
    {
      if (choice ==1) {
        actualSeat = seat-1;    /// THIS IS THE ISSUE
        reserveSeat(fc, seat-1);/// Right here!!!
        return true;
      }
    else {
      actualSeat = seat-21;    /// THIS IS THE ISSUE
      reserveSeat(fc, seat-21);/// Right here!!!
      return true;
      }
    }
    seat = getEmptySeat(fc);
    if (seat == -1)
    {
      cout << "This section is taken, would you like to try the other section? [y|n]: ";
    char answer;
    cin >> answer;
    if (answer == 'y')
    {
        seat = getEmptySeat(ec);
        if (seat == -1)
          {
            cout<< "Sorry, this flight is fully booked." << endl;
            return false;
          }
        actualSeat = seat;
        reserveSeat(ec,seat);
        return true;
    }
    else
      {
        cout << "Sorry, this flight is fully booked." << endl;
        return false;
      }
    }
    return true;
}

void printBoardingPass(vector<bool> fc, vector<bool> ec, int choice, int seat)
{
  cout <<  endl;
  cout << "    Airline Boarding Pass    " << endl;
  cout << "-----------------------------" << endl;

  if (choice == 1)
  {
    if (seat <= (fc.size() + 1))
    {
      cout << "Class: ";
      cout << "FIRST CLASS" << endl;
      cout << "Seat Number: " << seat + 1 << endl;
      cout << "Enjoy your flight!" << endl;
    }
  }
  else {
    if ((seat <= ec.size() + 1))
    {
      cout << "Class: ";
      cout << "ECONOMY CLASS" << endl;
      cout << "Seat Number: " << seat + 21 << endl;
      cout << "Enjoy your flight!" << endl;
    }
  }
}
