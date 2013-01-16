#include <stdio.h>
#include <time.h>

#define FORMAT "%Y/%m/%d %H:%M:%S"
#define OUTMAX 50

char *current_utc_timestamp(char *out);

int main(int argc, char **argv)
{
    char line[1000], out[OUTMAX];
    int c, idx;

    idx = 0;

    while ((c = getchar()) != EOF) {
        line[idx++] = c;
        if (c == '\n') {
            line[idx] = '\0';
            if (!current_utc_timestamp(out)) {
                printf("%s: Error formatting the timestamp\n", argv[0]);
                return 1;
            }
            printf("%s :: %s", out, line);
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
    if (!strftime(out, OUTMAX, FORMAT, tm)) {
        return NULL;
    }
    return out;
}
