
# Yiy - YouTube Video Downloader

Yiy is a versatile command-line tool to download high-quality videos or audio-only files from YouTube. With options for format selection and automatic merging, Yiy simplifies video downloads and media management.

## Features

- **Video and Audio Download**: Download video, audio, or combined streams from YouTube.
- **Enhanced Format Selection**: Choose specific video or audio formats manually, or let Yiy automatically select the highest quality.
- **Automatic Merging**: Seamlessly merges video and audio into a single MP4 file.
- **Command-Line Simplicity**: Easily download media with minimal commands.

## Installation

### Prerequisites
Ensure you have:
- **C++ Compiler** (e.g., GCC or Clang)
- **yt-dlp** for YouTube data extraction
- **ffmpeg** for video-audio merging

#### Install Dependencies

```bash
# Install yt-dlp and ffmpeg on Ubuntu/Debian
sudo apt install yt-dlp ffmpeg

# On macOS with Homebrew
brew install yt-dlp ffmpeg
```

#### Clone Repository

```bash
git clone https://github.com/tov171/yiy.git
cd yiy
```

### Building

Compile Yiy using the Makefile:

```bash
make
```

## Usage

### Basic Download Command

Run `yiy` and follow the prompts to enter a YouTube URL and select a format.

```bash
./yiy
Enter the video URL:
https://www.youtube.com/watch?v=yourvideo
```

### Format Selection

After entering the URL, Yiy displays available formats (video and audio). Enter a format ID to download or press enter for auto-selection.

### Example Commands

- **Download audio-only**: Select an audio format ID (e.g., `140` for m4a).
- **Download video**: Choose a video format ID with or without audio.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file.

## Contributing

Contributions and issues are welcome!

### Acknowledgments

- Built with [yt-dlp](https://github.com/yt-dlp/yt-dlp) for YouTube video data.
- Uses [ffmpeg](https://ffmpeg.org/) for media merging.
