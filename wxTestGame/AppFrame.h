#ifndef APPFRAME_H
#define APPFRAME_H

#include "wx/wx.h"
#include "stdwx.h"

#include "drawEngine.h"
#include "level.h"
#include "mage.h"

enum ID_list
{
	ID_New = 400,
	ID_Load,
	ID_About,
	ID_Exit
};

class AppFrame : public wxFrame
{
public:
	AppFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

	void OnNew(wxCommandEvent &event);
	void OnLoad(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);

	void OnPaint(wxPaintEvent &event);

private:
	//controls
	wxPanel *m_panel;
	wxPanel *m_info_panel;

	wxWindow *gameWindow;

	wxStaticText *stPlayerLives;
	wxStaticText *stCurrentLevel;
	wxStaticText *stNumEnemies;

	//game
	Level *level;
	Mage *player;
	DrawEngine drawArea;

	wxBitmap *backBuffer;
private:
	DECLARE_EVENT_TABLE()
};

#endif