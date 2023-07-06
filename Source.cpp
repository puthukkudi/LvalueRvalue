#include <iostream>
using namespace std;



int GetValue() //Rvalue
{
	return 10; 
}

int& GetValueNew() //Lvalue
{	
	static int value = 10;
	return value;
}

void SetValue(int i)
{

}

void SetValueNew(int& i) // Lvalue ref &
{

}

void SetValueRValue(int&& i) // RValue ref &&
{

}

int main()
{

	int value = 10;
	// value is Lvalue
	// 10 is Rvalue


	// Lvalue has address
	// Rvalue are temporary values

	
	int a = value; // assigning Lvalue to Lvalue

	int p = GetValue();  // assigning Rvalue to Lvalue
	// GetValue() is Rvalue as it returns a 
	// temp value that does not have any location / address

	/*
	* Cannot assign to Rvalue
	*/
	//GetValue() = 5; 

	GetValueNew() = 10; // No error as GetValueNew() is Lvalue


	SetValue(value); // assigning Lvalue to Lvalue
	SetValue(5); // assigning Rvalue to Lvalue

	/*
	* You cannot take Lvale reference from Rvalue
	*/
	SetValueNew(value);
	// SetValueNew(10); // error

	//int& p = 10; // Error : You cannot take Lvale reference from Rvalue
	const int& q = 10; // workaround for above


	/*
	* You cannot take Rvale reference from Lvalue
	*/
	//SetValueRValue(value); // Error
	SetValueRValue(10);


	cin.get();
}