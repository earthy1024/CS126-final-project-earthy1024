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

#include <Commdlg.h>



namespace myapp {

    using cinder::Color;
    using cinder::app::KeyEvent;
    using cinder::app::MouseEvent;
    using cinder::TextBox;
    bool begin_draw = true;
    bool draw_finished = false;
    bool start_type = false;
    bool path_typed = false;
    bool capital = false;
    bool search = false;
    bool clear = false;
    std::string filename = "C:/Users/HP/Documents/CinderFiles/";
    std::vector<cinder::vec2> button_list;
    std::vector<std::string> button_name;
    MyApp::PaintSize paint_size = MyApp::PaintSize::One;
    MyApp::PaintColor paint_color = MyApp::PaintColor::Red;
    cinder::ivec2 button_size = cinder::ivec2(60, 30);
    cinder::Surface current;
    OPENFILENAME ofn;
    char szFile[260];
    HWND hwnd;
    HANDLE hf;

    MyApp::MyApp() { }

    void MyApp::setup() {
        cinder::gl::enableDepthWrite();
        cinder::gl::enableDepthRead();

    }

    void MyApp::update() {
        if (draw_finished) {
            return;
        } else if (start_type) {
            cinder::gl::clear(Color(0, 0, 0));
            UpdateFileName();
            DrawButtons();
        } else if (path_typed) {
            path_typed = false;
            search = true;
        } else if (clear) {
            cinder::gl::clear(cinder::Color(0, 0, 0));
            DrawButtons();
            clear = false;
        }

    }
    cinder::Surface MyApp::copyDraw() {
        cinder::Surface surface = copyWindowSurface(cinder::Area(0, 0, 700, 700));
        return surface;
    }

    void MyApp::draw() {
        cinder::gl::enableAlphaBlending();
        if (begin_draw || draw_finished) {
            cinder::gl::clear(Color(0, 0, 0));
            begin_draw = false;
            draw_finished = false;
            // button("");
            DrawButtons();
        }
    }
    void MyApp::DrawButtons() {
        CreateButton("Blue", button_size, cinder::vec2(750, 70), cinder::Color(0, 0, 1));
        CreateButton("Green", button_size, cinder::vec2(750, 120), cinder::Color(0, 1, 0));
        CreateButton("Red", button_size, cinder::vec2(750, 170), cinder::Color(1, 0, 0));
        CreateButton("Orange", button_size, cinder::vec2(750, 220), cinder::Color(1, .8, 0));
        CreateButton("Teal", button_size, cinder::vec2(750, 270), cinder::Color(0, 1, 1));
        CreateButton("Purple", button_size, cinder::vec2(750, 320), cinder::Color(1, 0, 1));
        CreateButton("Small", button_size, cinder::vec2(750, 370), cinder::Color(0, 0, 0));
        CreateButton("Medium", button_size, cinder::vec2(750, 420), cinder::Color(0, 0, 0));
        CreateButton("Big", button_size, cinder::vec2(750, 470), cinder::Color(0, 0, 0));
        CreateButton("Large", button_size, cinder::vec2(750, 520), cinder::Color(0, 0, 0));
        CreateButton("Image", button_size, cinder::vec2(750, 570), cinder::Color(0, 0, 0));
        CreateButton("Clear", button_size, cinder::vec2(750, 620), cinder::Color(0, 0, 0));
        CreateButton("Submit", button_size, cinder::vec2(750, 670), cinder::Color(0, 0, 0));

        cinder::gl::color(1, 1, 1);
        cinder::gl::drawSolidRect(cinder::Rectf(700, 50, 800, 700));
    }

    void MyApp::DrawPaint(const MouseEvent& event) const {
        if (paint_color == PaintColor::Red) {
            cinder::gl::color(1, 0, 0);
        } else if (paint_color == PaintColor::Green) {
            cinder::gl::color(0, 1, 0);
        } else if (paint_color == PaintColor::Blue) {
            cinder::gl::color(0, 0, 1);
        } else if (paint_color == PaintColor::Orange) {
            cinder::gl::color(1, .8, 0);
        } else if (paint_color == PaintColor::Teal) {
            cinder::gl::color(0, 1, 1);
        } else if (paint_color == PaintColor::Purple) {
            cinder::gl::color(1, 0, 1);
        }
        cinder::gl::drawSolidCircle(event.getPos(), static_cast<float>(paint_size));
    }

    void MyApp::keyDown(KeyEvent event) {
        if (event.getCode() == KeyEvent::KEY_RSHIFT || event.getCode() == KeyEvent::KEY_LSHIFT) {
           capital = true;
           return;
        }
        if (event.getChar() == ' ') {
            path_typed = true;
            start_type = false;
            return;
        }
        if (capital) {
            filename += toupper(event.getChar());
            capital = false;
            return;
        }
        filename += event.getChar();
    }

    void MyApp::mouseDown(MouseEvent event) {
        if (search) {
            if (event.isLeftDown()) {
                cinder::gl::clear(Color(0, 0, 0));
                cinder::Surface image = cinder::Surface(cinder::loadImage(filename));
                cinder::gl::Texture2dRef texture2 = cinder::gl::Texture::create(image);
                cinder::gl::draw(texture2, cinder::vec2(event.getX() - 200, event.getY() - 200));
                cinder::gl::Texture2dRef texture1 = cinder::gl::Texture::create(current);
                cinder::gl::draw(texture1);
                DrawButtons();
                search = false;
            }
        }
        if (event.isLeftDown()) {
            for (int index = 0; index < button_list.size(); index++) {
                if (event.getPos().x < button_list[index].x + 30
                    &&  event.getPos().x > button_list[index].x - 30
                    &&  event.getPos().y < button_list[index].y + 15
                    &&  event.getPos().y > button_list[index].y - 15) {
                    if (button_name[index] == "Image") {
                        start_type = true;
                        path_typed = false;
                        current = copyDraw();
                        UpdateFileName();
                    } else if(button_name[index] == "Clear") {
                        clear = true;
                    } else if (button_name[index] == "Submit") {
                        mylibrary::ConvertImage(copyDraw(), "CropTest");
                    }
                    SelectColor(button_name[index]);
                    SelectSize(button_name[index]);
                }
            }
        }
    }

    void MyApp::UpdateFileName() {
        CreateButton("File: " + filename, cinder::ivec2(400, 30), cinder::vec2(400, 400), cinder::Color(0, 0, 0));
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
        } else if (text == "Orange") {
            paint_color = PaintColor::Orange;
        } else if (text == "Teal") {
            paint_color = PaintColor::Teal;
        } else if (text == "Purple") {
            paint_color = PaintColor::Purple;
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


    void MyApp::CreateButton(std::string text, const cinder::ivec2& size, const cinder::vec2& loc, const cinder::Color& color) {
        button_list.push_back(loc);
        button_name.push_back(text);

        if (color != cinder::Color(0, 0, 0)) {
            text = "";
        }
        cinder::gl::color(Color::white());



        auto box = TextBox()
                .alignment(TextBox::CENTER)
                .font(cinder::Font("Arial", 20))
                .size(size)
                .color(Color::white())
                .backgroundColor(cinder::ColorA(color))
                .text(text);

        const auto box_size = box.getSize();
        const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
        const auto surface = box.render();
        const auto texture = cinder::gl::Texture::create(surface);
        cinder::gl::draw(texture, locp);

    }


}  // namespace myapp
