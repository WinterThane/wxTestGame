#ifndef APP_FRAME_H
#define APP_FRAME_H

#include "wx/wx.h"

enum ID_LIST
{
	PAINT_WINDOW = 400
};

class AppFrame : public wxFrame
{
public:
	AppFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
	wxWindow *paintWindow;
};

#endif