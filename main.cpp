#include <iostream>
#include <string>
#include "yiy.h"

void showHelp() {
    std::cout << "=============================================\n";
    std::cout << "              YIY Video Downloader           \n";
    std::cout << "=============================================\n";
    std::cout << "Usage: yiy [OPTIONS]\n";
    std::cout << "OPTIONS:\n";
    std::cout << "  --help             Show this help message and exit\n";
    std::cout << "  --version          Show the version of the tool\n";
    std::cout << "  No arguments       Run the interactive video downloader\n";
    std::cout << "\nExample:\n";
    std::cout << "  yiy                Start the interactive video downloader\n";
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    // Handle command-line arguments
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--help") {
            showHelp();
            return 0;
        } else if (arg == "--version") {
            std::cout << "YIY Video Downloader v1.0.0" << std::endl;
            return 0;
        } else {
            std::cerr << "Invalid option: " << arg << std::endl;
            std::cerr << "Run `yiy --help` for usage information." << std::endl;
            return 1;
        }
    }

    // Interactive mode
    std::cout << "===============================================\n";
    std::cout << "         YIY Video Downloader                  \n";
    std::cout << "===============================================\n";

    std::string videoUrl;
    std::cout << "Enter the video URL: ";
    std::getline(std::cin, videoUrl);

    listAvailableFormats(videoUrl);

    std::cout << "Enter the format ID to download: ";
    std::string formatId;
    std::getline(std::cin, formatId);

    std::cout << "Choose the download type:\n";
    std::cout << "1. Video + Audio (Merged)\n";
    std::cout << "2. Video Only\n";
    std::cout << "3. Audio Only\n";
    std::cout << "Enter your choice (1, 2, or 3): ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        downloadAndMerge(videoUrl, formatId, "bestaudio");
    } else if (choice == 2) {
        downloadVideo(videoUrl, formatId);
    } else if (choice == 3) {
        listAvailableAudioFormats(videoUrl);
        std::cout << "Enter the audio format ID to merge with the video: ";
        std::string audioFormatId;
        std::cin >> audioFormatId;
        downloadAndMerge(videoUrl, formatId, audioFormatId);
    } else {
        std::cerr << "Invalid choice!" << std::endl;
    }

    return 0;
}

