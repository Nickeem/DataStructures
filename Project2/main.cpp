#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif

using namespace std;

#include <fstream> 
#include <string> 
#include <sstream>
#include <iomanip>


// record struct
struct record
{
    int id;
    char firstname[10];
    char surname[10];
    char destination[15];
    char membership[10];
    char booking[10];
};
typedef struct record Record;

// include data Structures
#include "BSTree.h"
#include  "AVLTree.h"
#include "RBTree.h"
#include  "SplayTree.h"
#include  "BinHeap.h"
#include  "BTree.h"
#include  "Set.h"
#include "DialogBoxes.h"
// g++ main.cpp -o runlol `wx-config --libs --cxxflags`



class MyApp: public wxApp
{
     virtual bool OnInit();
};

class ProjectFrame: public wxFrame
{
     private:
        DECLARE_EVENT_TABLE() //To declare events items
        
         BST *bs_tree;
         AVL *avl_tree;
         RBT *rb_tree;
         SplayTree *splay_tree;
         BinHeap *heap;
         Set *setA;
         Set *setB;
         
         
         BTree *b_tree;
         
         
        string opened_fileName;

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

        //Functions for Binary Search Tree Menu Items
        void createBST(wxCommandEvent& event);
        void BST_addRecord(wxCommandEvent& event);
        void BST_deleteRecord(wxCommandEvent& event);
        void BST_display_inOrder(wxCommandEvent& event);
        void BST_displayp_preOrder(wxCommandEvent& event);
        void BST_display_postOrder(wxCommandEvent& event);
        //Functions for AVL Tree Menu Items 
        void createAVL(wxCommandEvent& event);
        void AVL_addRecord(wxCommandEvent& event);
        void AVL_deleteRecord(wxCommandEvent& event);
        void AVL_display_inOrder(wxCommandEvent& event);
        void AVL_displayp_preOrder(wxCommandEvent& event);
        void AVL_display_postOrder(wxCommandEvent& event);
        //Functions for Red Black Tree Menu Items
        void createRBT(wxCommandEvent& event);
        void RBT_addRecord(wxCommandEvent& event);
        void RBT_deleteRecord(wxCommandEvent& event);
        void RBT_display_inOrder(wxCommandEvent& event);
        void RBT_displayp_preOrder(wxCommandEvent& event);
        void RBT_display_postOrder(wxCommandEvent& event);
        //Functions for Splay Tree Menu Items
        void createSplayT(wxCommandEvent& event);
        void SplayT_addRecord(wxCommandEvent& event);
        void SplayT_deleteRecord(wxCommandEvent& event);
        void SplayT_display_inOrder(wxCommandEvent& event);
        void SplayT_displayp_preOrder(wxCommandEvent& event);
        void SplayT_display_postOrder(wxCommandEvent& event);
        //Functions for Heao Menu Items
        void createHeap(wxCommandEvent& event);
        void Heap_addRecord(wxCommandEvent& event);
        void Heap_deleteRecord(wxCommandEvent& event);
        void Heap_displayAll(wxCommandEvent& event);
        void HeapSort(wxCommandEvent& event);
        
        //Functions for B Tree Menu Items
        void createBTree(wxCommandEvent& event);
        void BTree_addRecord(wxCommandEvent& event);
        void BTree_deleteRecord(wxCommandEvent& event);
        void BTree_displayAll(wxCommandEvent& event);
        
        //Functions for Set
        void createSets(wxCommandEvent& event);
        void AddtoSetA(wxCommandEvent& event);
        void AddtoSetB(wxCommandEvent& event);
        void displaySetA(wxCommandEvent& event);
        void displaySetB(wxCommandEvent& event);
        void displayIntersection(wxCommandEvent& event);
        void displayUnion(wxCommandEvent& event);
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

	// Binary Search Tree submenu items
    ID_BST_Create,
    ID_BST_Add,
    ID_BST_Delete,
    ID_BST_Display_IO,
    ID_BST_Display_PrO,
    ID_BST_Display_PoO,
	// AVL Search Tree submenu items
    ID_AVL_Create,
    ID_AVL_Add,
    ID_AVL_Delete,
    ID_AVL_Display_IO,
    ID_AVL_Display_PrO,
    ID_AVL_Display_PoO,
	// Red Black Tree submenu items
    ID_RBT_Create,
    ID_RBT_Add,
    ID_RBT_Delete,
    ID_RBT_Display_IO,
    ID_RBT_Display_PrO,
    ID_RBT_Display_PoO,
	// Splay Tree submenu items
    ID_SplayT_Create,
    ID_SplayT_Add,
    ID_SplayT_Delete,
    ID_SplayT_Display_IO,
    ID_SplayT_Display_PrO,
    ID_SplayT_Display_PoO,
	// Heap submenu items
    ID_Heap_Create,
    ID_Heap_Add,
    ID_Heap_Delete,
    ID_Heap_Display,
    ID_Heap_Sort,
	// B Tree submenu items
    ID_BTree_Create,
    ID_BTree_Add,
    ID_BTree_Delete,
    ID_BTree_Display,
    // Set submenu items
    ID_Set_Create,
    ID_Set_AddA,
    ID_Set_AddB,
    ID_Set_DisplayA,
    ID_Set_DisplayB,
    ID_Set_DisplayIntersection,
    ID_Set_DisplayUnion,

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
    
    // About menu item
    EVT_MENU ( ID_About,       ProjectFrame::About)

	// Events for the "Binary Search Tree" menu items
    EVT_MENU( ID_BST_Create , ProjectFrame::createBST)
    EVT_MENU( ID_BST_Add , ProjectFrame::BST_addRecord)
    EVT_MENU( ID_BST_Delete , ProjectFrame::BST_deleteRecord)
    EVT_MENU( ID_BST_Display_IO , ProjectFrame::BST_display_inOrder)
    EVT_MENU( ID_BST_Display_PrO , ProjectFrame::BST_displayp_preOrder)
    EVT_MENU( ID_BST_Display_PoO , ProjectFrame::BST_display_postOrder)
    
    // Events for the "AVL Tree" menu items
    EVT_MENU( ID_AVL_Create , ProjectFrame::createAVL)
    EVT_MENU( ID_AVL_Add , ProjectFrame::AVL_addRecord)
    EVT_MENU( ID_AVL_Delete , ProjectFrame::AVL_deleteRecord)
    EVT_MENU( ID_AVL_Display_IO , ProjectFrame::AVL_display_inOrder)
    EVT_MENU( ID_AVL_Display_PrO , ProjectFrame::AVL_displayp_preOrder)
    EVT_MENU( ID_AVL_Display_PoO , ProjectFrame::AVL_display_postOrder)
    
    // Events for the "Red Black Tree" menu items
    EVT_MENU( ID_RBT_Create , ProjectFrame::createRBT)
    EVT_MENU( ID_RBT_Add , ProjectFrame::RBT_addRecord)
    EVT_MENU( ID_RBT_Delete , ProjectFrame::RBT_deleteRecord)
    EVT_MENU( ID_RBT_Display_IO , ProjectFrame::RBT_display_inOrder)
    EVT_MENU( ID_RBT_Display_PrO , ProjectFrame::RBT_displayp_preOrder)
    EVT_MENU( ID_RBT_Display_PoO , ProjectFrame::RBT_display_postOrder)
    
    // Events for the "Splay Tree" menu items
    EVT_MENU( ID_SplayT_Create , ProjectFrame::createSplayT)
    EVT_MENU( ID_SplayT_Add , ProjectFrame::SplayT_addRecord)
    EVT_MENU( ID_SplayT_Delete , ProjectFrame::SplayT_deleteRecord)
    EVT_MENU( ID_SplayT_Display_IO , ProjectFrame::SplayT_display_inOrder)
    EVT_MENU( ID_SplayT_Display_PrO , ProjectFrame::SplayT_displayp_preOrder)
    EVT_MENU( ID_SplayT_Display_PoO , ProjectFrame::SplayT_display_postOrder)
    
    // Events for the "Heap" menu items
    EVT_MENU( ID_Heap_Create, ProjectFrame::createHeap)
    EVT_MENU( ID_Heap_Add, ProjectFrame::Heap_addRecord)
    EVT_MENU( ID_Heap_Delete, ProjectFrame::Heap_deleteRecord)
    EVT_MENU( ID_Heap_Display, ProjectFrame::Heap_displayAll)
    EVT_MENU( ID_Heap_Sort, ProjectFrame::HeapSort)
    
    // Events for the "B Tree" menu items
    EVT_MENU( ID_BTree_Create, ProjectFrame::createBTree)
    EVT_MENU( ID_BTree_Add, ProjectFrame::BTree_addRecord)
    EVT_MENU( ID_BTree_Delete, ProjectFrame::BTree_deleteRecord)
    EVT_MENU( ID_BTree_Display, ProjectFrame::BTree_displayAll)
    
    // Events for the "Set" menu items
    EVT_MENU( ID_Set_Create, ProjectFrame::createSets)
    EVT_MENU( ID_Set_AddA, ProjectFrame::AddtoSetA)
    EVT_MENU( ID_Set_AddB, ProjectFrame::AddtoSetB)
    EVT_MENU( ID_Set_DisplayA, ProjectFrame::displaySetA)
    EVT_MENU( ID_Set_DisplayB, ProjectFrame::displaySetB)
    EVT_MENU( ID_Set_DisplayIntersection, ProjectFrame::displayIntersection)
    EVT_MENU( ID_Set_DisplayUnion, ProjectFrame::displayUnion)


END_EVENT_TABLE ()


bool MyApp::OnInit()
  {
      // Create the main application window
      ProjectFrame *frame = new ProjectFrame( wxT("COMP2611 - Data Structures Project #1"),
                    wxPoint(50,50),
                    wxSize(950,400) );

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
    // Create ADTs
    // create new trees
    bs_tree = new BST();
    avl_tree = new AVL();
    rb_tree = new RBT();
    splay_tree = new SplayTree();
    heap = new BinHeap();
    setA = new Set();
    setB = new Set();
    heap = new BinHeap();
    b_tree = new BTree();

	// Create the main-menu items
	wxMenu *fileMenu = new wxMenu;
	wxMenu *bstMenu = new wxMenu;
	wxMenu *avlMenu = new wxMenu;    
	wxMenu *heapMenu = new wxMenu; 
	wxMenu *rbtMenu = new wxMenu;
    wxMenu *splayMenu = new wxMenu;
    wxMenu *btMenu = new wxMenu;
    wxMenu *setsMenu = new wxMenu;
	wxMenu *helpMenu = new wxMenu; 
    
    //Create a Menu bar
    wxMenuBar *menuBar = new wxMenuBar();

    //Append the main menu items to the Menu Bar
    menuBar->Append(fileMenu, wxT("File"));
    menuBar->Append(bstMenu, wxT("BST"));
    menuBar->Append(avlMenu, wxT("AVL Tree"));
    menuBar->Append(heapMenu, wxT("Heap"));
    menuBar->Append(rbtMenu, wxT("Red-Black Tree"));
    menuBar->Append(splayMenu, wxT("Splay Tree"));
    menuBar->Append(btMenu, wxT("B-Tree"));
    menuBar->Append(setsMenu, wxT("Sets"));
    menuBar->Append(helpMenu, wxT("Help"));
    
    //Append the sub-menu items to the Main Menu items
    fileMenu->Append(ID_OpenFile, wxT("Open File"), wxT("Load file into application"));
    fileMenu->Append(ID_Display, wxT("Display File"), wxT("View contents of opened file"));
    fileMenu->Append(ID_Save, wxT("Save"), wxT("Save File"));
    fileMenu->Append(ID_SaveAs, wxT("Save As"), wxT("Save File with new name"));
    fileMenu->Append(ID_Exit, wxT("Exit"), wxT("Close Application"));
    
    bstMenu->Append( ID_BST_Create, wxT("Create BST"), wxT("Create the BST from the RAF"));
    bstMenu->Append( ID_BST_Add, wxT("Add a Record"),wxT("Manually add a record to the BST"));
    bstMenu->Append( ID_BST_Delete, wxT("Delete a Record"), wxT("Delete a specified record from the BST"));
    bstMenu->Append( ID_BST_Display_IO, wxT("Inorder"), wxT("Display the inorder traversal result of the BST"));
    bstMenu->Append( ID_BST_Display_PrO, wxT("Preorder"), wxT("Display the preorder traversal result of the BST"));
    bstMenu->Append( ID_BST_Display_PoO, wxT("Postorder"), wxT("Display the postorder traversal result of the BST"));
    
    avlMenu->Append( ID_AVL_Create, wxT("Create AVL"), wxT("Create the AVL from the RAF"));
    avlMenu->Append( ID_AVL_Add, wxT("Add a Record"),wxT("Manually add a record to the AVL"));
    avlMenu->Append( ID_AVL_Delete, wxT("Delete a Record"), wxT("Delete a specified record from the AVL tree:"));
    avlMenu->Append( ID_AVL_Display_IO, wxT("Inorder"), wxT("Display the inorder traversal result of the AVL"));
    avlMenu->Append( ID_AVL_Display_PrO, wxT("Preorder"), wxT("Display the preorder traversal result of the AVL"));
    avlMenu->Append( ID_AVL_Display_PoO, wxT("Postorder"), wxT("Display the postorder traversal result of the AVL"));
    
    rbtMenu->Append( ID_RBT_Create, wxT("Create RBT"), wxT("Create the Red-Black tree from the RAF"));
    rbtMenu->Append( ID_RBT_Add, wxT("Add a Record"),wxT("Manually add a record to the Red-Black tree"));
    rbtMenu->Append( ID_RBT_Delete, wxT("Delete a Record"), wxT("Delete a specified record from the Red-Black tree"));
    rbtMenu->Append( ID_RBT_Display_IO, wxT("Inorder"), wxT("Display the inorder traversal result of the Red-Black tree"));
    rbtMenu->Append( ID_RBT_Display_PrO, wxT("Preorder"), wxT("Display the preorder traversal result of the Red-Black tree"));
    rbtMenu->Append( ID_RBT_Display_PoO, wxT("Postorder"), wxT("Display the postorder traversal result of the Red-Black tree"));
    
    splayMenu->Append( ID_SplayT_Create, wxT("CreateSplay"), wxT("Create the Splay tree from the RAF"));
    splayMenu->Append( ID_SplayT_Add, wxT("Add a Record"),wxT("Manually add a record to the Splay tree"));
    splayMenu->Append( ID_SplayT_Delete, wxT("Delete a Record"), wxT("Delete a specified record from the Splay tree"));
    splayMenu->Append( ID_SplayT_Display_IO, wxT("Inorder"), wxT("Display the inorder traversal result of the Splay tree"));
    splayMenu->Append( ID_SplayT_Display_PrO, wxT("Preorder"), wxT("Display the preorder traversal result of the Splay tree"));
    splayMenu->Append( ID_SplayT_Display_PoO, wxT("Postorder"), wxT("Display the postorder traversal result of the Splay tree"));
    
    heapMenu->Append( ID_Heap_Create, wxT("Create Heap"), wxT("Create the MinHeap tree from the RAF"));
    heapMenu->Append( ID_Heap_Add, wxT("Add a Record"), wxT("Manually add a record to the MinHeap"));
    heapMenu->Append( ID_Heap_Delete, wxT("Delete a Record"), wxT("Delete a specified record from the MinHeap tree"));
    heapMenu->Append( ID_Heap_Display, wxT("Display All"), wxT("Display ALL the inorder in the MinHeap tree"));
    heapMenu->Append( ID_Heap_Sort, wxT("Heap Sort"), wxT("Display the results of the Heap Sort of the MinHeap tree"));
    
    btMenu->Append( ID_BTree_Create, wxT("Create B-Tree"), wxT("Create the B-Tree from the RAF"));
    btMenu->Append( ID_BTree_Add, wxT("Add a Record"), wxT("Manually add a record to the B-Tree"));
    btMenu->Append( ID_BTree_Delete, wxT("Delete a Record"), wxT("Delete a specified record from the B-Tree"));
    btMenu->Append( ID_BTree_Display, wxT("Display ALL"), wxT("Display ALL the records in the B-Tree"));
    
     setsMenu->Append( ID_Set_Create, wxT("Create Sets"), wxT("Create SetA and Set B from the RAF"));
     setsMenu->Append( ID_Set_AddA, wxT("Add Data to SetA"), wxT("Manually add a record to Set A"));
     setsMenu->Append( ID_Set_AddB, wxT("Add Data to SetB"), wxT("SetB Manually add a record to Set B"));
     setsMenu->Append( ID_Set_DisplayA, wxT("Display SetA"), wxT("Display ALL the records in jn Set A"));
     setsMenu->Append( ID_Set_DisplayB, wxT("Display SetB"), wxT("Display ALL the records in jn Set B"));
     setsMenu->Append( ID_Set_DisplayIntersection, wxT("Display Intersection"), wxT("Display the Intersection records of Set A and Set B"));
     setsMenu->Append( ID_Set_DisplayUnion, wxT("Display Union"), wxT("Display Union Display the Union records of Set A and Set B"));
     
    
    helpMenu->Append( ID_About , wxT("About"), wxT("Program Info"));
    helpMenu->Append( ID_Exit , wxT("Exit"), wxT(""));
    
    

    // Attach the main menu bar to the frame
    SetMenuBar(menuBar);
    // Create a status bar
    CreateStatusBar(3);
    SetStatusText( wxT("Ready..."), 0);
    SetStatusText( wxT("Nickeem Payne-Deacon"), 1);
    SetStatusText( wxT("400008889"), 2);
    
    fileMenu->SetHelpString(0, wxT("Basic File Options"));

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
    wxFont myFont(10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL, false);
    MainEditBox->SetDefaultStyle(wxTextAttr(*wxBLACK, wxNullColour, myFont));

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
//=========== Other Support =================================
//=====================================================================

// Struct for transfering data to from random access file



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
             (wxT("Data Files (*.dat)|*.dat| Text(*.txt)|*.txt |All files (*.*)|*.*")), wxFD_OPEN, wxDefaultPosition);

        if (OpenDialog->ShowModal() == wxID_OK)    // if the user click "Open" instead of "cancel"
        {
            // Sets our current document to the file the user selected
            CurrentFilePath = OpenDialog->GetPath();

            //Clean up filename textbox and Display file name in filename textbox
            filenameTextBox->Clear();
            filenameTextBox->AppendText(CurrentFilePath);
            
            MainEditBox->Clear();
            //MainEditBox->LoadFile(CurrentFilePath);   //Opens that file in the MainEditBox
            opened_fileName = CurrentFilePath.mb_str(); // store file path / name of opened file
            
            
            fstream infile(opened_fileName, ios::in|ios::binary);
            Record rec;
            infile.seekg(0);
            stringstream output_stream;
            string output = "";
            
            // clear current trees in ADTs
            delete bs_tree;
            delete avl_tree;
            delete rb_tree;
            delete splay_tree;
            delete setA;
            delete setB;
            delete heap;
            delete b_tree;
            // delete heap;
            
            // create new trees
            bs_tree = new BST();
            avl_tree = new AVL();
            rb_tree = new RBT();
            splay_tree = new SplayTree();
            heap = new BinHeap();
            setA = new Set();
            setB = new Set();
            heap = new BinHeap();
            b_tree = new BTree();
                
            while (!infile.eof())
            {
                infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
                
                output_stream << left << setw(15) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                output = output_stream.str();
                wxString mystring(output.c_str(), wxConvUTF8);
                MainEditBox->AppendText(mystring);
                output_stream.str("");
                
                
                
                // fill ADTs
                bs_tree->insert(rec);
                heap->addMinHeap(rec);
                if (strcmp(rec.membership, "Platinum") == 0 || strcmp(rec.membership, "Gold") == 0)
                    avl_tree->insert(rec);
                if (strcmp(rec.booking, "Vacation") == 0 )
                    rb_tree->insert(rec);
                if (strcmp(rec.membership, "Silver") == 0 )
                    splay_tree->insert(rec);
                if (strcmp(rec.membership, "Regular") == 0 )
                    setA->add(rec);
                if (strcmp(rec.booking, "Walk-in") == 0 )
                    setB->add(rec);                    
                if (strcmp(rec.booking, "Business") == 0 )
                    b_tree->insert(rec); 
                // << rec.destination << endl;
                    
            }
            
             
            // Set the Title
            SetTitle(wxString(wxT("COMP2611 – Data Structures Project #1")));
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
                SetTitle(wxString(wxT("COMP2611 – Data Structures Project #1")));
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
        if (string(CurrentFilePath.mb_str()) == "") {
            MainEditBox->SetValue("No File Previously Selected");
            return;
        }
        opened_fileName = CurrentFilePath.mb_str(); // store file path / name of opened file
            
            
            fstream infile(opened_fileName, ios::in|ios::binary);
            Record rec;
            infile.seekg(0);
            stringstream output_stream;
            string output = "";
            
                
            while (!infile.eof())
            {
                infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
                
                output_stream << left << setw(15) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                output = output_stream.str();
                wxString mystring(output.c_str(), wxConvUTF8);
                MainEditBox->AppendText(mystring);
                output_stream.str("");
            }
        //MainEditBox->LoadFile(CurrentFilePath);
    }




void ProjectFrame::OnExit(wxCommandEvent& event)
    {
        wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
        Close(TRUE); // Close the window
    }


void ProjectFrame::About(wxCommandEvent& event) {
    InfoDialog *infoDialog = new InfoDialog( wxT("About Program"), wxPoint(200,300), wxSize(450,250) );
    if (infoDialog->ShowModal() == wxID_OK)
    {
        infoDialog->Close();
    }
    infoDialog->Destroy();
}


void ProjectFrame::createBST(wxCommandEvent& event) { 
    fstream infile(opened_fileName, ios::in|ios::binary);
    Record rec;
    infile.seekg(0);
    delete bs_tree;
    bs_tree = new BST();
    while (!infile.eof())
            {
                infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
                // fill ADTs
                bs_tree->insert(rec);
            }
    wxString formatted_string(bs_tree->inOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::BST_addRecord(wxCommandEvent& event) {
    AddRecordDialog *addrecordDialog = new AddRecordDialog( wxT("Add Record to Binary Search Tree"), wxPoint(200,300), wxSize(450,340) );
    if (addrecordDialog->ShowModal() == wxID_OK)
    {
        Record rec;
        // getting data from input dialog and filling record
        rec.id = wxAtoi(addrecordDialog->ClientIDBox->GetValue());
        strcpy(rec.firstname, string(addrecordDialog->FirstNameBox->GetValue().mb_str()).c_str());
        strcpy(rec.surname, string(addrecordDialog->SurnameBox->GetValue().mb_str()).c_str());
        strcpy(rec.destination, string(addrecordDialog->DestinationBox->GetValue().mb_str()).c_str());
        strcpy(rec.membership, string(addrecordDialog->MembershipCombo->GetValue().mb_str()).c_str());
        strcpy(rec.booking, string(addrecordDialog->BookingCombo->GetValue().mb_str()).c_str());
        
        stringstream output_stream;
        output_stream << left << setw(20) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                string output = output_stream.str();
                wxString formatted_string(output.c_str(), wxConvUTF8);
                MainEditBox->SetValue(formatted_string);
        
        bs_tree->insert(rec);
        addrecordDialog->Close();
    }
    addrecordDialog->Destroy();
}
void ProjectFrame::BST_deleteRecord(wxCommandEvent& event) { 
    DeleteDialog *deleteDialog = new DeleteDialog( wxT("Delete Record from Binary Search Tree"), wxPoint(200,300), wxSize(450,250) );
    if (deleteDialog->ShowModal() == wxID_OK)
    {
        int ID = wxAtoi(deleteDialog->ClientIDBox->GetValue());
        MainEditBox->SetValue(bs_tree->findNodeData(ID));
        bs_tree->remove(ID);
        deleteDialog->Close();
    }
    else if (deleteDialog->ShowModal() == wxID_CANCEL) 
        deleteDialog->Close();
    
    deleteDialog->Destroy();
}
void ProjectFrame::BST_display_inOrder(wxCommandEvent& event) {
    wxString formatted_string(bs_tree->inOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::BST_displayp_preOrder(wxCommandEvent& event) { 
    wxString formatted_string(bs_tree->preOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::BST_display_postOrder(wxCommandEvent& event) { 
    wxString formatted_string(bs_tree->postOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}




//Functions for AVL Tree Menu Items 
void ProjectFrame::createAVL(wxCommandEvent& event) { 
    fstream infile(opened_fileName, ios::in|ios::binary);
    Record rec;
    infile.seekg(0);
    delete avl_tree;
    avl_tree = new AVL();
    while (!infile.eof())
            {
                infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
                if (strcmp(rec.membership, "Platinum") == 0 || strcmp(rec.membership, "Gold") == 0)
                    avl_tree->insert(rec);
            }
            wxString formatted_string(avl_tree->inOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::AVL_addRecord(wxCommandEvent& event) {
    AddRecordDialog *addrecordDialog = new AddRecordDialog( wxT("Add Record to AVL Tree"), wxPoint(200,300), wxSize(450,340));
    if (addrecordDialog->ShowModal() == wxID_OK)
    {

        Record rec;
        rec.id = wxAtoi(addrecordDialog->ClientIDBox->GetValue());
        strcpy(rec.firstname, string(addrecordDialog->FirstNameBox->GetValue().mb_str()).c_str());
        strcpy(rec.surname, string(addrecordDialog->SurnameBox->GetValue().mb_str()).c_str());
        strcpy(rec.destination, string(addrecordDialog->DestinationBox->GetValue().mb_str()).c_str());
        strcpy(rec.membership, string(addrecordDialog->MembershipCombo->GetValue().mb_str()).c_str());
        strcpy(rec.booking, string(addrecordDialog->BookingCombo->GetValue().mb_str()).c_str());
        
        stringstream output_stream;
        output_stream << left << setw(20) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                string output = output_stream.str();
                wxString formatted_string(output.c_str(), wxConvUTF8);
                MainEditBox->SetValue(formatted_string);
        
        avl_tree->insert(rec);
        addrecordDialog->Close();
    }
    addrecordDialog->Destroy();
}
void ProjectFrame::AVL_deleteRecord(wxCommandEvent& event) { 
    DeleteDialog *deleteDialog = new DeleteDialog( wxT("Delete Record from AVL Tree"), wxPoint(200,300), wxSize(450,250) );
    if (deleteDialog->ShowModal() == wxID_OK)
    {
        int ID = wxAtoi(deleteDialog->ClientIDBox->GetValue());
        MainEditBox->SetValue(avl_tree->findNodeData(ID));
        avl_tree->remove(ID);
        deleteDialog->Close();
    }
    else if (deleteDialog->ShowModal() == wxID_CANCEL) 
        deleteDialog->Close();
    
    deleteDialog->Destroy();
}
void ProjectFrame::AVL_display_inOrder(wxCommandEvent& event) { 
    wxString formatted_string(avl_tree->inOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::AVL_displayp_preOrder(wxCommandEvent& event) {
    wxString formatted_string(avl_tree->preOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::AVL_display_postOrder(wxCommandEvent& event) { 
    wxString formatted_string(avl_tree->postOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}




//Functions for Red Black Tree Menu Items
void ProjectFrame::createRBT(wxCommandEvent& event) { 
    fstream infile(opened_fileName, ios::in|ios::binary);
    Record rec;
    infile.seekg(0);
    delete rb_tree; // delete current tree in pointer
    rb_tree = new RBT();
    while (!infile.eof())
        {
            infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
            if (strcmp(rec.booking, "Vacation") == 0 )
                rb_tree->insert(rec); 
        }
    wxString formatted_string(rb_tree->inOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
            
}
void ProjectFrame::RBT_addRecord(wxCommandEvent& event) {
    AddRecordDialog *addrecordDialog = new AddRecordDialog( wxT("Add Record to Red-Black Tree"), wxPoint(200,300), wxSize(450,340));
    if (addrecordDialog->ShowModal() == wxID_OK)
    {

        Record rec;
        rec.id = wxAtoi(addrecordDialog->ClientIDBox->GetValue());
        strcpy(rec.firstname, string(addrecordDialog->FirstNameBox->GetValue().mb_str()).c_str());
        strcpy(rec.surname, string(addrecordDialog->SurnameBox->GetValue().mb_str()).c_str());
        strcpy(rec.destination, string(addrecordDialog->DestinationBox->GetValue().mb_str()).c_str());
        strcpy(rec.membership, string(addrecordDialog->MembershipCombo->GetValue().mb_str()).c_str());
        strcpy(rec.booking, string(addrecordDialog->BookingCombo->GetValue().mb_str()).c_str());
        
        stringstream output_stream;
        output_stream << left << setw(20) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                string output = output_stream.str();
                wxString formatted_string(output.c_str(), wxConvUTF8);
                MainEditBox->SetValue(formatted_string);
        
        rb_tree->insert(rec);
        addrecordDialog->Close();
    }
    addrecordDialog->Destroy();
}
void ProjectFrame::RBT_deleteRecord(wxCommandEvent& event) { 
    DeleteDialog *deleteDialog = new DeleteDialog( wxT("Delete Record from Red-Black Tree"), wxPoint(200,300), wxSize(450,250) );
    if (deleteDialog->ShowModal() == wxID_OK)
    {
        int ID = wxAtoi(deleteDialog->ClientIDBox->GetValue());
        MainEditBox->SetValue(rb_tree->findNodeData(ID));
        rb_tree->remove(ID);
        deleteDialog->Close();
    }
    else if (deleteDialog->ShowModal() == wxID_CANCEL) 
        deleteDialog->Close();
    
    deleteDialog->Destroy();
}
void ProjectFrame::RBT_display_inOrder(wxCommandEvent& event) {
    wxString formatted_string(rb_tree->inOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::RBT_displayp_preOrder(wxCommandEvent& event) { 
    wxString formatted_string(rb_tree->preOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::RBT_display_postOrder(wxCommandEvent& event) { 
    wxString formatted_string(rb_tree->postOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}




//Functions for Splay Tree Menu Items
void ProjectFrame::createSplayT(wxCommandEvent& event) {
    fstream infile(opened_fileName, ios::in|ios::binary);
    Record rec;
    infile.seekg(0);
            
    delete splay_tree;
    splay_tree = new SplayTree();
    while (!infile.eof())
        {
            infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
            if (strcmp(rec.membership, "Silver") == 0 )
                splay_tree->insert(rec);  
        }
    wxString formatted_string(splay_tree->inOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::SplayT_addRecord(wxCommandEvent& event) { 
    AddRecordDialog *addrecordDialog = new AddRecordDialog( wxT("Add Record to Splay Tree"), wxPoint(200,300), wxSize(450,340));
    if (addrecordDialog->ShowModal() == wxID_OK)
    {

        Record rec;
        rec.id = wxAtoi(addrecordDialog->ClientIDBox->GetValue());
        strcpy(rec.firstname, string(addrecordDialog->FirstNameBox->GetValue().mb_str()).c_str());
        strcpy(rec.surname, string(addrecordDialog->SurnameBox->GetValue().mb_str()).c_str());
        strcpy(rec.destination, string(addrecordDialog->DestinationBox->GetValue().mb_str()).c_str());
        strcpy(rec.membership, string(addrecordDialog->MembershipCombo->GetValue().mb_str()).c_str());
        strcpy(rec.booking, string(addrecordDialog->BookingCombo->GetValue().mb_str()).c_str());
        
        stringstream output_stream;
        output_stream << left << setw(20) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                string output = output_stream.str();
                wxString formatted_string(output.c_str(), wxConvUTF8);
                MainEditBox->SetValue(formatted_string);
        
        splay_tree->insert(rec);
        addrecordDialog->Close();
    }
    addrecordDialog->Destroy();
}
void ProjectFrame::SplayT_deleteRecord(wxCommandEvent& event) { 
    DeleteDialog *deleteDialog = new DeleteDialog( wxT("Delete Record from Splay Tree"), wxPoint(200,300), wxSize(450,250) );
    if (deleteDialog->ShowModal() == wxID_OK)
    {
        int ID = wxAtoi(deleteDialog->ClientIDBox->GetValue());
        MainEditBox->SetValue(splay_tree->findNodeData(ID));
        splay_tree->remove(ID);
        deleteDialog->Close();
    }
    else if (deleteDialog->ShowModal() == wxID_CANCEL) 
        deleteDialog->Close();
    
    deleteDialog->Destroy();
}
void ProjectFrame::SplayT_display_inOrder(wxCommandEvent& event) { 
    wxString formatted_string(splay_tree->inOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::SplayT_displayp_preOrder(wxCommandEvent& event) {
    wxString formatted_string(splay_tree->preOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::SplayT_display_postOrder(wxCommandEvent& event) {
    wxString formatted_string(splay_tree->postOrder().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}




//Functions for Heao Menu Items
void ProjectFrame::createHeap(wxCommandEvent& event) { 
    fstream infile(opened_fileName, ios::in|ios::binary);
    Record rec;
    infile.seekg(0);
    delete heap;
    heap = new BinHeap();
    while (!infile.eof())
        {
            infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
            heap->addMinHeap(rec); 
        }
    wxString formatted_string(heap->displayHeap().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::Heap_addRecord(wxCommandEvent& event) { 
    AddRecordDialog *addrecordDialog = new AddRecordDialog( wxT("Add Record to Heap"), wxPoint(200,300), wxSize(450,340));
    if (addrecordDialog->ShowModal() == wxID_OK)
    {

        Record rec;
        rec.id = wxAtoi(addrecordDialog->ClientIDBox->GetValue());
        strcpy(rec.firstname, string(addrecordDialog->FirstNameBox->GetValue().mb_str()).c_str());
        strcpy(rec.surname, string(addrecordDialog->SurnameBox->GetValue().mb_str()).c_str());
        strcpy(rec.destination, string(addrecordDialog->DestinationBox->GetValue().mb_str()).c_str());
        strcpy(rec.membership, string(addrecordDialog->MembershipCombo->GetValue().mb_str()).c_str());
        strcpy(rec.booking, string(addrecordDialog->BookingCombo->GetValue().mb_str()).c_str());
        
        stringstream output_stream;
        output_stream << left << setw(20) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                string output = output_stream.str();
                wxString formatted_string(output.c_str(), wxConvUTF8);
                MainEditBox->SetValue(formatted_string);
        
        heap->addMinHeap(rec);
        addrecordDialog->Close();
    }
    addrecordDialog->Destroy();
}
void ProjectFrame::Heap_deleteRecord(wxCommandEvent& event) {
    DeleteDialog *deleteDialog = new DeleteDialog( wxT("Delete Record from Heap"), wxPoint(200,300), wxSize(450,250) );
    if (deleteDialog->ShowModal() == wxID_OK)
    {
        int ID = wxAtoi(deleteDialog->ClientIDBox->GetValue());
        MainEditBox->SetValue(heap->findNodeData(ID));
        heap->deleteMinHeapVal(ID);
        deleteDialog->Close();
    }
    else if (deleteDialog->ShowModal() == wxID_CANCEL) 
        deleteDialog->Close();
    
    deleteDialog->Destroy(); 
}
void ProjectFrame::Heap_displayAll(wxCommandEvent& event) {
    wxString formatted_string(heap->displayHeap().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::HeapSort(wxCommandEvent& event) { 
    wxString formatted_string(heap->sortMinHeap().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
        
//Functions for B Tree Menu Items
void ProjectFrame::createBTree(wxCommandEvent& event) { 
    fstream infile(opened_fileName, ios::in|ios::binary);
    Record rec;
    infile.seekg(0);
    delete b_tree;
    b_tree = new BTree();
    while (!infile.eof())
        {
            infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
            if (strcmp(rec.booking, "Business") == 0 )
                b_tree->insert(rec); 
        }
    wxString formatted_string(b_tree->displayBTree().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string); 
}
void ProjectFrame::BTree_addRecord(wxCommandEvent& event) { 
    AddRecordDialog *addrecordDialog = new AddRecordDialog( wxT("Add Record to B-Tree"), wxPoint(200,300), wxSize(450,340));
    if (addrecordDialog->ShowModal() == wxID_OK)
    {

        Record rec;
        rec.id = wxAtoi(addrecordDialog->ClientIDBox->GetValue());
        strcpy(rec.firstname, string(addrecordDialog->FirstNameBox->GetValue().mb_str()).c_str());
        strcpy(rec.surname, string(addrecordDialog->SurnameBox->GetValue().mb_str()).c_str());
        strcpy(rec.destination, string(addrecordDialog->DestinationBox->GetValue().mb_str()).c_str());
        strcpy(rec.membership, string(addrecordDialog->MembershipCombo->GetValue().mb_str()).c_str());
        strcpy(rec.booking, string(addrecordDialog->BookingCombo->GetValue().mb_str()).c_str());
        
        stringstream output_stream;
        output_stream << left << setw(20) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                string output = output_stream.str();
                b_tree->insert(rec);
                wxString formatted_string(output.c_str(), wxConvUTF8);
                MainEditBox->SetValue(formatted_string);
        
        //b_tree->insert(rec);
        addrecordDialog->Close();
    }
    addrecordDialog->Destroy(); 
}
void ProjectFrame::BTree_deleteRecord(wxCommandEvent& event) { 
     DeleteDialog *deleteDialog = new DeleteDialog( wxT("Delete Record from Splay Tree"), wxPoint(200,300), wxSize(450,250) );
    if (deleteDialog->ShowModal() == wxID_OK)
    {
        int ID = wxAtoi(deleteDialog->ClientIDBox->GetValue());
        MainEditBox->SetValue("Didn't attemp based on my implementation of B-Tree :)");
        deleteDialog->Close();
    }
    else if (deleteDialog->ShowModal() == wxID_CANCEL) 
        deleteDialog->Close();
    
    deleteDialog->Destroy();
    
}
void ProjectFrame::BTree_displayAll(wxCommandEvent& event) { 
   wxString formatted_string(b_tree->displayBTree().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
        
//Functions for Set
void ProjectFrame::createSets(wxCommandEvent& event) { 
    fstream infile(opened_fileName, ios::in|ios::binary);
    Record rec;
    infile.seekg(0);
            
    delete setA;
    delete setB;
    setA = new Set();
    setB = new Set();
    while (!infile.eof())
        {
            infile.read (reinterpret_cast<char*>(&rec), sizeof(Record));
            if (strcmp(rec.membership, "Regular") == 0 )
                    setA->add(rec);
            if (strcmp(rec.booking, "Walk-in") == 0 )
                setB->add(rec);
        }
}
void ProjectFrame::AddtoSetA(wxCommandEvent& event) {
    AddRecordDialog *addrecordDialog = new AddRecordDialog( wxT("Add Record to Set A"), wxPoint(200,300), wxSize(450,340));
    if (addrecordDialog->ShowModal() == wxID_OK)
    {

        Record rec;
        rec.id = wxAtoi(addrecordDialog->ClientIDBox->GetValue());
        strcpy(rec.firstname, string(addrecordDialog->FirstNameBox->GetValue().mb_str()).c_str());
        strcpy(rec.surname, string(addrecordDialog->SurnameBox->GetValue().mb_str()).c_str());
        strcpy(rec.destination, string(addrecordDialog->DestinationBox->GetValue().mb_str()).c_str());
        strcpy(rec.membership, string(addrecordDialog->MembershipCombo->GetValue().mb_str()).c_str());
        strcpy(rec.booking, string(addrecordDialog->BookingCombo->GetValue().mb_str()).c_str());
        
        stringstream output_stream;
        output_stream << left << setw(20) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                string output = output_stream.str();
                wxString formatted_string(output.c_str(), wxConvUTF8);
                MainEditBox->SetValue(formatted_string);
        
        setA->add(rec);
        addrecordDialog->Close();
    }
    addrecordDialog->Destroy();
}
void ProjectFrame::AddtoSetB(wxCommandEvent& event) { 
    AddRecordDialog *addrecordDialog = new AddRecordDialog( wxT("Add Record to Set B"), wxPoint(200,300), wxSize(450,340));
    if (addrecordDialog->ShowModal() == wxID_OK)
    {

        Record rec;
        rec.id = wxAtoi(addrecordDialog->ClientIDBox->GetValue());
        strcpy(rec.firstname, string(addrecordDialog->FirstNameBox->GetValue().mb_str()).c_str());
        strcpy(rec.surname, string(addrecordDialog->SurnameBox->GetValue().mb_str()).c_str());
        strcpy(rec.destination, string(addrecordDialog->DestinationBox->GetValue().mb_str()).c_str());
        strcpy(rec.membership, string(addrecordDialog->MembershipCombo->GetValue().mb_str()).c_str());
        strcpy(rec.booking, string(addrecordDialog->BookingCombo->GetValue().mb_str()).c_str());
        
        stringstream output_stream;
        output_stream << left << setw(20) << rec.id 
                << left << setw(15) << rec.firstname 
                << left << setw(15) << rec.surname 
                << left << setw(15) << rec.destination 
                << left << setw(15) << rec.membership 
                << left << setw(15) << rec.booking 
                << endl; 
                
                string output = output_stream.str();
                wxString formatted_string(output.c_str(), wxConvUTF8);
                MainEditBox->SetValue(formatted_string);
        
        setB->add(rec);
        addrecordDialog->Close();
    }
    addrecordDialog->Destroy();
}
void ProjectFrame::displaySetA(wxCommandEvent& event) { 
    wxString formatted_string(setA->displaySet().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::displaySetB(wxCommandEvent& event) { 
    wxString formatted_string(setB->displaySet().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::displayIntersection(wxCommandEvent& event) { 
    Set temp_set;
    temp_set.intersect(setA, setB);
    wxString formatted_string(temp_set.displaySet().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
void ProjectFrame::displayUnion(wxCommandEvent& event) { 
    Set temp_set;
    temp_set.Union(setA, setB);
    wxString formatted_string(temp_set.displaySet().c_str(), wxConvUTF8);
    MainEditBox->SetValue(formatted_string);
}
