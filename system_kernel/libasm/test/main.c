#include "header.h"

void strlen_test() {

    printf("\n\ttesting ft_strlen:\n\n");

    char * str = strdup("ptrtest");

    printf("ft_strlen(\"test\") = %d\n", ft_strlen("test"));
    printf("strlen(\"test\") = %d\n", strlen("test"));
    write(1, "\n", 1);
    printf("ft_strlen(\"\") = %d\n", ft_strlen(""));
    printf("strlen(\"\") = %d\n", strlen(""));
    write(1, "\n", 1);
    printf("ft_strlen(str) = %d\n", ft_strlen(str));
    printf("strlen(str) = %d\n", strlen(str));
    write(1, "\n", 1);
    // printf("strlen(NULL) = %d\n", strlen(NULL));
    // printf("ft_strlen(NULL) = %d\n", ft_strlen(NULL));
}

void strcpy_test() {

    printf("\n\ttesting ft_strcpy:\n\n");

    char * dst1 = calloc(5, sizeof(char));

    printf("ft_strcpy(dst1, \"test\") = %s\n", ft_strcpy(dst1, "test"));
    printf("strcpy(dst1, \"test\") = %s\n", strcpy(dst1, "test"));
    write(1, "\n", 1);
    printf("ft_strcpy(dst1, \"\") = %s\n", ft_strcpy(dst1, ""));
    printf("strcpy(dst1, \"\") = %s\n", strcpy(dst1, ""));
    // write(1, "\n", 1);
    // printf("strcpy(dst1, NULL) = %s\n", strcpy(dst1, NULL));
    // printf("ft_strcpy(dst1, NULL) = %s\n", ft_strcpy(dst1, NULL));
}

void strcmp_test() {

    printf("\n\ttesting ft_strcmp:\n\n");

    printf("ft_strcmp(\"test\", \"test\") = %d\n", ft_strcmp("test", "test"));
    printf("strcmp(\"test\", \"test\") = %d\n", strcmp("test", "test"));
    write(1, "\n", 1);
    printf("ft_strcmp(\"test\", \"test2\") = %d\n", ft_strcmp("test", "test2"));
    printf("strcmp(\"test\", \"test2\") = %d\n", strcmp("test", "test2"));
    write(1, "\n", 1);
    printf("ft_strcmp(\"test3\", \"test\") = %d\n", ft_strcmp("test3", "test"));
    printf("strcmp(\"test3\", \"test\") = %d\n", strcmp("test3", "test"));
    // write(1, "\n", 1);
    // printf("strcmp(\"test4\", NULL) = %d\n", strcmp("test4", NULL));
    // printf("ft_strcmp(\"test4\", NULL) = %d\n", ft_strcmp("test4", NULL));
}

void write_test() {

    printf("\n\ttesting ft_write:\n\n");

    printf("ft_write(1, \"salut \", 6) = %d", ft_write(1, "salut ", 6));
    printf(" | strerrno = %s\n", strerror(errno));

    errno = 0;
    printf("write(1, \"salut \", 6) = %d", write(1, "salut ", 6));
    printf(" | strerrno = %s\n", strerror(errno));

    write(1, "\n", 1);

    errno = 0;
    printf("ft_write(-1, \"salut \", 6) = %d", ft_write(-1, "salut ", 6));
    printf(" | strerrno = %s\n", strerror(errno));

    errno = 0;
    printf("write(-1, \"salut \", 6) = %d", write(-1, "salut ", 6));
    printf(" | strerrno = %s\n", strerror(errno));

    errno = 0;
}

void read_test() {

    printf("\n\ttesting ft_read:\n\n");

    int fd = open("./test/read.txt", 0);
    int fd2 = open("./test/read.txt", 0);
    char buff[16];

    ft_read(fd, buff, 14);
    printf("ft_read(fd, buff, 14) = %s", buff);
    printf(" | strerrno = %s\n", strerror(errno));

    read(fd2, buff, 14);
    printf("read(fd, buff, 14) = %s", buff);
    printf(" | strerrno = %s\n", strerror(errno));

    write(1, "\n", 1);

    ft_read(-1, buff, 14);
    printf("ft_read(-1, buff, 14) | strerrno = %s\n", strerror(errno));
    
    errno = 0;
    read(-1, buff, 14);
    printf("read(-1, buff, 14) | strerrno = %s\n", strerror(errno));

    errno = 0;
}

void strdup_test() {

    printf("\n\ttesting ft_strdup:\n\n");

    char * str = strdup("ptrtest");

    printf("ft_strdup(\"test\") = %s\n", ft_strdup("test"));
    printf("strdup(\"test\") = %s\n", strdup("test"));

    write(1, "\n", 1);

    printf("ft_strdup(str) = %s\n", ft_strdup(str));
    printf("strdup(str) = %s\n", strdup(str));
}

int main() {

    strlen_test();
    strcpy_test();
    strcmp_test();
    write_test();
    read_test();
    strdup_test();
    write(1, "\n", 1);

    return 0;
}