// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>

#include <mylibrary/converter.h>
#include "C:\Users\HP\CLionProjects\Cinder\MyProjects\final-project-earthy1024\apps\my_app.h"

TEST_CASE("Random sanity test", "[random]") {
  const float random = cinder::randFloat();
  REQUIRE(0. <= random);
  REQUIRE(random <= 1.);
}

TEST_CASE("Correct image url") {
    std::string url = "https://imgur.com/";
    REQUIRE(mylibrary::ConnectToHost("C:/Users/HP/Documents/CinderFiles/TestUpload.jpg") != url);
}

TEST_CASE("Get correct qr code image") {
    std::string url = "www.imgur.com";
    std::string path = "C:/Users/HP/Documents/CinderFiles/www.imgur.com/.jpg";
    REQUIRE(mylibrary::CreateQRCode(url) == path);
}

TEST_CASE("Get correct qr code from web link") {
    std::string url = mylibrary::ConnectToHost("C:/Users/HP/Documents/CinderFiles/TestUpload.jpg");
    REQUIRE(mylibrary::CreateQRCode(url) == "C:/Users/HP/Documents/CinderFiles/https://imgur.com/a/yisyZik/.jpg");
}
