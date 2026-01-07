#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
    FILE *log = fopen("text.txt", "w");
    while (1) {
        time_t timestamp = time(NULL);
        struct tm *local_time = localtime(&timestamp);
        fprintf(log, "%d-%d-%d %.2d:%.2d:%.2d\n", 
            local_time->tm_year + 1900,
            local_time->tm_mon + 1,
            local_time->tm_mday,
            local_time->tm_hour,
            local_time->tm_min,
            local_time->tm_sec);
        fflush(log);
        sleep(1);
    }
    return 0;
}

