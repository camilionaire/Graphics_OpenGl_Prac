#ifndef MY_WINDOW_H
#define MY_WINDOW_H

#include <Fl/Fl_Gl_Window.h>

class MyWindow : public Fl_Gl_Window
{
   public:
      MyWindow(int width, int height, const char* title);
      virtual ~MyWindow();
      void InitializeGL();
      virtual void draw();
      void DrawCube();
      virtual int handle(int event);

      float rotation;
      float rotationIncrement;
      bool animating;
};

#endif
