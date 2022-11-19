
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

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);

	// draw something
    DrawCube();

}

// just copied and pasted this so we'll see...
void MyWindow::DrawCube()
{
    glBegin(GL_QUADS);
    // front
    glColor3f(1, 0, 0);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);

    // back
    glColor3f(0, 1, 0);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);

    // top
    glColor3f(0, 0, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);

    // bottom
    glColor3f(1, 1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);

    // left
    glColor3f(0, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);

    // right
    glColor3f(1, 0, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glEnd();
}



