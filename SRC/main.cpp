#include <wx/wxprec.h>
#include <windows.h>
#include <process.h>
#include <shellapi.h>
#include <wx/sizer.h>
#include <wx/wx.h>
#include <wx/timer.h>

#include "GUI.h"
#include "MyProject1MyFrame1.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() {
		system("taskkill /F /T /IM Generator.exe");
		return 0;
	}
};


class RenderTimer : public wxTimer {
	MyProject1MyFrame1* mainFrame;
public:
	RenderTimer(MyProject1MyFrame1* mainFrame);
	void Notify();
	void start();
};

RenderTimer::RenderTimer(MyProject1MyFrame1* mainFrame) : wxTimer() {
	RenderTimer::mainFrame = mainFrame;
};

void RenderTimer::Notify() {
	mainFrame->Repaint();
};

void RenderTimer::start() {
	wxTimer::Start(1000);
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	wxFrame* mainFrame = new MyProject1MyFrame1(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	ShellExecute(NULL, _T("open"), _T("Generator.exe"), NULL, NULL, NULL);

	dynamic_cast<MyProject1MyFrame1*>(mainFrame)->Repaint();
	RenderTimer* timer = new RenderTimer(dynamic_cast<MyProject1MyFrame1*>(mainFrame));
	timer->start();


	return true;
}