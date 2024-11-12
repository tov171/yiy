#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

void download_video_and_audio(const std::string& video_url, const std::string& format_id) {
    // Combine video ID and best audio format (e.g., "298+bestaudio")
    std::string format_combination = format_id + "+bestaudio";

    // Download video and audio together
    std::string download_command = "yt-dlp -f " + format_combination + " -o \"%(title)s.%(ext)s\" " + video_url;
    
    std::cout << "Downloading video and audio...\n";
    system(download_command.c_str());

    // Extract the title for the file name
    std::string title_command = "yt-dlp --get-title " + video_url;
    char title_buffer[256];
    FILE* title_file = popen(title_command.c_str(), "r");
    if (title_file == nullptr) {
        std::cerr << "Error: Failed to get video title.\n";
        return;
    }
    fgets(title_buffer, sizeof(title_buffer), title_file);
    std::string video_title = title_buffer;
    video_title = video_title.substr(0, video_title.size() - 1);  // Remove newline character

    // Escape spaces and special characters in the video title
    char escaped_video_title[512];
    std::memset(escaped_video_title, 0, sizeof(escaped_video_title));
    for (size_t i = 0; i < video_title.size(); ++i) {
        if (video_title[i] == ' ') {
            strcat(escaped_video_title, "\\ ");
        } else if (video_title[i] == '@') {
            strcat(escaped_video_title, "\\@");
        } else {
            strncat(escaped_video_title, &video_title[i], 1);
        }
    }

    // The video and audio will now be downloaded together in the same file, no need for extra merging.
    std::cout << "Download completed: " << std::string(escaped_video_title) + ".mp4\n";
}

void show_formats(const std::string& video_url) {
    std::string command = "yt-dlp -F " + video_url;
    std::cout << "Available video formats:\n";
    system(command.c_str());
}

int main() {
    std::string video_url;
    std::string format_id;

    std::cout << "Enter the video URL: ";
    std::getline(std::cin, video_url);

    show_formats(video_url);

    std::cout << "Enter the format ID to download (e.g., 298 for 720p MP4): ";
    std::getline(std::cin, format_id);

    // Download video and audio automatically
    download_video_and_audio(video_url, format_id);

    return 0;
}

