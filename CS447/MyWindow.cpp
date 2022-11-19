
#include "MyWindow.h"

#include <FL/Gl.h>
#include <FL/Fl.h>
#include <GL/GLU.h>

void IdleCallback(void* pData) {

    if (pData != NULL) {

        MyWindow* pWindow = reinterpret_cast<MyWindow*>(pData);
        if (pWindow->animating) {
            pWindow->rotation += pWindow->rotationIncrement / 100;
            pWindow->redraw();
        }
    }
}

MyWindow::MyWindow(int width, int height, const char* title) : Fl_Gl_Window(width, height, title) {

	mode(FL_RGB | FL_ALPHA | FL_DEPTH | FL_DOUBLE);

    rotation = 0.f;
    rotationIncrement = 10.f;
    animating = false;

    Fl::add_idle(IdleCallback, this);
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
    // takes the angle to rotate (degrees) and axis to rotate around (pos y)
    glRotatef(rotation, 0, 1, 0);

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

int MyWindow::handle(int event)
{
    switch (event)
    {
    // makes sure all keyboard events are sent to window
    case FL_FOCUS:
    case FL_UNFOCUS:
        return 1;

    case FL_KEYBOARD:
        int key = Fl::event_key();
        switch (key)
        {
        case FL_Left:
            rotation -= rotationIncrement;
            redraw();
            return 1;

        case FL_Right:
            rotation += rotationIncrement;
            redraw();
            return 1;

        case ' ':
            animating = !animating;
            return 1;
        }
    }

    return Fl_Gl_Window::handle(event);
}


