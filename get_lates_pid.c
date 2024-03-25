#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h> 

int main() {
    int max_pid = 0;
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char *name = entry->d_name;
            if (strspn(name, "0123456789") == strlen(name)) {
                int pid = atoi(name);
                if (pid > max_pid) {
                    max_pid = pid;
                }
            }
        }
    }

    closedir(dir);

    printf("En büyük PID: %d\n", max_pid);

    return 0;
}