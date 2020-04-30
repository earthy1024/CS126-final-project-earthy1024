// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_CONVERTER_H_
#define FINALPROJECT_MYLIBRARY_CONVERTER_H_

#include <cinder/ImageIo.h>
#include <cinder/Surface.h>

namespace mylibrary {

void ConvertImage(cinder::Surface surface, std::string name);
void ConnectToHost(std::string path);
}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_CONVERTER_H_
