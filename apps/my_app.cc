// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>

#include <../blocks/Cinder-QRCodeGenerator/src/QRCodeGenerator.h>


namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() { }

void MyApp::setup() {

}

void MyApp::update() {

    QRCodeGenerator generator = QRCodeGenerator();
    Surface8u image = generator.generate("test string", 5);
}

void MyApp::draw() {

}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
