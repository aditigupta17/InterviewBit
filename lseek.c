#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	int fd, ret, buff;
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	fd = open("random", O_CREAT | O_APPEND | O_RDWR, 0600);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}
	
	ret = write(fd, (void *) a, sizeof(a));
	if(fd < 0)
	{
		perror("write");
		close(fd);
		exit(1);
	}

	ret = lseek(fd, 4*sizeof(int), SEEK_SET);
	if(fd < 0)
	{
		perror("lseek");
		close(fd);
		exit(1);
	}

	ret = read(fd, &buff, sizeof(int));
	if(fd < 0)
	{
		perror("read");
		exit(1);
	}
	printf("b = %d\n", buff);
	close(fd);
}
