#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = -1, ret = -1;
    char buf[200];
    fd_set myset;
    struct timeval tm;

    //fd = open("/dev/input/mousel", O_RDONLY);
    //if(fd < 0)
    //{
        //perror("open:");
        //return -1;
    //}

    FD_ZERO(&myset);
    //FD_SET(fd, &myset);
    FD_SET(0, &myset);

    tm.tv_sec = 10;
    tm.tv_usec = 0;

    ret = select(0+1, &myset, NULL, NULL, &tm);
    if(ret < 0)
    {
        perror("select: ");
        return -1;
    }
    else if(ret == 0)
    {
        printf("timeout");
    }
    else
    {
        if(FD_ISSET(0, &myset))
        {
            memset(buf, 0, sizeof(buf));
            read(0, buf, 5);
            printf("what does the keyboard read:[%s].\n", buf);
        }

        //if(FD_ISSET(fd, &myset))
        //{
            //memset(buf, 0, sizeof(buf));
            //read(0, buf, 50);
            //printf("what does the mousel read:[%s].\n", buf);
        //}
    }

    return 0;
}
