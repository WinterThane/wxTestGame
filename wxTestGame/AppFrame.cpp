#include "stdwx.h"

#include "AppFrame.h"

#define GRID_SIZE 64
#define LEVEL_X 10
#define LEVEL_Y 10

BEGIN_EVENT_TABLE(AppFrame, wxFrame)
	EVT_MENU(ID_New, AppFrame::OnNew)
	EVT_MENU(ID_Load, AppFrame::OnLoad)
	EVT_MENU(ID_About, AppFrame::OnAbout)
	EVT_MENU(ID_Exit, AppFrame::OnExit)
END_EVENT_TABLE()

AppFrame::AppFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
	wxMenuBar *menu_bar = new wxMenuBar;

	wxMenu *menuFile = new wxMenu;

	menuFile->Append(ID_New, "&New");
	menuFile->AppendSeparator();
	menuFile->Append(ID_Load, "&Load");
	menuFile->AppendSeparator();
	menuFile->Append(ID_About, "&About");
	menuFile->AppendSeparator();
	menuFile->Append(ID_Exit, "&Exit");

	menu_bar->Append(menuFile, "&File");
	SetMenuBar(menu_bar);

	m_panel = new wxPanel(this, -1);
	m_info_panel = new wxPanel(m_panel, -1, wxDefaultPosition, wxSize(200, 400), wxBORDER_STATIC);

	gameWindow = new wxWindow(m_panel, -1, wxDefaultPosition, wxSize(200, 200), wxBORDER_STATIC);

	gameWindow->Connect(-1, -1, wxEVT_PAINT, (wxObjectEventFunction) &AppFrame::OnPaint, NULL, this);

	stPlayerLives = new wxStaticText(m_info_panel, -1, _T("Lives:"), wxDefaultPosition, wxSize(100, 15), wxST_NO_AUTORESIZE);
	stCurrentLevel = new wxStaticText(m_info_panel, -1, _T("Level:"), wxDefaultPosition, wxSize(100, 15), wxST_NO_AUTORESIZE);
	stNumEnemies = new wxStaticText(m_info_panel, -1, _T("Enemies:"), wxDefaultPosition, wxSize(100, 15), wxST_NO_AUTORESIZE);

	wxBoxSizer *mainsizer = new wxBoxSizer(wxHORIZONTAL);

	mainsizer->Add(gameWindow, 1, wxGROW | wxALL, 5);
	mainsizer->Add(m_info_panel, 0, wxGROW | wxALL | wxSTRETCH_NOT, 5);

	wxBoxSizer *subsizer = new wxBoxSizer(wxVERTICAL);

	subsizer->Add(stPlayerLives, 0, wxLEFT | wxTOP, 5);
	subsizer->Add(stCurrentLevel, 0, wxLEFT | wxTOP, 5);
	subsizer->Add(stNumEnemies, 0, wxLEFT | wxTOP, 5);

	m_panel->SetAutoLayout(TRUE);
	m_panel->SetSizer(mainsizer);

	m_info_panel->SetAutoLayout(TRUE);
	m_info_panel->SetSizer(subsizer);

	backBuffer = new wxBitmap(LEVEL_X * GRID_SIZE, LEVEL_Y * GRID_SIZE);

	drawArea.createBackgroundTile(TILE_EMPTY, &wxBITMAP(emptyTile));
	drawArea.createBackgroundTile(TILE_WALL, &wxBITMAP(wallTile));

	drawArea.createSprite(SPRITE_PLAYER, &wxBITMAP(playerTile));
	drawArea.createSprite(SPRITE_ENEMY, &wxBITMAP(enemyTile));
	drawArea.createSprite(SPRITE_FIREBALL, &wxBITMAP(fireballTile));

	drawArea.setWindow(backBuffer, LEVEL_X, LEVEL_Y);

	level = new Level(&drawArea, LEVEL_X, LEVEL_Y);
	player = new Mage(level, &drawArea, 0);

	level->draw();
	level->addPlayer(player);
	level->addEnemies(3);

	level->setPlayerPosition();
	level->update();
}

void AppFrame::OnNew(wxCommandEvent& event)
{
	
}

void AppFrame::OnLoad(wxCommandEvent& event)
{
	
}

void AppFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(_T("ayyy"), _T("About Test Game"));
}

void AppFrame::OnExit(wxCommandEvent& event)
{
	
}

void AppFrame::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(gameWindow);

	dc.SetBackground(*wxBLACK_BRUSH);
	dc.Clear();

	dc.DrawBitmap(*backBuffer, wxPoint(0, 0));
}