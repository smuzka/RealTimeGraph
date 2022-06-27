#include "GUI.h"

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style) {
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* ExpandSizer;
	ExpandSizer = new wxBoxSizer(wxVERTICAL);

	GraphPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1000, 500), wxTAB_TRAVERSAL);

	ExpandSizer->Add(GraphPanel, 1, wxEXPAND | wxALL, 5);


	MainSizer->Add(ExpandSizer, 1, wxEXPAND, 5);

	wxBoxSizer* MenuSizer;
	MenuSizer = new wxBoxSizer(wxVERTICAL);

	ModeOneButton = new wxButton(this, wxID_ANY, wxT("Mode 1"), wxDefaultPosition, wxDefaultSize, 0);
	MenuSizer->Add(ModeOneButton, 0, wxALL, 5);

	ModeTwoButton = new wxButton(this, wxID_ANY, wxT("Mode 2"), wxDefaultPosition, wxDefaultSize, 0);
	MenuSizer->Add(ModeTwoButton, 0, wxALL, 5);

	ScaleButton = new wxButton(this, wxID_ANY, wxT("Scale"), wxDefaultPosition, wxDefaultSize, 0);
	MenuSizer->Add(ScaleButton, 0, wxALL, 5);

	BarGraphButton = new wxButton(this, wxID_ANY, wxT("Bar graph"), wxDefaultPosition, wxDefaultSize, 0);
	MenuSizer->Add(BarGraphButton, 0, wxALL, 5);

	MainSizer->Add(MenuSizer, 0, wxEXPAND, 5);


	this->SetSizer(MainSizer);
	this->Layout();
	MainSizer->Fit(this);

	this->Centre(wxBOTH);


	// Connect Events
	GraphPanel->Connect(wxEVT_PAINT, wxUpdateUIEventHandler(MyFrame1::WxPanel_Repaint), NULL, this);
	ModeOneButton->Connect(wxEVT_BUTTON, wxUpdateUIEventHandler(MyFrame1::OnModeOneButton), NULL, this);
	ModeTwoButton->Connect(wxEVT_BUTTON, wxUpdateUIEventHandler(MyFrame1::OnModeTwoButton), NULL, this);
	ScaleButton->Connect(wxEVT_BUTTON, wxUpdateUIEventHandler(MyFrame1::OnScaleButton), NULL, this);
	BarGraphButton->Connect(wxEVT_BUTTON, wxUpdateUIEventHandler(MyFrame1::OnBarGraphButton), NULL, this);
}

MyFrame1::~MyFrame1() {
	// Disconnect Events
	GraphPanel->Disconnect(wxEVT_PAINT, wxUpdateUIEventHandler(MyFrame1::WxPanel_Repaint), NULL, this);
	ModeOneButton->Disconnect(wxEVT_BUTTON, wxUpdateUIEventHandler(MyFrame1::OnModeOneButton), NULL, this);
	ModeTwoButton->Disconnect(wxEVT_BUTTON, wxUpdateUIEventHandler(MyFrame1::OnModeTwoButton), NULL, this);
	ScaleButton->Disconnect(wxEVT_BUTTON, wxUpdateUIEventHandler(MyFrame1::OnScaleButton), NULL, this);
	BarGraphButton->Disconnect(wxEVT_BUTTON, wxUpdateUIEventHandler(MyFrame1::OnBarGraphButton), NULL, this);
}