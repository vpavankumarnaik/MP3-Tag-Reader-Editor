# MP3-Tag-Reader-Editor
C-based tool to read, view, and edit MP3 metadata (ID3 tags) without modifying audio, helping organize music libraries efficiently.

## Features
- Read metadata from MP3 files.
- Edit and update ID3 tags (Title, Artist, Album, Year, Genre).
- Lightweight and runs in the command line.
- No external dependencies required.

## Folder Structure
All project files are in the root directory:

MP3-Tag-Reader-Editor/
│
├── mp3_main.c
├── mp3_edit.c
├── mp3_view.c
├── populate.c
├── mp3_header.h
├── README.md
├── LICENSE
└── .gitignore

## Compilation
To compile the project using `gcc`:

```bash
gcc *.c -o mp3_editor

Usage
Run the compiled program:

./mp3_editor
