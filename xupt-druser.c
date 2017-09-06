#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <pppd/pppd.h>

char pppd_version[] = VERSION;

extern option_t auth_options[];

int update_user(char **argv)
{
	if(strlen(*argv) > 8 && (
	   strcmp(*argv + 8, "@telecom") == 0 ||
	   strcmp(*argv + 8, "@unicom") == 0)) {
		strcpy(user, "\r\n");
		strcpy(user + 2, *argv);
	} else {
		strcpy(user, *argv);
	}
	return 1;
}

void plugin_init(void)
{
	option_t *authopt = auth_options;
	while(authopt->name) {
		if(strcmp(authopt->name, "user") == 0) {
			authopt->type = o_special;
			authopt->flags = OPT_PRIO | OPT_A2STRVAL;
			authopt->addr = update_user;
			authopt->addr2 = user;
			break;
		}
		authopt++;
	}
}
