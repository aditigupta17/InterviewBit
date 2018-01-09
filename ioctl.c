#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ioctl.h>
#include<linux/cdrom.h>
int main()
{
  int fd = open("/dev/dvd", O_RDONLY | O_NONBLOCK);
  ioctl(fd, CDROMEJECT);
  ioctl(fd, CDROMCLOSETRAY);
}
