#ifndef UTILS_H
#define UTILS_H

enum class FileState {
    Unknown,
    Created,
    Deleted,
    Edited,
    Renamed
};

enum class FileType {
    File,
    Directory
};


#endif // UTILS_H