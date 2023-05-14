#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


#define BUF_SIZE	1024
#define BUF_FLUSH	-1


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

/*		end main.c			*/
/*----------------------------------------------*/





/*----------------------------------------------*/
/*		start execute.c			*/

/*		filtering the command		*/
void filter_cmd(data_t *data);

/*		get the command location 	*/
char *get_location(char *cmd);

/*		end execute.c			*/
/*----------------------------------------------*/






/*----------------------------------------------*/
/*		start help_string.c		*/

char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/*		end help_string.c		*/
/*----------------------------------------------*/







/*----------------------------------------------*/
/*		start help_print.c		*/

int writechar(int c);
int writestr(char *str);
int _strlen(char *s);

/*		end help_print.c		*/
/*----------------------------------------------*/





/*----------------------------------------------*/
/*		start help_free.c		*/

void free_data(data_t *data);

/*		end help_free.c			*/
/*----------------------------------------------*/





#endif
