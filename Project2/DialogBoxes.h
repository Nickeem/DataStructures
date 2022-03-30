#ifndef DIALOGBOXES_H
#define DIALOGBOXES_H


#include <string>    
  

class InfoDialog: public wxDialog
{
        public:
                InfoDialog(const wxString& title, const wxPoint& pos, const wxSize& size);                    
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
  
DeleteDialog::DeleteDialog( const wxString& title, const wxPoint& pos, 
                        const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
{
    //The new panel for the DeleteDialog box
    wxPanel    *panel = new wxPanel(this, -1);
    // prompt label
    wxStaticText *prompt   = new wxStaticText(panel, wxID_ANY, wxT("Delete Record with Client ID: "), 
                                                     wxPoint(5, 25));
    
    ClientIDBox = new wxTextCtrl ( panel, wxID_ANY, wxT("Enter ClientID to remove"), 
                                            wxPoint(50, 20), wxSize(220, -1) );
    
    // Delete Button
    wxButton* remove = new wxButton(panel, wxID_OK, wxT("&Delete"), wxPoint(130, 180), 
                                    wxDefaultSize, 0);

    // The CANCEL button
    wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&CANCEL"), 
                                    wxPoint(230, 180), wxDefaultSize, 0 );
    // Centre the dialog on the parent's window
    Centre();
    
    
} // DeleteDialog constructor
  


#endif
