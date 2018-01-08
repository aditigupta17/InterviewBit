#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd, cd; //file-descriptor, copy-descriptor
	fd = open("random", O_CREAT | O_APPEND | O_RDWR, 0600);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}
	cd = dup(fd);
	write(cd, "I have a pen\n", 13);
	write(fd, "I have an apple\n", 16);
	return 0;
}
