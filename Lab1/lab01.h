#include <iostream>
#include <cmath>

using namespace std;

// Start of Part A
int smallest(int a, int b, int c) {
	return min(min(a,b),c);
}


float smallest(float a, float b, float c) {
	return min(min(a,b),c);
}


char smallest(char a, char b, char c) {
	return min(min(a,b),c);
}


string smallest(string a, string b, string c) {
	return min(min(a,b),c);
}
// END OF Part A

//Part B
template <class T>
void print(T item) {
	cout << item << endl;
}
//END OF PART B

// Part C
float calc(int a=1, int b=1, int c=1) {
	return (a*b)/(b+c);
}
// END OF PART C

// Part D
inline float areaOfCircle(int r) {
	return M_PI * r **2;
}

inline float areaOfCircle(float r) {
	return M_PI * r **2;
}

inline float areaOfCircle(double r) {
	return M_PI * r **2;
}

// END OF PART D

// Part E
void pointerSquare(int *pointer) {
	*pointer *= *pointer; // square value in pointer
}
// END OF PART E

//Part F
bool pointerEvenCheck(int *pointer) {
	return (*pointer) % 2 == 0; // check if value at address is even
}
// END OF PART F

// Part G
int* varAddress(int &num){
	return &num; // return variable address
}
// END OF PART G

// Part H
int product(int x, int y){
	if (y == 1 ) {
		return x;
	}
	return x + product(x, --y); // product using sums
}
// END OF PART H 

// Part I
int power(int x, int y){
	if (y == 1 ) {
		return x;
	}
	return x * power(x, --y); // power using recursion
} 
// END OF PART I

