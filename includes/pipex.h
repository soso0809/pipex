// includes/pipex.h
#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h" // Si tu utilises ta libft
# include <fcntl.h>                   // open flags (O_RDONLY, etc.)
# include <stdio.h>                   // perror (pour les erreurs)
# include <stdlib.h>                  // malloc, free, exit
# include <sys/wait.h>                // waitpid
# include <unistd.h>                  // open, close, read, write, pipe, dup2,
	execve


/* ************************************************************************** */
/*
* Purpose:  display a message to stderr and exit the program with a given
	status.
* Function implemented: ft_error
***	- File descriptor for input
***	- File descriptor for output
***	- Array of arguments for command 1
***	- Full path to command 1 (e.g.: "/bin/ls")
***	- Array of arguments for command 2
***	- Full path to command 2
***	- 1 if here_doc mode is enabled (bonus), 0 otherwise
***	- Delimiter for here_doc (e.g.: "EOF")
*/
/* ************************************************************************** */
typedef struct s_data
{
	int fd_in;
	int fd_out;
	char **cmd1;
	char *cmd1_path;
	char **cmd2;
	char *cmd2_path;
	int here_doc;
	char *limiter;
}		t_data;


/* ************************************************************************** */
/* MANDATORY FUNCTION DECLARATIONS */
/* ************************************************************************** */


void	exit_error(char *msg);
char	*find_path(char *cmd, char **envp);
t_data	*parse_input(int argc, char **argv, char **envp);
void	execute_commands(t_data *data, char **envp);
void	free_data(t_data *data);

#endif
