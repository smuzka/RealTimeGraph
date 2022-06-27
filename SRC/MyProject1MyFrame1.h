#pragma once
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/brush.h>
#include <wx/colour.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <string>

#include "GUI.h"
#include "Data.h"
#include "DataAnalyzer.h"

class MyProject1MyFrame1 : public MyFrame1 {
protected:
	void WxPanel_Repaint(wxUpdateUIEvent& event);
	void OnModeOneButton(wxUpdateUIEvent& event);
	void OnModeTwoButton(wxUpdateUIEvent& event);
	void OnScaleButton(wxUpdateUIEvent& event);
	void OnBarGraphButton(wxUpdateUIEvent& event);


	bool mode;
	bool scale;
	bool bar;

public:
	MyProject1MyFrame1(wxWindow* parent);

	void Repaint();
	void DrawAxes(wxDC* dc);
	void ModeOne(wxDC* dc);
	void ModeTwo(wxDC* dc);
	void DrawChart(wxDC* dc, bool);
	void DrawScale(wxDC* dc, int w, int h);
	void BarGraphModeOne(wxDC* dc);
	void BarGraphModeTwo(wxDC* dc);
	void BarGraphDrawChart(wxDC* dc, bool);
};