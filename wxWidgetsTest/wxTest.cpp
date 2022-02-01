#include <wx/wx.h>

class MyApp : public wxApp
{
	public:
		virtual bool OnInit();
};

class MyFrame : public wxFrame 
{
	private:
		DECLARE_EVENT_TABLE()
	public:
		MyFrame(const wxString& title); // Constructor
		// Event Handlers
		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);	
};

DECLARE_APP(MyApp); // Declare Application Class
IMPLEMENT_APP(MyApp); // Create Application class object

// Enumeration Table
enum
{
	wxID_Quit = wxID_HIGHEST + 1,
	WXID_About,
};
