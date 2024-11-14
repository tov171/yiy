#include <iostream>
#include "yiy.h"

int main() {
    std::string video_url;
    std::cout << "Enter the video URL: ";
    std::cin >> video_url;

    // Display available formats to the user
    showFormats(video_url);

    std::string format_id;
    std::cout << "Enter the format ID you want to download: ";
    std::cin >> format_id;

    // Download the video in the chosen format
    downloadVideo(video_url, format_id);

    return 0;
}

