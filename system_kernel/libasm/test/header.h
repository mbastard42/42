#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

extern int      ft_strlen(const char *);
extern char *   ft_strcpy(char *, const char *);
extern int      ft_strcmp(const char *, const char *);
extern size_t   ft_write(int, const void *, size_t);
extern size_t   ft_read(int, void *, size_t);
extern char *   ft_strdup(const char *);
