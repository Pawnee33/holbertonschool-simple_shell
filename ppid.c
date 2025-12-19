#include "shell.h"
/**
 * print_ppid - Prints the ID of the parent processus
 *
 * Return: void
 */
void print_ppid(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%d\n", my_ppid);

}
