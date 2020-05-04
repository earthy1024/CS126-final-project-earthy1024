// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/converter.h>
#include <cinder/ImageIo.h>
#include <cinder/Utilities.h>
#include <curl/curl.h>
#include <iostream>
#include <fstream>

namespace mylibrary {

void ConvertImage(cinder::Surface surface, const std::string& name) {
    std::string path_name = "C:/Users/HP/Documents/CinderFiles/" + name + ".jpg";
    cinder::writeImage(path_name, surface);
    // ConnectToHost(path_name);
}
std::string ConnectToHost(const std::string& path) {

    // Upload image
    struct curl_httppost *formpost = NULL;
    struct curl_httppost *last = NULL;
    std::string output;
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.imgur.com/3/image");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Authorization: Client-ID {{1d9f06fbc549636}}");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_mime *mime;
        curl_mimepart *part;
        mime = curl_mime_init(curl);
        part = curl_mime_addpart(mime);
        curl_mime_name(part, "image");
        curl_mime_data(part, path.c_str(), CURL_ZERO_TERMINATED);
        curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output.c_str());
        res = curl_easy_perform(curl);
        curl_mime_free(mime);
    }
    std::string url = std::string("https://imgur.com/") + output;
    return url;

}

std::string CreateQRCode(const std::string& url) {
    FILE *file;
    std::string path = "C:/Users/HP/Documents/CinderFiles/QR3.jpg";
    std::string link = "http(s)://api.qrserver.com/v1/create-qr-code/?data=" + url + "&size=[pixels]x[pixels]";

    /*
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
        file = fopen(path, "w");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        res = curl_easy_perform(curl);
        fclose(file);
        curl_easy_cleanup(curl);
    }
    */
    std::ofstream os(path, std::ostream::binary);
    CURL* curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &cb);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_FILE, &os);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return path;
}

static size_t cb(void *data, size_t size, size_t nmemb, void *userp)
{
    if(userp)
    {
        std::ostream& os = *static_cast<std::ostream*>(userp);
        std::streamsize len = size * nmemb;
        if(os.write(static_cast<char*>(data), len))
            return len;
    }

    return 0;
}

}  // namespace mylibrary
