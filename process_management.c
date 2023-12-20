#include "main.h"

/**
 * create_process - Create a new process using fork
 *
 * Return: The PID of the new process, or -1 on failure
 */
pid_t create_process(void)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error: Failed to fork");
	}

	return (pid);
}

/**
 * wait_for_process - Wait for a process to change state
 * @pid: The PID of the process to wait for
 *
 * Return: The exit status of the process, or -1 on failure
 */
int wait_for_process(pid_t pid)
{
	int status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("Error: Failed to wait for process");
		return (-1);
	}

	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}

	return (-1);
}
