#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif

#include <fstream> 
#include <string> 
#include "Deque.h"
#include "Node.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Stack.h"
// g++ main.cpp -o runlol `wx-config --libs --cxxflags`

using namespace std;

class MyApp: public wxApp
{
     virtual bool OnInit();
};

class ProjectFrame: public wxFrame
{
     private:
        DECLARE_EVENT_TABLE() //To declare events items
        Deque deque;
        PriorityQueue pQueue;
        Queue queue;
        Stack stack;
        vector<string> fileData;

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
        
        // About function
        void About(wxCommandEvent& event);

        //Functions for Queue Menu Items
        void queueDisplay(wxCommandEvent& event);
        void queueHead(wxCommandEvent& event);
        void queueTail(wxCommandEvent& event);
        void queueDequeue(wxCommandEvent& event);
        //Functions for Priority Queue Menu Items
        void priorityQueueDisplay(wxCommandEvent& event);
        void priorityQueueHead(wxCommandEvent& event);
        void priorityQueueTail(wxCommandEvent& event);
        void priorityDequeue(wxCommandEvent& event);
        //Functions for Double Ended Queue Menu Items
        void dequeDisplay(wxCommandEvent& event);
        void dequeHead(wxCommandEvent& event);
        void dequeTail(wxCommandEvent& event);
        void deque_DQ_Head(wxCommandEvent& event);
        void deque_DQ_Tail(wxCommandEvent& event);
        //Functions for Stack Menu Items
        void stackDisplay(wxCommandEvent& event);
        void stackHead(wxCommandEvent& event);
        void stackTail(wxCommandEvent& event);
        void stackPop(wxCommandEvent& event);
        

};

DECLARE_APP(MyApp)        // Declare Application class
IMPLEMENT_APP(MyApp)      // Create Application class object


enum
    {
     // File menu items
	ID_OpenFile  = wxID_HIGHEST + 1,  //File menu item
	ID_Display,
	ID_Save,
	ID_SaveAs,
	ID_Exit,
    ID_Help,

	// Queue submenu items
    ID_Q_Display,
    ID_Q_Head,
    ID_Q_Tail,
    ID_Q_Dequeue,
	// Priority Queue submenu items
    ID_PQ_Display,
    ID_PQ_Head,
    ID_PQ_Tail,
    ID_PQ_Dequeue,
	// Deque submenu items
    ID_D_Display,
    ID_D_Head,
    ID_D_Tail,
    ID_D_DqHead,
    ID_D_DqTail,
	// Stack submenu items
    ID_S_Display,
    ID_S_Head,
    ID_S_Tail,
    ID_S_Pop,
	// Help submenu items
    ID_About,
    ID,Exit,
    };

BEGIN_EVENT_TABLE ( ProjectFrame, wxFrame )
	// Events for the "File" menu items
  	EVT_MENU ( ID_OpenFile,   ProjectFrame::OnOpenFile )   //File Menu
   	EVT_MENU ( ID_Display,    ProjectFrame::OnDisplay )
   	EVT_MENU ( ID_Save,       ProjectFrame::OnSave )
   	EVT_MENU ( ID_SaveAs,     ProjectFrame::OnSaveAs )
   	EVT_MENU ( ID_Exit,       ProjectFrame::OnExit )

	// Events for the "Queue" menu items
    EVT_MENU( ID_Q_Display , ProjectFrame::queueDisplay)
    EVT_MENU( ID_Q_Head , ProjectFrame::queueHead)
    EVT_MENU( ID_Q_Tail , ProjectFrame::queueTail)
    EVT_MENU( ID_Q_Dequeue , ProjectFrame::queueDequeue)
	// Events for the "Priority Queue" menu items    
    EVT_MENU( ID_PQ_Display , ProjectFrame::priorityQueueDisplay)
    EVT_MENU( ID_PQ_Head , ProjectFrame::priorityQueueHead)
    EVT_MENU( ID_PQ_Tail , ProjectFrame::priorityQueueTail)
    EVT_MENU( ID_PQ_Dequeue , ProjectFrame::priorityDequeue)
 	// Events for the "Deque" menu items
    EVT_MENU( ID_D_Display , ProjectFrame::dequeDisplay)
    EVT_MENU( ID_D_Head , ProjectFrame::dequeHead)
    EVT_MENU( ID_D_Tail , ProjectFrame::dequeTail)
    EVT_MENU( ID_D_DqHead , ProjectFrame::deque_DQ_Head)
    EVT_MENU( ID_D_DqTail , ProjectFrame::deque_DQ_Tail)

 	// Events for the "Stack" menu items
    EVT_MENU( ID_S_Display , ProjectFrame::stackDisplay)
    EVT_MENU( ID_S_Head , ProjectFrame::stackHead)
    EVT_MENU( ID_S_Tail , ProjectFrame::stackTail)
    EVT_MENU( ID_S_Pop , ProjectFrame::stackPop)

END_EVENT_TABLE ()


bool MyApp::OnInit()
  {
      // Create the main application window
      ProjectFrame *frame = new ProjectFrame( wxT("COMP2611 - Data Structures Project #1"),
                    wxPoint(50,50),
                    wxSize(650,400) );

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
 	// SetIcon(wxIcon(wxT("uwiIcon.xpm")));



	// Create the main-menu items
	wxMenu *fileMenu = new wxMenu;
	wxMenu *queueMenu = new wxMenu;
	wxMenu *dequeMenu = new wxMenu;    
	wxMenu *priorityQueueMenu = new wxMenu; 
	wxMenu *stackMenu = new wxMenu; 
	wxMenu *helpMenu = new wxMenu; 
    
    //Create a Menu bar
    wxMenuBar *menuBar = new wxMenuBar();

    //Append the main menu items to the Menu Bar
    menuBar->Append(fileMenu, wxT("File"));
    menuBar->Append(queueMenu, wxT("Queue"));
    menuBar->Append(priorityQueueMenu, wxT("Priority Queue"));
    menuBar->Append(dequeMenu, wxT("Deque"));
    menuBar->Append(stackMenu, wxT("Stack"));
    menuBar->Append(helpMenu, wxT("Help"));
    //Append the sub-menu items to the Main Menu items
    fileMenu->Append(ID_OpenFile, wxT("Open File"), wxT(""));
    fileMenu->Append(ID_Display, wxT("Display File"), wxT(""));
    fileMenu->Append(ID_Save, wxT("Save"), wxT(""));
    fileMenu->Append(ID_SaveAs, wxT("Save As"), wxT(""));
    fileMenu->Append(ID_Exit, wxT("Exit"), wxT(""));
    
    queueMenu->Append( ID_Q_Display , wxT("Display All") );
    queueMenu->Append( ID_Q_Head , wxT("Show Head") );
    queueMenu->Append( ID_Q_Tail , wxT("Show Tail") );
    queueMenu->Append( ID_Q_Dequeue , wxT("Dequeue") );
    
    priorityQueueMenu->Append( ID_PQ_Display , wxT("Display All") );
    priorityQueueMenu->Append( ID_PQ_Head , wxT("Show Head") );
    priorityQueueMenu->Append( ID_PQ_Tail , wxT("Show Tail") );
    priorityQueueMenu->Append( ID_PQ_Dequeue , wxT("Dequeue") );
    
    dequeMenu->Append( ID_D_Display , wxT("Display All") );
    dequeMenu->Append( ID_D_Head , wxT("Show Head") );
    dequeMenu->Append( ID_D_Tail , wxT("Show Tail") );
    dequeMenu->Append( ID_D_DqHead , wxT("Dequeue Head") );
    dequeMenu->Append( ID_D_DqTail , wxT("Dequeue Tail") );
    
    stackMenu->Append( ID_S_Display , wxT("Display All") );
    stackMenu->Append( ID_S_Head , wxT("Show Head") );
    stackMenu->Append( ID_S_Tail , wxT("Show Tail") );
    stackMenu->Append( ID_S_Pop , wxT("Pop") );
    
    helpMenu->Append( ID_About , wxT("About"));
    helpMenu->Append( ID_Exit , wxT("Exit"));
    
    

    // Attach the main menu bar to the frame
    SetMenuBar(menuBar);
    // Create a status bar
    CreateStatusBar(3);
    SetStatusText( wxT("Ready..."), 0);
    SetStatusText( wxT("Nickeem Payne-Deacon"), 1);
    SetStatusText( wxT("400008889"), 2);

    //Put text in the status bar




    //Set up the panel for fileData display
//===============================================================================
//================= DO NOT CHANGE THE CODE IN THIS SECTION ======================
//===============================================================================

    wxPanel     *panel     = new wxPanel(this, -1);
    wxBoxSizer  *vbox      = new wxBoxSizer(wxVERTICAL);        //Vertical sizer for main window
    wxBoxSizer  *hbox1     = new wxBoxSizer(wxHORIZONTAL);      //Horizontal sizer for main window

    //Add two textboxes to the panel for fileData display
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
            
            
            ifstream infile ( CurrentFilePath.mb_str() ); // for filling objects
            short int c = -1;
            //vector<string> fileData;
            string info;
            
            while (getline(infile, info)) {
                /* deque, pQueue, queue, stack; */
                if (c == -1) {
                    c++;   
                    continue;
                }
                fileData.push_back(info);
                queue.enqueue(new Node(&fileData.at(c)));
                if (fileData.at(c).find("Platinum") != std::string::npos || fileData.at(c).find("Gold") != std::string::npos) {
                    //pQueue.enqueue(new Node(&fileData.at(c)));
                }
                if (fileData.at(c).find("Vacation") != std::string::npos) {
                    deque.enqueueHead(new Node(&fileData.at(c)));
                }
                if (fileData.at(c).find("Business") != std::string::npos) {
                    deque.enqueueTail(new Node(&fileData.at(c)));
                }
                if (fileData.at(c).find("Walk-in") != std::string::npos) {
                    stack.push(new Node(&fileData.at(c)));
                }
                c++;
            }
             
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


void ProjectFrame::About(wxCommandEvent& event) {}


//=============================================================================
//============== Definition for the Queue Functions ===========================
//=============================================================================
void ProjectFrame::queueDisplay(wxCommandEvent& event) {
    MainEditBox->Clear();
    MainEditBox->AppendText(queue.showHead());
}
void ProjectFrame::queueHead(wxCommandEvent& event) {}
void ProjectFrame::queueTail(wxCommandEvent& event) {}
void ProjectFrame::queueDequeue(wxCommandEvent& event) {}



//=============================================================================
//============== Definition for the Priority Queue Functions ==================
//=============================================================================
void ProjectFrame::priorityQueueDisplay(wxCommandEvent& event) {}
void ProjectFrame::priorityQueueHead(wxCommandEvent& event) {}
void ProjectFrame::priorityQueueTail(wxCommandEvent& event) {}
void ProjectFrame::priorityDequeue(wxCommandEvent& event) {}



//=============================================================================
//============== Definition for the Deque Functions ===========================
//=============================================================================
void ProjectFrame::dequeDisplay(wxCommandEvent& event) {}
void ProjectFrame::dequeHead(wxCommandEvent& event) {}
void ProjectFrame::dequeTail(wxCommandEvent& event) {}
void ProjectFrame::deque_DQ_Head(wxCommandEvent& event) {}
void ProjectFrame::deque_DQ_Tail(wxCommandEvent& event) {}



//=============================================================================
//============== Definition for the Stack Functions ===========================
//=============================================================================
void ProjectFrame::stackDisplay(wxCommandEvent& event) {}
void ProjectFrame::stackHead(wxCommandEvent& event) {}
void ProjectFrame::stackTail(wxCommandEvent& event) {}
void ProjectFrame::stackPop(wxCommandEvent& event) {}
