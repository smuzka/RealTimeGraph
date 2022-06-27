#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/frame.h>
#include <wx/wxprec.h>
#include <wx/event.h>

class MyFrame1 : public wxFrame {
protected:
	wxPanel* GraphPanel;
	wxButton* ModeOneButton;
	wxButton* ModeTwoButton;
	wxButton* ScaleButton;
	wxButton* BarGraphButton;

	// Virtual event handlers, overide them in your derived class
	virtual void WxPanel_Repaint(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void OnModeOneButton(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void OnModeTwoButton(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void OnScaleButton(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void OnBarGraphButton(wxUpdateUIEvent& event) { event.Skip(); }

public:
	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Smuga, Czaicki, Gawron (:", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	~MyFrame1();
};

