// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <cinder/Vector.h>


namespace myapp {

using cinder::Color;
using cinder::app::KeyEvent;
using cinder::app::MouseEvent;
using cinder::TextBox;

bool begin_draw = true;
bool draw_finished = false;

MyApp::MyApp() { }

void MyApp::setup() {
    cinder::gl::enableDepthWrite();
    cinder::gl::enableDepthRead();
}

void MyApp::update() {
    if (!draw_finished) {
        return;
    }
    else {
        MouseEvent event = MouseEvent();
        mouseDown(event);
    }
}

void MyApp::draw() {
    cinder::gl::enableAlphaBlending();
    if (begin_draw) {
        cinder::gl::clear(Color(0, 0, 0));
        begin_draw = false;
    }
    MouseEvent event = MouseEvent();

}

void MyApp::drawPaint(MouseEvent event) const {
    cinder::gl::color((float) rand() / (float) RAND_MAX
            , (float) rand() / (float) RAND_MAX
            , (float) rand() / (float) RAND_MAX);
    cinder::gl::drawSolidCircle(event.getPos(), 20);

}
void MyApp::keyDown(KeyEvent event) {

}


void MyApp::mouseDown(MouseEvent event) {
    if (event.isLeftDown()) {
        drawPaint(event);
    }
}
    
void MyApp::mouseDrag(MouseEvent event) {
    if (event.isLeftDown()) {
        drawPaint(event);
    }
}


}  // namespace myapp
