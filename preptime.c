#include <stdio.h>
#include <time.h>

#define FORMAT "%Y/%m/%d %H:%M:%S"
#define TSMAX 50
#define LINEMAX 1024

char *current_utc_timestamp(char *out);

int main(int argc, char **argv)
{
    char line[LINEMAX], timestamp[TSMAX];
    int c, idx;

    idx = 0;

    while ((c = getchar()) != EOF) {
        line[idx++] = c;
        if (c == '\n' || idx == LINEMAX) {
            line[idx] = '\0';
            if (!current_utc_timestamp(timestamp)) {
                printf("%s: Error formatting the timestamp\n", argv[0]);
                return 1;
            }
            printf("%s :: %s", timestamp, line);
            idx = 0;
        }
    }
    return 0;
}

char *current_utc_timestamp(char *out)
{
    time_t now;
    struct tm *tm;
    now = time(NULL);
    tm = gmtime(&now);
    if (!strftime(out, TSMAX, FORMAT, tm)) {
        return NULL;
    }
    return out;
}
