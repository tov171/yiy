
# Yiy - YouTube Video Downloader

Yiy is a command-line tool that allows you to download high-quality videos from YouTube. It automatically selects the best video and audio quality and merges them into a single MP4 file for easy playback.

## Features
- **Download videos from YouTube**: Get the highest quality video available.
- **Auto selection of best video and audio formats**: Automatically chooses the best format for both video and audio, saving you the hassle.
- **Video and audio merging**: Combines the video and audio into a single MP4 file.
- **Simple CLI interface**: Easy to use command-line interface to download videos in just a few commands.

## Installation

### Prerequisites
Before using Yiy, you need to install the following dependencies:
- **C++ compiler**: Make sure you have a C++ compiler installed (GCC or Clang).
- **yt-dlp**: A YouTube video downloader that helps extract video data.
- **ffmpeg**: A tool to merge video and audio files.

#### Installing Dependencies

1. **Install yt-dlp**:
   On Ubuntu/Debian-based systems:
   ```bash
   sudo apt install yt-dlp
   ```

   On macOS (with Homebrew):
   ```bash
   brew install yt-dlp
   ```

2. **Install ffmpeg**:
   On Ubuntu/Debian-based systems:
   ```bash
   sudo apt install ffmpeg
   ```

   On macOS (with Homebrew):
   ```bash
   brew install ffmpeg
   ```

3. **Clone the repository**:
   ```bash
   git clone https://github.com/tov171/yiy.git
   cd yiy
   ```

### Building the Project
Yiy uses a `Makefile` to handle the build process. Follow these steps to compile the project:

1. **Build the project**:
   ```bash
   make
   ```

2. After building, you should have an executable file named `yiy`.

## Usage

### Downloading a Video

To download a video from YouTube, simply run the following command with the video URL:

```bash
./yiy https://www.youtube.com/watch?v=yourvideoID
```

### Format Selection (Optional)

After entering the video URL, the tool will display a list of available formats. You can select the format you want by entering its ID (for example, 22 for 720p MP4). If you don't select a format, the tool will automatically choose the best available format.

### Merging Video and Audio

Yiy automatically merges the video and audio streams into a single MP4 file, so you don’t have to worry about handling them separately.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Feel free to fork this project, open issues, and submit pull requests. Contributions are welcome!

---

### **Acknowledgments**

- This project uses [yt-dlp](https://github.com/yt-dlp/yt-dlp) for extracting YouTube video information.
- [ffmpeg](https://ffmpeg.org/) is used for merging video and audio files.
