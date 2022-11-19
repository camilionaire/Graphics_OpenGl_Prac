
#include "MyWindow.h"

#include <FL/Gl.h>
#include <GL/GLU.h>

MyWindow::MyWindow(int width, int height, const char* title) : Fl_Gl_Window(width, height, title)
{
	mode(FL_RGB | FL_ALPHA | FL_DEPTH | FL_DOUBLE);
}

MyWindow::~MyWindow()
{}

void MyWindow::InitializeGL() {

	glClearColor(.1f, .1f, .1f, 1);
	glEnable(GL_DEPTH_TEST);
}

void MyWindow::draw() {
	
	static bool firstTime = true;
	if (firstTime) {
		InitializeGL();
		firstTime = false;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// view transformations

	// draw something

}


