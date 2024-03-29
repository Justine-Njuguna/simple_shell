#ifndef GENERAL_CODE_H
#define  GENERAL_CODE_H

#define _TRUE            1
#define _FALSE           0

#define STDIN            0
#define STDOUT           1
#define STDERR           2

#define NON_INTERACTIVE  0
#define INTERACTIVE      1

#define PERMISSIONS      1
#define NON_PERMISSIONS -1

#define _FILE            10
#define NON_FILE         -10

#define _ENOENT          "No such file or directory"
#define _EACCES          "Permission denied"
#define _CMD_NOT_EXISTS  "not found"
#define _ILLEGAL_NUMBER  "Illegal number"

#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133

#define _CODE_SETENV_FAILURE   134
#define _CODE_UNSETENV_FAILURE 135
#define _CODE_WRONG_ARGUMENTS  136
#define _CODE_UNKNOWN_HOME     137
#define _CODE_GETCWD_FAILURE   138
#define _CODE_CHDIR_FAILURE    139
#define _CODE_UNKNOWN_HOME     137
#define _CODE_GETCWD_FAILURE   138
#define _CODE_CHDIR_FAILURE    139

typedef struct __attribute__((__packed__))
{
        int argc;                 /* Number of arguments received */
        char **argv;              /* Arguments received */
        int mode;                 /* INTERACTIVE or NON_INTERACTIVE */
        int error_code;           /* Error code for error message */
        char *command;            /* Command to execute */
        int n_commands;           /* Number of commands executed */
        char *value_path;         /* Path of a command */
        int check_is_current_path;      /* Check if is current path or not */
        int status_code;          /* Last exit code */
        char *buffer;             /* Line readed with the getline */
        char **arguments;         /* Line splited into words */
        char *environment;        /* Last environment variable get it */
        int pid;                  /* Process id */
} general_t;

typedef struct __attribute__((__packed__))
{
        char *message;            /* Error message */
        int code;                 /* Error code for identify the error message */
} error_t;

typedef struct __attribute__((__packed__))
{
        char *command;            /* arguments[0] = cmd */
        void (*func)(general_t *info, char **arguments);
} builtin_t;

#endif /* GENERAL_CODE_H */

