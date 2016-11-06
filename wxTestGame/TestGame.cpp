#include "stdwx.h"

#include "AppFrame.h"

class TestGame : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(TestGame)

bool TestGame::OnInit()
{
	AppFrame *frame = new AppFrame(_T("Test Game"), wxPoint(100, 100), wxSize(900, 800));

	frame->Show(TRUE);

	SetTopWindow(frame);

	return true;
}