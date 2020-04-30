// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <mylibrary/converter.h>

#include <cinder/app/App.h>
#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <cinder/Vector.h>
#include <cinder/params/Params.h>
#include <cinder/app/RendererGl.h>
#include <rpc.h>
#include <list>

namespace myapp {

using cinder::Color;
using cinder::app::KeyEvent;
using cinder::app::MouseEvent;
using cinder::TextBox;

cinder::params::InterfaceGlRef mParams;
bool begin_draw = true;
bool draw_finished = false;
std::vector<cinder::vec2> button_list;
std::vector<std::string> button_name;
MyApp::PaintSize paint_size = MyApp::PaintSize::One;
MyApp::PaintColor paint_color = MyApp::PaintColor::Red;
cinder::ivec2 button_size = cinder::ivec2(50, 30);

MyApp::MyApp() { }

void MyApp::setup() {
    cinder::gl::enableDepthWrite();
    cinder::gl::enableDepthRead();

}

void MyApp::update() {
    if (draw_finished) {
        return;
    }
    else {
        if (paint_color == PaintColor::Red) {

        }
    }
}

void MyApp::draw() {
    cinder::gl::enableAlphaBlending();
    if (begin_draw) {
        cinder::gl::clear(Color(0, 0, 0));
        begin_draw = false;
        // button("");
        CreateButton("Blue", button_size, cinder::vec2(750, 100));
        CreateButton("Green", button_size, cinder::vec2(750, 150));
        CreateButton("Red", button_size, cinder::vec2(750, 200));
        CreateButton("Small", button_size, cinder::vec2(750, 270));
        CreateButton("Medium", button_size, cinder::vec2(750, 320));
        CreateButton("Big", button_size, cinder::vec2(750, 370));
        CreateButton("Large", button_size, cinder::vec2(750, 420));
        CreateButton("Submit", button_size, cinder::vec2(500, 800));
    }

}

void MyApp::DrawPaint(MouseEvent event) const {
    if (paint_color == PaintColor::Red) {
        cinder::gl::color(1, 0, 0);
    } else if (paint_color == PaintColor::Green) {
        cinder::gl::color(0, 1, 0);
    } else if (paint_color == PaintColor::Blue) {
        cinder::gl::color(0, 0, 1);
    }
    cinder::gl::drawSolidCircle(event.getPos(), static_cast<float>(paint_size));
}

void MyApp::keyDown(KeyEvent event) {

}


void MyApp::mouseDown(MouseEvent event) {
    if (event.isLeftDown()) {
        for (int index = 0; index < button_list.size(); index++) {
            if (event.getPos().x < button_list[index].x + 25
            &&  event.getPos().x > button_list[index].x - 25
            &&  event.getPos().y < button_list[index].y + 15
            &&  event.getPos().y > button_list[index].y - 15) {
                if (button_name[index] == "Submit") {
                    cinder::Surface surface = copyWindowSurface();
                    // Add user input code
                    mylibrary::ConvertImage(surface, "TestTwo");

                    // This segment can be used to open QRCode surface
                    cinder::gl::clear(Color(0, 0, 0));
                    cinder::gl::color(1, 1, 1);
                    cinder::Surface newSurface = cinder::Surface(cinder::loadImage("C:/Users/HP/Documents/CinderFiles/testqrcode.png"));
                    cinder::gl::Texture2dRef texture = cinder::gl::Texture::create(newSurface);
                    cinder::gl::draw(texture);
                }
                SelectColor(button_name[index]);
                SelectSize(button_name[index]);
            }
        }
    }
}

void MyApp::mouseDrag(MouseEvent event) {
    if (event.isLeftDown()) {
        DrawPaint(event);
    }
}


void MyApp::SelectColor(const std::string& text) {
    if (text == "Red") {
        paint_color = PaintColor::Red;
    } else if (text == "Green") {
        paint_color = PaintColor::Green;
    } else if (text == "Blue") {
        paint_color = PaintColor::Blue;
    }
}

void MyApp::SelectSize(const std::string& text) {
    if (text == "Small") {
        paint_size = PaintSize::One;
    } else if (text == "Medium") {
        paint_size = PaintSize::Two;
    } else if (text == "Big") {
        paint_size = PaintSize::Three;
    } else if (text == "Large") {
        paint_size = PaintSize::Four;
    }
}


void MyApp::CreateButton(const std::string& text, const cinder::ivec2& size, const cinder::vec2& loc) {
    cinder::gl::color(Color::white());

    button_list.push_back(loc);
    button_name.push_back(text);

    auto box = TextBox()
        .alignment(TextBox::CENTER)
        .font(cinder::Font("Arial", 20))
        .size(size)
        .color(Color::black())
        .backgroundColor(cinder::ColorA(1, 1, 1))
        .text(text);

    const auto box_size = box.getSize();
    const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
    const auto surface = box.render();
    const auto texture = cinder::gl::Texture::create(surface);
    cinder::gl::draw(texture, locp);
}


}  // namespace myapp
