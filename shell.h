#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE	1024
#define BUF_FLUSH	-1
#define SHELL_MSG	"$ "


/**
 * struct programData - a struct that holds and program and
 * passed arguments
 *
 * @get_cmd: inputed command from getline()
 * @cmd: full command with "/bin/"
 *
 */
typedef struct programData
{

	char *get_cmd;
	char **cmd;
	char *run_cmd;
	char *prog_name;
	char **env;
} data_t;


/*----------------------------------------------*/
/*		start main.c			*/

/*		clear the struct		*/
void init_data(data_t *data, int ac, char **av, char **env);

/*		clear getline() str		*/
char *clear_getline(char *str);

/*		start the loop			*/
void shell_loop(data_t *data, int ac, char **av, char **env);

/*		handle CTRL C			*/
void handle_sig(int sig);

/*		end main.c			*/
/*----------------------------------------------*/





/*----------------------------------------------*/
/*		start paths.c			*/

/*		filtering the command		*/
void filter_cmd(data_t *data);

/*		get command location	 	*/
char *get_location(data_t *data);

/*		end paths.c			*/
/*----------------------------------------------*/


/*----------------------------------------------*/
/*		start args.c			*/

args(data_t *data, int ac, char **av);

/*		end args.c			*/
/*----------------------------------------------*/





/*----------------------------------------------*/
/*		start help_string_1.c		*/

char *full_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *full_strdup(char *str);

/* 		start help_strint_2.c		*/
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);

/*		end help_string.c		*/
/*----------------------------------------------*/






/*----------------------------------------------*/
/*		start help_print.c		*/

int writechar(int c);
int writestr(char *str);
size_t _strlen(char *s);

/*		end help_print.c		*/
/*----------------------------------------------*/





/*----------------------------------------------*/
/*		start help_free.c		*/

void free_data(data_t *data);
void free_grid_char(char **array);
void free_used_data(data_t *data);
/*		end help_free.c			*/
/*----------------------------------------------*/





#endif
