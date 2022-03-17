#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct record
{
    int ID;
    char firstname[16];
    char surname[16];
    char destination[15];
    char membership[10];
    char booking[10];
};
typedef struct record Record;

string trimBlanks(string str)
{
    while(!isalpha(str[0]))
    {
        for (int x = 0; x < (int)str.length()-1; x++)
        {
            str[x] = str[x+1];
        }
        str[str.length()-1] = '\0';
    }
    return str;
}

int main()
{
    string heading;
    int idno;
    string firstname;
    string surname;
    string destination;
    string membership;
    string booking;
    char comma;
    
    fstream infile("Guests.txt", ios::in);
    fstream outfile("Guests.dat", ios::out|ios::binary);
    
    getline(infile, heading, '\n');
    Record rec;
    
    while(!infile.eof()) 
    {
        infile >> idno >> comma;
        getline(infile, firstname, ',');
        getline(infile, surname, ',');
        getline(infile, destination, ',');
        getline(infile, membership, ',');
        getline(infile, booking, '\n');
        
        firstname = trimBlanks(firstname);
        surname = trimBlanks(surname);
        destination = trimBlanks(destination);
        membership = trimBlanks(membership);
        booking = trimBlanks(booking);
        
        rec.ID = idno;
        firstname.copy(rec.firstname, firstname.size() + 1);
        surname.copy(rec.surname, surname.size() + 1);
        destination.copy(rec.destination, destination.size() + 1);
        membership.copy(rec.membership, membership.size() + 1);
        booking.copy(rec.booking, booking.size() + 1);

        if (!infile.eof())
        {
        outfile.write(reinterpret_cast<char*>(&rec), sizeof(Record));
        cout << rec.firstname << "\t" 
         << rec.surname << "\t" 
         << rec.destination << "\t" 
         << rec.membership << "\t" 
         << rec.booking << "\t";
        }
    }

    return 0;
}
