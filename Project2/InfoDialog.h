//
//  DataDialog.h
//  DataDialog
//
//  Created by Dr. John Charlery on 02/13/2022.
//  Copyright (c) 2022 University of the West Indies. All rights reserved.
//

// // used and edited by Nickeem Payne-Deacon for Assignment


#ifndef INFODIALOG_H
#define INFODIALOG_H


#include <string>    
  
//Define a info box class with the 4 data fields (Attributes) - inheriting from wxDialog, of course
// only constructor in edited use
class InfoDialog: public wxDialog
    {
        public:
                InfoDialog(const wxString& title, const wxPoint& pos, const wxSize& size);                    
    };

    
    
    
    
    
//-----------------------------------------------------------------------------------------
// The constructor function for the InfoDialog class - this is where it all happens
//-----------------------------------------------------------------------------------------
InfoDialog::InfoDialog ( const wxString& title, const wxPoint& pos, 
                        const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
    {
      
        //The new new panel for the DataDialog box
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
 
                
        //------------------------------------------------------------------------------------------
        //Define and position the StaticTexts - the labels
        //------------------------------------------------------------------------------------------
        wxStaticText *programmerName   = new wxStaticText(panel, wxID_ANY, wxT("Programmer Name: Nickeem Payne-Deacon"), 
                                                     wxPoint(5, 25));
        wxStaticText *program = new wxStaticText(panel, wxID_ANY, wxT("Program: Testing Abstract Data Types using file data"), 
                                                     wxPoint(5, 70) );
        wxStaticText *systemArchitecture = new wxStaticText(panel, wxID_ANY, wxT(" System: "+sys_arch), 
                                                     wxPoint(5, 115) );

        
        //------------------------------------------------------------------------------------------
        // Define and position the Response buttons (OK and CANCEL)
        //------------------------------------------------------------------------------------------
    
        // The OK button
        wxButton* close = new wxButton(panel, wxID_OK, wxT("&Close"), wxPoint(180, 180), 
                                    wxDefaultSize, 0);

        // The CANCEL button
        //wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&CANCEL"), 
          //                                wxPoint(230, 180), wxDefaultSize, 0 );
    
        // Centre the dialog on the parent's window
        Centre();

        // Maximize(); // Maximize the window
    
  }
  


#endif
