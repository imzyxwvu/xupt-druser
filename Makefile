xupt-druser.so: xupt-druser.c
	$(CC) --shared -o $@ $< -fPIC

install: xupt-druser.so
	cp $< /usr/lib/pppd/2.4.*/
