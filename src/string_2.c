#include <stdio.h>
#include <string.h>

void saperate_key_value(char *key[], char *val[], char *string)
{
    char **key_ptr = key;
    char **val_ptr = val;
    char *saveptr1, *saveptr2;

    char *token = strtok(string, ":");
    *key_ptr = strtok(token, "=");
    *val_ptr = strtok(NULL, "=");

    key_ptr++;
    val_ptr++;

    for (;;)

    while ((token = strtok(NULL, ":")) != NULL) //为什么可以这样写？
    {
        *key_ptr = strtok(token, "=");
        *val_ptr = strtok(NULL, "=");

        key_ptr++;
        val_ptr++;
    }
}