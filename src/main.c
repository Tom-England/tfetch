#include "check_stats.c"
#include <stdio.h>

#define RED         "[0;31m"
#define BOLDRED     "[1;31m"
#define GREEN       "[1;32m"
#define NOCOLOUR		""

int main(){

	char* temp = read_temp();
	char* uptime = get_uptime();
	char* ip_addr = get_ip_addr();
	char* memory_usage = get_mem_usage();
	
	char** logo = get_logo();

	// For some reason attempting to get hostname via getenv("HOSTNAME")
	// returns null despite $HOSTNAME being a valid env variable
	// This function is also not in linux/unistd.h hence the second include
	char hostname[255 + 1];
	gethostname(hostname, 255 + 1);

	char host[255];
	sprintf(host, "%s@%s", getenv("USER"), hostname);

	printf("\n");
	print(1, host, "", GREEN);
	print(0, logo[0], "", NOCOLOUR);
	
	print(1, "Current uptime: ", uptime, RED);
	print(0, logo[1], "", NOCOLOUR);

	print(1, "CPU Temp: ", temp, RED);
	print(0, logo[2], "", NOCOLOUR);

	print(1, "IP Address: ", ip_addr, RED);
	print(0, logo[3], "", NOCOLOUR);

	print(1, "Memory: ", memory_usage, RED);
	print(0, logo[4], "", NOCOLOUR);

	printf("\n");

	free(uptime);
	free(temp);
	return 0;
}
