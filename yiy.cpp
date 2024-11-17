#include <iostream>
#include <cstdlib>
#include "yiy.h"

// Helper function to execute system commands and handle errors
void executeCommand(const std::string& command) {
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "\033[1;31mError: Command failed - " << command << "\033[0m\n";
    }
}

// List available video formats
void listAvailableFormats(const std::string& video_url) {
    std::string command = "yt-dlp -F \"" + video_url + "\" | grep -E 'mp4|webm' | awk '{print \"\\033[1;34m\" $0 \"\\033[0m\"}'";
    executeCommand(command);
}

// List available audio formats
void listAvailableAudioFormats(const std::string& video_url) {
    std::string command = "yt-dlp -F \"" + video_url + "\" | grep -E 'audio' | awk '{print \"\\033[1;36m\" $0 \"\\033[0m\"}'";
    executeCommand(command);
}

// Download video
void downloadVideo(const std::string& video_url, const std::string& format_id) {
    std::string command = "yt-dlp -f " + format_id + " \"" + video_url + "\"";
    executeCommand(command);
}

// Download audio
void downloadAudio(const std::string& video_url, const std::string& format_id) {
    std::string command = "yt-dlp -f " + format_id + " \"" + video_url + "\"";
    executeCommand(command);
}

// Download and merge video + audio
void downloadAndMerge(const std::string& video_url, const std::string& video_format_id, const std::string& audio_format_id) {
    std::string command = "yt-dlp -f " + video_format_id + "+" + audio_format_id + " --merge-output-format mp4 \"" + video_url + "\"";
    executeCommand(command);
}

