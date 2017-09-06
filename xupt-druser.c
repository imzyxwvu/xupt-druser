#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// from pppd.h
#define MAXNAMELEN	256	/* max length of hostname or name for auth */
extern char user[MAXNAMELEN];/* Our name for authenticating ourselves */
void info __P((char *, ...)); /* log an informational message */

char pppd_version[] = "2.4.7";

void plugin_init(void)
{
	char newuser[MAXNAMELEN] = {'\r', '\n', 0};
	strcpy(newuser + 2, user);
	strcpy(user, newuser);
	info("xupt-druser: OK!");
}
