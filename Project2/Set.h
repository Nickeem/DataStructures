#ifndef SET_H
#define SET_H

class SetNode {
    private:
        int ClientID;
        char FirstName[10];
        char Surname[10];
        char Destination[15];
        char Membership[10];
        char Booking[10];
        
    public:
        SetNode() {
            ClientID = -1;
        }
        SetNode(Record rec) {
            ClientID = rec.id; 
            strcpy(FirstName , rec.firstname);
            strcpy(Surname, rec.surname);
            strcpy(Destination, rec.destination);
            strcpy(Membership, rec.membership);
            strcpy(Booking, rec.booking);
        }
        
         // Accessor functions
        int getID()       {return ClientID;}
        char* getFirstName() {return FirstName;}
        char* getSurname() { return Surname;}
        char* getDestination() {return Destination; }
        char* getMembership() {return Membership;}
        char* getBooking() {return Booking;}
        //string getData();

        // Mutator functions
        void setID(int id)       {ClientID = id;}
        void setFirstName(char* fname)  {strcpy(FirstName , fname);}
        void setSurname(char* sname)  {strcpy(Surname , sname);}
        void setDestination(char* dest)  {strcpy(Destination , dest);}
        void setMembership (char* membership)  {strcpy(Membership , membership);}
        void setBooking(char* booking)  {strcpy(Booking , booking);}
};

class Set {
    private:
        vector <SetNode> elements;
    public:
        Set(void) {elements.resize(0);}
        int getNumElements()  const {return elements.size();}
        SetNode* getElement (int) ;
        bool find (int );
        void add (Record); 
        void remove (int ); 
        void intersect(Set*, Set*);
        void Union(Set* setA, Set* setB);
        string displaySet()

};

SetNode* Set::getElement (int index) {
    return &elements[index];
}

bool Set::find(int id) {
    for (int i=0; i < elements.size(); i++) {
        if (id == elements[i].getID()) // all values between nodes are the same
            return true;
    }
    return false;
}
void Set::add (Record rec) {
    if (find(rec.id)) 
        return;
    else
        elements.push_back(SetNode(rec));

}

void Set::remove(int id) {
    int index = 0;
    while (elements[index].getID() != id && index < elements.size()) {
        index++;
    }
    if (index == elements.size())
        return;
    for (int j=index; j < elements.size(); j++)  {
        elements[j] = elements[j + 1];  
    }
    elements.resize(elements.size() - 1);
        
}

void Set::intersect(Set* setA, Set* setB) {
    elements.resize(0); // clear contents of vector
    for(int i = 0; i < setA->getNumElements(); i++) {
        if (setB->find(setA->getElement(i)->getID()))
            elements.push_back(*(setA->getElement(i)));
    }
}

void Set::Union(Set* setA, Set* setB) {
    elements.resize(0);
    for (int i = 0; i < setA->getNumElements(); i++)
        elements.push_back(*(setA->getElement(i)));
    for (int i = 0; i < setB->getNumElements(); i++) {
        if (!find(setB->getElement(i)->getID()))
            elements.push_back(*(setB->getElement(i)));
    }
}

string Set::displaySet() {
    string data = "";
    stringstream data_stream;
    for (int i =0; i < elements.size(); i++) {
        data_stream << std::left << setw(10) << elements[i].getID() 
                        << std::left << setw(15) << elements[i].getSurname()
                        << std::left << setw(15) << elements[i].getDestination()
                        << std::left << setw(15) << elements[i].getMembership()
                        << std::left << setw(15) << elements[i].getBooking()
                        << endl; 
            
            data += data_stream.str();
            data_stream.str("");
    }
    return data;
}

#endif
