#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "yiy.h"

void showFormats(const std::string& video_url) {
    // Command to retrieve and display format information
    std::string format_command = "yt-dlp -F " + video_url;
    int result = system(format_command.c_str());

    if (result != 0) {
        std::cerr << "Error: Failed to retrieve format information.\n";
    }
}

void downloadVideo(const std::string& video_url, const std::string& format_id) {
    // Command to download video with audio if available
    std::string download_command = "yt-dlp -f " + format_id + "+bestaudio -o \"%(title)s.%(ext)s\" " + video_url;

    std::cout << "Downloading video in the chosen format...\n";
    int result = system(download_command.c_str());
    if (result != 0) {
        std::cerr << "Error: Download command failed with code " << result << ".\n";
        return;
    }

    // Extract title for renaming the file if necessary
    std::string title_command = "yt-dlp --get-title " + video_url;
    char title_buffer[256];
    FILE* title_file = popen(title_command.c_str(), "r");

    if (title_file == nullptr || fgets(title_buffer, sizeof(title_buffer), title_file) == nullptr) {
        std::cerr << "Error: Failed to get video title.\n";
        if (title_file) pclose(title_file);
        return;
    }

    pclose(title_file);
    std::string video_title = title_buffer;
    video_title = video_title.substr(0, video_title.size() - 1);  // Remove newline character

    // Rename output file to .mp4 if the selected format should be MP4
    if (format_id == "18" || format_id == "22" || format_id == "37") {
        std::cout << "Renaming output to .mp4...\n";
        std::string rename_command = "mv \"" + video_title + ".webm\" \"" + video_title + ".mp4\"";
        result = system(rename_command.c_str());
        if (result != 0) {
            std::cerr << "Error: Rename command failed with code " << result << ".\n";
        }
    }

    std::cout << "Download completed.\n";
}

