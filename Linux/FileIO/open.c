#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char str[100];

    fd = open("cd.txt", O_RDONLY);
    if(fd < 0)
    {
        perror("open");
    }

    while(read(fd, str, sizeof(str)) > 0)
    {
        printf("%s", str);
    }

    return 0;
}
