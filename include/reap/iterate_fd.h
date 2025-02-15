#ifndef REAP_ITERATE_FD_H
#define REAP_ITERATE_FD_H

#include <dirent.h>

#include "definitions.h"

typedef struct reapFdIterator {
    DIR *dir;
    pid_t pid;
} reapFdIterator;

typedef struct reapFdResult {
    int fd;
    char file[SHORT_PATH_SIZE];
} reapFdResult;

int
reapFdIteratorInit(pid_t pid, reapFdIterator *iterator);

void
reapFdIteratorClose(reapFdIterator *iterator);

int
reapFdIteratorNext(reapFdIterator *iterator, reapFdResult *result);

int
reapReadFd(pid_t pid, int fd, char *dest, size_t size);

#endif  // REAP_ITERATE_FD_H
