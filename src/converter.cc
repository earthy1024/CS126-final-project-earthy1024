// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/converter.h>
#include <cinder/ImageIo.h>
#include <cinder/Utilities.h>
#include <curl/curl.h>
#include <iostream>
#include <fstream>

namespace mylibrary {

void ConvertImage(cinder::Surface surface, std::string name) {
    std::string path_name = "C:/Users/HP/Documents/CinderFiles/" + name + ".jpg";
    cinder::writeImage(path_name, surface);
    ConnectToHost(path_name);
}
void ConnectToHost(std::string path) {

    FILE *file = fopen("C:/Users/HP/Documents/CinderFiles/TestTwo.jpg", "rb");

    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://imgur.com/upload?beta");
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, file);
    curl_easy_cleanup(curl);



    std::cout << "test" << std::endl;
    std::cout << curl_url() << std::endl;

    /*
    curl_easy_reset(curl);
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.qr-code-generator.com/");
    curl_easy_cleanup(curl);
     */
}
}  // namespace mylibrary
