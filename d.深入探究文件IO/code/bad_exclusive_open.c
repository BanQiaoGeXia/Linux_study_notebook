fd = open(argv[1], O_WRONLY);
if(fd != -1)
{
	printf("[PID %ld] File \"%s\" already exists\n", (long)getpid(), argv[1]);
	close(fd);
}
else{
	if(errno != ENOENT)
	{
		errExit("open");
	}
	else
	{
		fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		if(fd == -1)
		{
			errExit("open");
			printf("[PID %ld] Created file \"%s\" exclusively\n", (long)getpid(), argv[1]);
		}
	}
}