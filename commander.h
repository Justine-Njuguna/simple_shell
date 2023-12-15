#ifndef COMMANDER_H
#define COMMANDER_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#include "general_code.h"
#include "txt.h"
#include "errhandlers.h"
#include "our_builtins.h"
#include "memories.h"

extern char **environ;

/* handle_commands.c */
void get_analysis(char **args, general_t *information, char *buff);

/* give_permissions.c */
int check_is_executable(char *fname);
int check_is_file(char *commands);

/* env_2.c */
char *_get_env(const char *name);
char *check_which(char *fname, general_t *information);
void check_is_current_path(char *path, general_t *information);
void check_get_full_env(void);

/* punisher.c(execute.c) */
void punish(char *commands, char **args, general_t *information, char *buff);
int check_current_dir(char *cmd, char **args, char *buff, general_t *information);

#endif
