#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <fcntl.h>


int main(int argc, char **argv) {
	int i;
	int saved_stdin;
	int savefile_in;
	int chfd;

	int fd = open("tmp", O_CREAT | O_RDWR | O_APPEND, 0644);
	saved_stdin = dup(1);  // saved file fd
	savefile_in = dup(fd);
	// redir->saved_stdout = dup(1);
	// redir->saved_stdin = dup(0);


	printf("parent pid is: %d\n", getpid());
   // for (i = 0; i < 2; i++) 
	{
		dup2(fd, 1); // default: write to a file
		write(1, "i am in this file, like it or not\n", 34);
		int pid = fork();
		int status;
		
		if (pid > 0) {
			write(1, "can i print to the terminal??\n", 30);
			dup2(1, fd);	// try to switch back
			write(1, "how about now ??\n", 17);
			dup2(saved_stdin, 1);
			write(1, "ok, let's see this on terminal ??\n", 34);

			close(saved_stdin);
			wait(&status);
		}
		else {
			chfd = open("new", O_CREAT | O_RDWR | O_APPEND, 0644);
			printf("CHILD pid is: %d\n", getpid());
			dup2(chfd, 1);
			close(chfd);
			write(1, "CHILD process writing to tje 1\n",31);
			close(saved_stdin);
			close(fd);
			close(savefile_in);
			exit(0);
		}
	}
	close(fd);
	close(savefile_in);
}



/*int main(int argc, char **argv) {
	int i;
	printf("parent pid is: %d\n", getpid());
	for (i = 0; i < 2; i++) {
		int pid = fork();
		int status;
		if (pid) {
			wait(&status);
		}
		else {
			char *test = malloc(5000);
			char *args[2] = {"Hello, world!", NULL};
			execve("/bin/echo", args, NULL);
			/*printf("--- CHILD: my pid is: %d\n", getpid());
			char *ptr = (char *)malloc(2*sizeof(char));
		   // free(ptr);
		   // free(test);
		}
	}
}

*/
