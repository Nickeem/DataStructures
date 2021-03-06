#ifndef DIALOGBOXES_H
#define DIALOGBOXES_H


#include <string>    
  

class InfoDialog: public wxDialog
{
        public:
                InfoDialog(const wxString& title, const wxPoint& pos, const wxSize& size);                    
};

class AddRecordDialog: public wxDialog {
    public:
            wxTextCtrl* ClientIDBox;
            wxTextCtrl* FirstNameBox;
            wxTextCtrl* SurnameBox;
            wxTextCtrl* DestinationBox;
            wxComboBox* MembershipCombo;
            wxComboBox* BookingCombo;
            AddRecordDialog(const wxString& title, const wxPoint& pos, const wxSize& size);
};

class DeleteDialog: public wxDialog
{
    public:
            wxTextCtrl* ClientIDBox;
            DeleteDialog(const wxString& title, const wxPoint& pos, const wxSize& size);
}; // DeleteDialog
    

InfoDialog::InfoDialog ( const wxString& title, const wxPoint& pos, 
                        const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
    {
      
        //The new panel for the InfoDialog box
        wxPanel    *panel = new wxPanel(this, -1);
        std::string sys_arch = "Not Found";
#ifdef _WIN32
        sys_arch = "Windows OS";
#elif __APPLE__
        sys_arch = "Apple OS";
#elif __ANDROID__
        sys_arch = "Android OS";
#elif __linux__
        sys_arch = "Linux OS";
#elif __unix__
        sys_arch = "UNIX OS";

#endif
 
                
        wxStaticText *programmerName   = new wxStaticText(panel, wxID_ANY, wxT("Programmer Name: Nickeem Payne-Deacon"), 
                                                     wxPoint(5, 25));
        wxStaticText *program = new wxStaticText(panel, wxID_ANY, wxT("Program: Testing Abstract Data Types using file data"), 
                                                     wxPoint(5, 70) );
        wxStaticText *systemArchitecture = new wxStaticText(panel, wxID_ANY, wxT(" System: "+sys_arch), 
                                                     wxPoint(5, 115) );

    
        // The OK button
        wxButton* close = new wxButton(panel, wxID_OK, wxT("&Close"), wxPoint(180, 180), 
                                    wxDefaultSize, 0);

        // The CANCEL button
        //wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&CANCEL"), 
          //                                wxPoint(230, 180), wxDefaultSize, 0 );
        // Centre the dialog on the parent's window
        Centre();
        // Maximize(); // Maximize the window
    
  } // InfoDialog constructor
  
AddRecordDialog::AddRecordDialog( const wxString& title, const wxPoint& pos, 
                        const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
{
    //The new panel for the AddRecordDialog box
    wxPanel    *panel = new wxPanel(this, -1);
    // Labels and data boxes
    wxStaticText *ClientIDLabel = new wxStaticText(panel, wxID_ANY, wxT("Client ID: "), 
                                                     wxPoint(5, 25));
    ClientIDBox = new wxTextCtrl ( panel, wxID_ANY, wxT(""), 
                                                    wxPoint(75, 20), wxSize(220, -1) );
    
    wxStaticText *FirstNameLabel = new wxStaticText(panel, wxID_ANY, wxT("First Name: "), 
                                                     wxPoint(5, 65));
    FirstNameBox = new wxTextCtrl ( panel, wxID_ANY, wxT(""), 
                                                    wxPoint(75, 60), wxSize(220, -1) );
    
    wxStaticText *SurnameLabel = new wxStaticText(panel, wxID_ANY, wxT("Surname:: "), 
                                                     wxPoint(5, 105));
    SurnameBox = new wxTextCtrl ( panel, wxID_ANY, wxT(""), 
                                                    wxPoint(75, 100), wxSize(220, -1) );
    
    wxStaticText *DestinationLabel = new wxStaticText(panel, wxID_ANY, wxT("Destination: "), 
                                                     wxPoint(5, 145));
    DestinationBox = new wxTextCtrl ( panel, wxID_ANY, wxT(""), 
                                                    wxPoint(85, 140), wxSize(220, -1) );
    
    wxStaticText *MembershipLabel = new wxStaticText(panel, wxID_ANY, wxT("Membership: "), 
                                                     wxPoint(5, 185));
    bool enableMembership = true;
    string e_m = string(title.mb_str()); // get title of window and put into string 
    
    
    string default_membership = "Regular";
    

    wxArrayString memberships;
    if (e_m.find("AVL") != std::string::npos ) {
        memberships.Add(wxT("Gold"));
        memberships.Add(wxT("Platinum"));
        default_membership = "Gold";
    }
    else if (e_m.find("Splay") != std::string::npos) {
        memberships.Add(wxT("Silver"));
        default_membership = "Silver";
    }
    else if (e_m.find("Set A") != std::string::npos) {
        memberships.Add(wxT("Regular"));
        default_membership = "Regular";
    }
    else {
        
        memberships.Add(wxT("Regular"));
        memberships.Add(wxT("Silver"));
        memberships.Add(wxT("Gold"));
        memberships.Add(wxT("Platinum"));
    }
    wxString cv_default_membership(default_membership.c_str(), wxConvUTF8); // converted string to wxString
    
    MembershipCombo = new wxComboBox ( panel, -1, cv_default_membership, 
                                                    wxPoint(85, 180), wxSize(110, -1), 
                                                    memberships, wxCB_READONLY );
    
    
    wxStaticText *BookingLabel = new wxStaticText(panel, wxID_ANY, wxT("Booking: "), 
                                                     wxPoint(5, 225));
    string default_booking = "Walk-In";
    wxArrayString bookings;
    
    // alter booking options based on type of ADT
    if (e_m.find("Red-Black") != std::string::npos ) {
        bookings.Add(wxT("Vacation"));
        default_booking = "Vacation";
    }
    else if (e_m.find("B-Tree") != std::string::npos ) {
        bookings.Add(wxT("Business"));
        default_booking = "Business";
    }
    else if (e_m.find("Set B") != std::string::npos ) {
        bookings.Add(wxT("Walk-In"));
    }
    else {
        bookings.Add(wxT("Vacation"));
        bookings.Add(wxT("Walk-In"));
        bookings.Add(wxT("Business"));
    }
    wxString cv_default_booking(default_booking.c_str(), wxConvUTF8); // converted string to wxString
    BookingCombo = new wxComboBox ( panel, -1, cv_default_booking, 
                                                    wxPoint(75, 220), wxSize(110, -1), 
                                                    bookings, wxCB_READONLY );
    
    
    // OK Button
    wxButton* ok = new wxButton(panel, wxID_OK, wxT("&Ok"), wxPoint(130, 250), 
                                    wxDefaultSize, 0);
    // The CANCEL button
    wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&Cancel"), 
                                    wxPoint(230, 250), wxDefaultSize, 0 );
    // Centre panel
    Centre();
    
}
  
DeleteDialog::DeleteDialog( const wxString& title, const wxPoint& pos, 
                        const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
{
    //The new panel for the DeleteDialog box
    wxPanel    *panel = new wxPanel(this, -1);
    // prompt label
    wxStaticText *prompt   = new wxStaticText(panel, wxID_ANY, wxT("Delete Record with Client ID: "), 
                                                     wxPoint(5, 25));
    
    ClientIDBox = new wxTextCtrl ( panel, wxID_ANY, wxT("Enter ClientID to remove"), 
                                            wxPoint(200, 20), wxSize(190, -1) );
    
    // Delete Button
    wxButton* remove = new wxButton(panel, wxID_OK, wxT("&Delete"), wxPoint(130, 180), 
                                    wxDefaultSize, 0);

    // The CANCEL button
    wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&Cancel"), 
                                    wxPoint(230, 180), wxDefaultSize, 0 );
    // Centre the dialog on the parent's window
    Centre();
    
    
} // DeleteDialog constructor
  


#endif
