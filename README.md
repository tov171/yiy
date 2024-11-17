
# YIY - YouTube Video Downloader

YIY is a simple and efficient command-line YouTube video downloader written in C++. It allows users to download videos and audio from YouTube with ease.

## Features
- Choose specific video and audio formats for downloading.
- Automatically merge video and audio streams into a single file.
- Uses FFmpeg for merging video and audio.
- Supports various YouTube video qualities.

## Requirements
- [FFmpeg](https://ffmpeg.org/) (installed and available in the system's PATH)
- [yt-dlp](https://github.com/yt-dlp/yt-dlp) (a fork of youtube-dl with additional features)

## Installation
Follow the steps below to install YIY on your system.

1. Clone the repository:
   ```bash
   git clone https://github.com/tov171/yiy.git
   ```

2. Navigate to the project directory:
   ```bash
   cd yiy
   ```

3. Install the required dependencies:
   ```bash
   sudo apt-get update
   sudo apt-get install ffmpeg
   pip install -r requirements.txt
   ```

4. Build the project:
   ```bash
   make
   ```

5. Run the program:
   ```bash
   ./yiy [YouTube URL]
   ```

## Usage
- Provide the YouTube URL as a command-line argument.
- Select the desired format when prompted.
- YIY will automatically download and merge the video and audio.

## Contributing
Contributions are welcome! Feel free to fork the repository and submit pull requests.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
