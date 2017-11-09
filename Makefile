CC=gcc

libnumcpus.so:
	$(CC) -O3 -fPIC -shared -Wl,-soname,$@ -o $@ numcpus.c

clean:
	rm libnumcpus.so
