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

inline float areaOfCircle(int r) {
	return M_PI * r **2;
}

inline float areaOfCircle(float r) {
	return M_PI * r **2;
}

inline float areaOfCircle(double r) {
	return M_PI * r **2;
}
