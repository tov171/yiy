
# Installation Guide for YIY

Follow these steps to install and use the YIY YouTube downloader on your system.

## Prerequisites
1. **FFmpeg**:
   - Install FFmpeg using your package manager. For Ubuntu/Debian:
     ```bash
     sudo apt-get update
     sudo apt-get install ffmpeg
     ```

2. **yt-dlp**:
   - Install yt-dlp using pip:
     ```bash
     pip install yt-dlp
     ```

3. **Development Tools**:
   - Ensure you have `make` and `g++` installed. For Ubuntu/Debian:
     ```bash
     sudo apt-get install build-essential
     ```

## Installation Steps
1. Clone the YIY repository:
   ```bash
   git clone https://github.com/tov171/yiy.git
   ```

2. Navigate to the project directory:
   ```bash
   cd yiy
   ```

3. Build the project using `make`:
   ```bash
   make
   ```

4. Run the program:
   ```bash
   ./yiy [YouTube URL]
   ```

## Notes
- Ensure `ffmpeg` and `yt-dlp` are accessible in your system's PATH.
- For any issues, refer to the README file or submit an issue on GitHub.
