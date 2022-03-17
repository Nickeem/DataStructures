#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct record
{
    int ID;
    char firstname[10];
    char surname[10];
    char destination[15];
    char membership[10];
    char booking[10];
};
typedef struct record Record;


int main()
{
    fstream infile("Guests.dat", ios::in|ios::binary);
    Record rec;
    infile.seekg(0);
    
    while (!infile.eof())
    {
        infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
        cout << rec.surname << " || " << rec.ID << endl;
    }
    

    return 0;
}
