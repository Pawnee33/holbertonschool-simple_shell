#include "shell.h"
/**
 * print_pid - Prints the ID of the child processus
 *
 * Return: void
 */
void print_pid(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
}
