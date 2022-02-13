//  Skeleton 01
//  COMP2611 Project Assignment
//
//  Created by Dr. John Charlery on 02/12/2022.
//  Copyright (c) 2022 University of the West Indies. All rights reserved.
//

//============================VERY IMPORTANT=========================================
//		You can use this code as a start-up, BUT, you are required to 
//			modify the code accordingly. You should have your own class
//			names, your own functions' names, etc. You are also required
//			to have documentation within your code.
//
//		DO NOT SIMPLY SUBMIT THE CODE WHICH HAS BEEN GIVEN!
//===================================================================================


/************************************************************************************
  Step 1: Always include the header file wx.h
*************************************************************************************/
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif

#include <fstream> 
#include <string> 


using namespace std;


/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with 
      the function to execute the program                    
*************************************************************************************
*************************************************************************************/
class MyApp: public wxApp
  {
     virtual bool OnInit();
  };

  
  
  
  
/************************************************************************************
*************************************************************************************
   Step 3: Declare the inherited main frame class from wxFrame. In this class 
       also will ALL the events handlers be declared    
*************************************************************************************
*************************************************************************************/
class ProjectFrame: public wxFrame
  {
     private:
        DECLARE_EVENT_TABLE() //To declare events items
    
     public:
        ProjectFrame(const wxString& title, const wxPoint& pos, 
            const wxSize& size);
        
         //Public attributes
        wxTextCtrl* MainEditBox;
        wxTextCtrl* filenameTextBox;
        wxString CurrentFilePath;    // The Path to the file we have open
        
        
       //Functions for File Menu Items
        void OnOpenFile(wxCommandEvent& event);
        void OnDisplay(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);    
        void OnExit(wxCommandEvent& event);     //handle for Quit function
        
        //Functions for Queue Menu Items
        
        //Functions for Priority Queue Menu Items
        
        //Functions for Double Ended Queue Menu Items
        
        //Functions for Stack Menu Items
                
  };

 
  
/************************************************************************************
*************************************************************************************
  Step 4. Declare the compiler directives                    
*************************************************************************************
*************************************************************************************/
DECLARE_APP(MyApp)        // Declare Application class
IMPLEMENT_APP(MyApp)      // Create Application class object
  

enum
    {
          // File menu items
        ID_OpenFile  = wxID_HIGHEST + 1,        //File menu item
        ID_Display,
        ID_Save,
        ID_SaveAs,
        ID_Exit,
         
        // Queue submenu items
        
        // Priority Queue submenu items
        
        // Deque submenu items
        
        // Stack submenu items
        
        // Help submenu items

    };

    
    
BEGIN_EVENT_TABLE ( ProjectFrame, wxFrame )
      // Events for the "File" menu items
      EVT_MENU ( ID_OpenFile,   ProjectFrame::OnOpenFile )   //File Menu 
      EVT_MENU ( ID_Display,    ProjectFrame::OnDisplay )
      EVT_MENU ( ID_Save,       ProjectFrame::OnSave )
      EVT_MENU ( ID_SaveAs,     ProjectFrame::OnSaveAs )
      EVT_MENU ( ID_Exit,       ProjectFrame::OnExit )
    
        
      // Events for the "Queue" menu items
      // Events for the "Priority Queue" menu items
      // Events for the "Deque" menu items
      // Events for the "Stack" menu items
     

END_EVENT_TABLE () 
  




/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool MyApp::OnInit()
  {
      // Create the main application window
      ProjectFrame *frame = new ProjectFrame( wxT("Dummy"), 
                    wxPoint(50,50), 
                    wxSize(250,200) );

      // Display the window
      frame->Show(TRUE);
    
      SetTopWindow(frame);

      return TRUE;

  }
  
  
  

/************************************************************************************
*************************************************************************************
  Step 6:   Define the Constructor functions for the Frame class
*************************************************************************************
*************************************************************************************/
ProjectFrame::ProjectFrame ( const wxString& title, const wxPoint& pos, const wxSize& size)
            : wxFrame((wxFrame *)NULL, -1, title, pos, size)
  {
    // Set the frame icon - optional
    SetIcon(wxIcon(wxT("uwiIcon.xpm")));

    
    
    // Create the main-menu items

    //Create a Menu bar
            
    //Append the main menu items to the Menu Bar
        
    //Append the sub-menu items to the Main Menu items
        
    // Attach the main menu bar to the frame
        
    // Create a status bar
        
    //Put text in the status bar
    
    
    
    
    //Set up the panel for data display
//===============================================================================
//================= DO NOT CHANGE THE CODE IN THIS SECTION ======================    
//===============================================================================

    wxPanel     *panel     = new wxPanel(this, -1);
    wxBoxSizer  *vbox      = new wxBoxSizer(wxVERTICAL);        //Vertical sizer for main window
    wxBoxSizer  *hbox1     = new wxBoxSizer(wxHORIZONTAL);      //Horizontal sizer for main window

    //Add two textboxes to the panel for data display
    wxBoxSizer  *hbox2     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for filename window
    wxBoxSizer  *hbox3     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for display window
    
    wxStaticText *fileLabel     = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
    wxStaticText *displayLabel     = new wxStaticText(panel, wxID_ANY, wxT("Display"));

    //Initialize the filename textbox window
    filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));
    
    //Initialize the display window
    MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."), 
                      wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);
                      
    //Position the labels and textboxes in the panel
    hbox1->Add(fileLabel, 0, wxRIGHT, 8);
    hbox1->Add(filenameTextBox, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    vbox->Add(-1, 10);
    hbox2->Add(displayLabel, 0);
    vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
    vbox->Add(-1, 10);

    hbox3->Add(MainEditBox, 1, wxEXPAND);
    vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

    vbox->Add(-1, 25);
    panel->SetSizer(vbox);

    Centre();
    
  }


//=====================================================================
//=========== Other Support Functions =================================
//=====================================================================
    
  

  
/**************************************************************************
***************************************************************************
  Step 7:  Define member functions for the Frame class
***************************************************************************
***************************************************************************/



//=========================================================================
//======== Definition for the File Functions ==============================
//=========================================================================

void ProjectFrame::OnOpenFile(wxCommandEvent& event )
    {
        // Creates a "open file" dialog with 3 file types
        wxFileDialog *OpenDialog = new wxFileDialog( this, 
             (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
             (wxT("Data Files (*.dat)|*.dat|All files (*.*)|*.*")), wxFD_OPEN, wxDefaultPosition);
 
        if (OpenDialog->ShowModal() == wxID_OK)    // if the user click "Open" instead of "cancel"
        {
            // Sets our current document to the file the user selected
            CurrentFilePath = OpenDialog->GetPath();

            //Clean up filename textbox and Display file name in filename textbox 
            filenameTextBox->Clear();
            filenameTextBox->AppendText(CurrentFilePath);

            MainEditBox->LoadFile(CurrentFilePath);   //Opens that file in the MainEditBox

            // Set the Title
            SetTitle(wxString(wxT("Dummy")));
        }

    }
 

 

void ProjectFrame::OnSave(wxCommandEvent& event )
    {
        // Save to the already-set path for the document
        MainEditBox->SaveFile();
    }
  
  
  
void ProjectFrame::OnSaveAs(wxCommandEvent& event)
    {
    	wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")), 
                            wxEmptyString, wxEmptyString,
                            (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
                            wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

        // Creates a Save Dialog with 4 file types
        if (SaveDialog->ShowModal() == wxID_OK)     // If the user clicked "OK"
            {
                CurrentFilePath = SaveDialog->GetPath();

                // set the path of our current document to the file the user chose to save under
                MainEditBox->SaveFile(CurrentFilePath); // Save the file to the selected path

                // Set the Title to reflect the file open
                SetTitle(wxString(wxT("Dummy Again")));
        }
        
    }
  
 
 
 
void ProjectFrame::OnDisplay(wxCommandEvent& event )
    {
        // Creates a "open file" dialog with 4 file types
        wxFileDialog *OpenDialog = new wxFileDialog( this, (wxT("Choose a file to open")), 
                wxEmptyString, wxEmptyString,
                (wxT("Data Files (*.dat)|*.dat|All files (*.*)|*.*")),
                wxFD_OPEN, wxDefaultPosition);

        MainEditBox->Clear();

        MainEditBox->LoadFile(CurrentFilePath); 
    }
  
  

  
void ProjectFrame::OnExit(wxCommandEvent& event)
    {
        wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
        Close(TRUE); // Close the window
    }



  
//=============================================================================
//============== Definition for the Queue Functions ===========================
//=============================================================================




//=============================================================================
//============== Definition for the Priority Queue Functions ==================
//=============================================================================




//=============================================================================
//============== Definition for the Deque Functions ===========================
//=============================================================================




//=============================================================================
//============== Definition for the Stack Functions ===========================
//=============================================================================





