// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/converter.h>
#include <cinder/ImageIo.h>
#include <cinder/Utilities.h>

namespace mylibrary {

void ConvertImage(cinder::Surface surface, std::string name) {
    cinder::writeImage("C:/Users/HP/Documents/CinderFiles/" + name + ".jpg", surface);
}

}  // namespace mylibrary
