// Attribution-ShareAlike 2.0 Generic (CC BY-SA 2.0)
// Code from Stackoverflow: https://stackoverflow.com/a/22762558/33611
// Thank you apangin: https://stackoverflow.com/users/3448419/apangin
#include <stdlib.h>
#include <unistd.h>

int JVM_ActiveProcessorCount(void) {
    char* val = getenv("_NUM_CPUS");
    return val != NULL ? atoi(val) : sysconf(_SC_NPROCESSORS_ONLN);
}
