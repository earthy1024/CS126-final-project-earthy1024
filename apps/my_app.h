// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>


namespace myapp {

class MyApp : public cinder::app::App {
 public:
    enum class PaintColor {
        Red,
        Blue,
        Green,
        Orange,
        Yellow
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
  static void SelectColor(const std::string& text);
  static void SelectSize(const std::string& text);
  void DrawPaint(cinder::app::MouseEvent) const;
  void keyDown(cinder::app::KeyEvent) override;
  void mouseDown(cinder::app::MouseEvent) override;
  void mouseDrag(cinder::app::MouseEvent) override;
  static void CreateButton(const std::string& text, const cinder::ivec2& size, const cinder::vec2& loc);
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
