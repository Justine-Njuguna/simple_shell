#ifndef ERR_HANDLERS_H
#define ERR_HANDLERS_H

#include "general_code.h"
#include "txt.h"

/* handle_errors.c */
char *msg_selector(general_t information);
void error(general_t *information);
void err_xtra(general_t *information, char *xtra);

#endif
