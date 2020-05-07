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
  static void SelectColor(const std::string& text);
  static void SelectSize(const std::string& text);
  void DrawPaint(const cinder::app::MouseEvent&) const;
  void keyDown(cinder::app::KeyEvent) override;
  void mouseDown(cinder::app::MouseEvent) override;
  void mouseDrag(cinder::app::MouseEvent) override;
  static void CreateButton(std::string text, const cinder::ivec2& size, const cinder::vec2& loc, cinder::Color color);
  cinder::Surface copyDraw();
  void UpdateFileName();
  void DrawButtons();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
