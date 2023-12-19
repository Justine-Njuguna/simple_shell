#ifndef OUR_BUILTINS_H
#define OUR_BUILTINS_H

#include "general_code.h"
#include "txt.h"
#include "memories.h"
#include "commander.h"

/* buitin_file.c */
int check_the_builtins(general_t *information, char **args);
int builtin_files(general_t *information, char **args);
void bin_unsetenv(general_t *information, char **args);
void bin_setenv(general_t *information, char **args);

/* exits.c */
void bin_exits(general_t *information, char **args);
int nums_control(general_t *information, char *num);

/* env_1.c */
void bin_env_1(general_t *information, char **args);

/* echoes.c */
void bin_echoes(general_t *information, char **args);
void print_echoes(int idx, char *txt, char **args);

/**/
#endif
