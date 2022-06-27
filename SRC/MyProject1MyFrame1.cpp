#include "MyProject1MyFrame1.h"

MyProject1MyFrame1::MyProject1MyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	mode = 0;
	scale = 0;
	bar = 0;
}

void MyProject1MyFrame1::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	Repaint();
}


void MyProject1MyFrame1::OnModeOneButton(wxUpdateUIEvent& event) {
	if (mode == 1) {
		mode = 0;
		Repaint();
	}
}

void MyProject1MyFrame1::OnModeTwoButton(wxUpdateUIEvent& event) {
	if (mode == 0) {
		mode = 1;
		Repaint();
	}
}

void MyProject1MyFrame1::OnScaleButton(wxUpdateUIEvent& event) {
	scale = !scale;
	Repaint();
}

void MyProject1MyFrame1::OnBarGraphButton(wxUpdateUIEvent& event) {
	bar = !bar;
	Repaint();
}

void MyProject1MyFrame1::DrawScale(wxDC* dc, int w, int h) {
	dc->SetPen(wxPen(wxColor(255, 0, 0)));
	dc->SetTextForeground(wxColor(255, 0, 0));
	// X Axis
	dc->DrawLine(wxPoint(w - 1, h / 2 - 4), wxPoint(w - 1, h / 2 + 5));
	dc->DrawText(std::to_string(10), wxPoint(w - 20, h / 2 + 10));
	for (int seconds = 0; seconds < 10; seconds++) {
		dc->DrawLine(wxPoint(seconds * (w / 10), h / 2 - 4), wxPoint(seconds * (w / 10), h / 2 + 5));
		dc->DrawText(std::to_string(seconds), wxPoint(seconds * (w / 10), h / 2 + 10));
	}

	// Y Axis
	dc->DrawLine(wxPoint(w / 2 - 4, h - 1), wxPoint(w / 2 + 5, h - 1));
	dc->DrawText("-1.0", wxPoint(w / 2 + 10, h - 20));
	for (int scaleY = 1; scaleY < 11; scaleY++) {
		dc->DrawLine(wxPoint(w / 2 - 4, h - (scaleY * (h / 10))), wxPoint(w / 2 + 5, h - (scaleY * (h / 10))));
		dc->DrawText(std::to_string(((scaleY * 0.2) - 1)).substr(0, scaleY > 4 ? 3 : 4), wxPoint(w / 2 + 10, h - (scaleY * (h / 10))));
	}
}


void MyProject1MyFrame1::DrawAxes(wxDC* dc) {

	int w, h;
	GraphPanel->GetSize(&w, &h);

	// Y Axis
	dc->SetPen(wxPen(wxColor(100, 100, 100)));
	dc->DrawLine(wxPoint(w / 2, 0), wxPoint(w / 2, h));
	dc->DrawLine(wxPoint(w / 2, 0), wxPoint(w / 2 + 10, 10));
	dc->DrawLine(wxPoint(w / 2, 0), wxPoint(w / 2 - 10, 10));

	// X Axis
	dc->DrawLine(wxPoint(0, h / 2), wxPoint(w, h / 2));
	dc->DrawLine(wxPoint(w, h / 2), wxPoint(w - 10, h / 2 - 10));
	dc->DrawLine(wxPoint(w, h / 2), wxPoint(w - 10, h / 2 + 10));

	if (scale) {
		DrawScale(dc, w, h);
	}
}

// linear graph
void MyProject1MyFrame1::ModeOne(wxDC* dc) {
	DrawChart(dc, false);
}

void MyProject1MyFrame1::ModeTwo(wxDC* dc) {
	DrawChart(dc, false);

	DrawChart(dc, true);
}

void MyProject1MyFrame1::DrawChart(wxDC* dc, bool newData) {
	int w, h;
	GraphPanel->GetSize(&w, &h);

	std::vector<int> pixels;

	if (newData) {
		for (int i = 0; i < DataAnalyzer::DATA_SIZE; i++) {
			pixels.push_back(DataAnalyzer::newData->getPixelY(i, h));
		}
		dc->SetPen(wxPen(wxColor(0, 0, 255)));
	}
	else {
		for (int i = 0; i < DataAnalyzer::DATA_SIZE; i++) {
			pixels.push_back(DataAnalyzer::oldData->getPixelY(i, h));
		}
		dc->SetPen(wxPen(wxColor(0, 0, 0)));
	}

	for (int i = 0; i < pixels.size() - 1; i++) {
		dc->DrawLine(wxPoint(i * (double(w) / pixels.size()), pixels[i]), wxPoint((i + 1) * (double(w) / pixels.size()), pixels[i + 1]));
	}
}

//bar graph
void MyProject1MyFrame1::BarGraphModeOne(wxDC* dc) {
	BarGraphDrawChart(dc, true);
}

void MyProject1MyFrame1::BarGraphModeTwo(wxDC* dc) {
	BarGraphDrawChart(dc, false);

	BarGraphDrawChart(dc, true);
}

void MyProject1MyFrame1::BarGraphDrawChart(wxDC* dc, bool newData) {
	int w, h;
	GraphPanel->GetSize(&w, &h);

	std::vector<int> pixels;

	if (newData) {
		for (int i = 0; i < DataAnalyzer::DATA_SIZE; i++) {
			pixels.push_back(DataAnalyzer::newData->getPixelY(i, h));
		}
		dc->SetPen(wxPen(wxColor(0, 0, 255)));
	}
	else {
		for (int i = 0; i < DataAnalyzer::DATA_SIZE; i++) {
			pixels.push_back(DataAnalyzer::oldData->getPixelY(i, h));
		}
		dc->SetPen(wxPen(wxColor(0, 0, 0)));
	}

	for (int i = 0; i < pixels.size() - 1; i++) {
		dc->DrawLine(wxPoint(i * (double(w) / pixels.size()), h / 2), wxPoint(i * (double(w) / pixels.size()), pixels[i]));
	}
}



void MyProject1MyFrame1::Repaint() {

	DataAnalyzer::ReadData();

	wxClientDC dc1(GraphPanel);
	wxBufferedDC dc(&dc1);

	int w, h;
	GraphPanel->GetSize(&w, &h);

	dc.SetBackground(wxBrush(RGB(255, 255, 255)));
	dc.Clear();
	dc.SetClippingRegion(0, 0, w, h);

	if (bar == 0) {
		if (mode == 0) {
			ModeOne(&dc);
		}
		else if (mode == 1) {
			ModeTwo(&dc);
		}
	}
	else if (bar == 1) {
		if (mode == 0) {
			BarGraphModeOne(&dc);
		}
		else if (mode == 1) {
			BarGraphModeTwo(&dc);
		}
	}

	DrawAxes(&dc);
}