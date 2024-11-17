#ifndef YIY_H
#define YIY_H

#include <string>

// List available video formats
void listAvailableFormats(const std::string& video_url);

// List available audio formats
void listAvailableAudioFormats(const std::string& video_url);

// Download video in the selected format
void downloadVideo(const std::string& video_url, const std::string& format_id);

// Download audio in the selected format
void downloadAudio(const std::string& video_url, const std::string& format_id);

// Download and merge video and audio formats
void downloadAndMerge(const std::string& video_url, const std::string& video_format_id, const std::string& audio_format_id);

#endif

