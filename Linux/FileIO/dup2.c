#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd, fd1, n;
    char str[100];

    fd = open("cd.txt", O_RDONLY);
    if(fd < 0)
    {
        perror("open cd.txt\n");
        return 1;
    }
    fd1 = open("cd1.txt", O_RDWR | O_TRUNC);
    if(fd1 < 0)
    {
        perror("open cd1.txt\n");
        return 1;
    }

    //close(1);
    int newfd = dup2(fd1, 1);
    if(newfd < 0)
    {
        perror("dup");
        return 1;
    }
    printf("newfd = %d.\n", newfd);

    while(n = read(fd, str, sizeof(str)) > 0)
    {
        if((n = write(newfd, str, strlen(str))) != n)
        {
            printf("write error\n");
        }
        printf("%s", str);
    }

    close(fd1);
    close(fd);
    close(newfd);

    return 0;
}
