#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd;
    char *p = "test";
    char str[100];

    fd = open("cd.txt", O_RDWR | O_APPEND);
    if(fd < 0)
    {
        perror("open");
    }

    if(write(fd, p, strlen(p)) != strlen(p))
    {
        write(2, "write error\n", 12);
    }

    lseek(fd, 0, SEEK_SET);
    while(read(fd, str, sizeof(str)) > 0)
    {
        printf("%s", str);
    }

    return 0;
}
