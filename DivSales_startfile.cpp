// Author:                      Graham Williams
// Assignment Number:           Lab 11
// File Name:                   L11_doe.cpp
// Course/Section:              COSC 1337 Section <number>
// Date:                        <date goes here>
// Instructor:                  Dr. B. Hohlt
//
//  Chapter 11 --  Corporate Sales
//

#include <iostream>
#include <iomanip>
using namespace std;

// class declaration
class DivSales
{
  private:
    double sales[4];        // sales for 4 quarters of one division
    static double totalSales;
    
  public:
    DivSales();
    void setSales(double, double, double, double);
    double getQSales (int);
    static double getCorpSales();
};

// function prototypes
ostream &operator<<(ostream &out, const DivSales divisions);

// main
int main()
{
    
    const int NUM_DIV = 6;      	// number of divisions	
    DivSales divisions[NUM_DIV]; 	// an array of DivSales objects
    								// initialized with the default constructor
    
	// set values for all objects in divisions array
	cout << "Enter the sales for each quarter from each division.\n";
	for (int count = 0; count < NUM_DIV; count++)
	{
		double q1,
			   q2,
			   q3,
			   q4;
		cout << "Division " << (count + 1) << ": ";
		cin >> q1 >> q2 >> q3 >> q4;
		divisions[count].setSales(q1, q2, q3, q4);
	}
	// Output sales by division
	cout << setprecision(2);
	cout << showpoint << fixed;
	cout << "Here are the division sales by quarter:\n";
	for (int count = 0; count < NUM_DIV; count++)
	{
		cout << "The sales for division" << count + 1 << " are:\n";
		for (int i = 0; i < 4; i++)
		{
			cout << "Quarter " << i + 1 << ": $" << divisions[count].getQSales(i) << endl;
		}
	}
	
	// Output total sales
	cout << "The total corporate sales are: $" << DivSales::getCorpSales() << endl;
	
	// Output sales by division with operator<<
	for (int count = 0; count < NUM_DIV; count++)
	{
		cout << divisions << endl;
	}
	// Output total sales
    
    return 0;
}

// function definitions

// overloaded operator<<
ostream &operator<<(ostream &out, DivSales divisions)
{

	for (int i = 0; i < 4; i++)
	{
		out << divisions.getQSales(i);
	}	
	return out;	
}
// default constructor
DivSales::DivSales()
{
    for (int i = 0; i < 4; i++)
        sales[i] = 0;
}

// static member variable totalSales
double DivSales::totalSales = 0;

// static member function setSales
void DivSales::setSales(double q1, double q2, double q3, double q4)
{
	if (q1 < 0)
	{
		q1 = 0;
	}
	else if (q2 < 0)
	{
		q2 = 0;
	}
	else if (q3 < 0)
	{
		q3 = 0;
	}
	else if (q4 < 0)
	{
		q4 = 0;
	}
	else
	{
		totalSales += q1;
		totalSales += q2;
		totalSales += q3;
		totalSales += q4;
		
		sales[0] = q1;
		sales[1] = q2;
		sales[2] = q3;
		sales[3] = q4;
	}
}

// member function getQSales
double DivSales::getQSales(int quarter)
{
	if (quarter >= 0 && quarter <= 3)
	{
		return sales[quarter];
	}
	else
	{
		return 0;
	}
}

// static member function getCorpSales
double DivSales::getCorpSales() 
{
	return totalSales;
}
/*
 
Output sales by division :
Sales for Division 1
        Quarter 1: $3000.00
        Quarter 2: $4000.00
        Quarter 3: $5000.00
        Quarter 4: $6000.00
Sales for Division 2
        Quarter 1: $3500.00
        Quarter 2: $4500.00
        Quarter 3: $5500.00
        Quarter 4: $6500.00
Sales for Division 3
        Quarter 1: $1111.00
        Quarter 2: $2222.00
        Quarter 3: $3333.00
        Quarter 4: $4444.00
Sales for Division 4
        Quarter 1: $3050.00
        Quarter 2: $4050.00
        Quarter 3: $5050.00
        Quarter 4: $6050.00
Sales for Division 5
        Quarter 1: $3550.00
        Quarter 2: $4550.00
        Quarter 3: $5550.00
        Quarter 4: $6550.00
Sales for Division 6
        Quarter 1: $5000.00
        Quarter 2: $6000.00
        Quarter 3: $7000.00
        Quarter 4: $8000.00

Total Corporate Sales: $113510.00

Output sales by division using operator<< :
Sales for Division 1
 Quarter 1: $3000.00
 Quarter 2: $4000.00
 Quarter 3: $5000.00
 Quarter 4: $6000.00

Sales for Division 2
 Quarter 1: $3500.00
 Quarter 2: $4500.00
 Quarter 3: $5500.00
 Quarter 4: $6500.00

Sales for Division 3
 Quarter 1: $1111.00
 Quarter 2: $2222.00
 Quarter 3: $3333.00
 Quarter 4: $4444.00

Sales for Division 4
 Quarter 1: $3050.00
 Quarter 2: $4050.00
 Quarter 3: $5050.00
 Quarter 4: $6050.00

Sales for Division 5
 Quarter 1: $3550.00
 Quarter 2: $4550.00
 Quarter 3: $5550.00
 Quarter 4: $6550.00

Sales for Division 6
 Quarter 1: $5000.00
 Quarter 2: $6000.00
 Quarter 3: $7000.00
 Quarter 4: $8000.00


Total Corporate Sales: $113510.00
  
 */

