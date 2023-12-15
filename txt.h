#ifndef TXT_H
#define TXT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "general_code.h"
#include "memories.h"

/* txt.c */
void prompt_start(general_t *information);
void prompt_me(general_t *information);
char *get_prompt();
void sigintHandler(int sigNum);

/* utility_txt.c */
int _strlen(char *message);
char *_strcat(char *destination, char *source);
char *_strcpy(char *destination, char *source);
char *_strdup(char *string);
int _strcmp(char *string1, char *string2);

/* utility_txt2.c */
char *check_to_string(int num);
int check_is_numerical(unsigned int x);
int check_is_atoi(char *x);
int contains_letter(char *s);

/* printing.c */
int _putchar_to_fdesc(char c, int fd);
int print_to_fdesc(char *message, int fd);

/* print_out.c */
int _putchar(char a);
int print(char *message);

/* print_error.c */
int print_error(char *message);

/* tokenizah.c */
char **word_split(char *line, const char *delim);
char *join_words(char *word1, char *word2, char *word3, const char *delim);

/* patternize.c */
void pattern_analyze(general_t *information, char **args);
char *handle_patterns(general_t *information, char *str);
char *val_replace(general_t *information, int *idx, char *str);

/* replace_patternize.c */
char *replacement(general_t *information, int *idx, char *str);
char *replace_environment(general_t *information, char *env);

#endif /* TXT_H */
