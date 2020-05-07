// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/Text.h>


namespace myapp {

class MyApp : public cinder::app::App {
 public:
    enum class PaintColor {
        Red,
        Blue,
        Green,
        Orange,
        Teal,
        Purple
    };
    enum class PaintSize {
        One = 5,
        Two = 10,
        Three = 15,
        Four = 20
    };


  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  /**
  Checks the updated color to use
  */
  static void SelectColor(const std::string& text);
  
  /**
  Checks the updated size to use
  */
  static void SelectSize(const std::string& text);
  void DrawPaint(const cinder::app::MouseEvent&) const;
 
  /**
  Called when the user is prompted to type the image path
  */
  void keyDown(cinder::app::KeyEvent) override;
 
  /**
  Called when user accesses buttons
  Activates different functionality based on button called
  */
  void mouseDown(cinder::app::MouseEvent) override;
 
  /**
  Used to draw paint
  */
  void mouseDrag(cinder::app::MouseEvent) override;
 
  /**
  Creates a button in the form of a text box
  Each button is stored in a vector and the location can be accessed
  */
  static void CreateButton(std::string text, const cinder::ivec2& size, const cinder::vec2& loc, cinder::Color color);
  
  /**
  Gets a copy of the current drawing.
  */
  cinder::Surface copyDraw();
 
  /**
  Gets the updated file path the user types in
  */
  void UpdateFileName();
 
  /**
  Used when the ui is cleared
  Creates the button interface
  */
  void DrawButtons();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
