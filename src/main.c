#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "stepcounters/stepcounters.h"

#define STEPS_CONTROLLED_PATH "../data/steps/controlled/"
#define STEPS_UNCONTROLLED_PATH "../data/steps/uncontrolled/"

void becnhmarkFolder(char *prefix, char *dirname)
{
    DIR *folder;

    folder = opendir(dirname);
    if (folder == NULL)
    {
        perror("Unable to read controlled steps directory");
        return;
    }
    struct dirent *entry;

    while ((entry = readdir(folder)))
    {
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..") && strcmp(entry->d_name, ".DS_Store"))
        {
            long int GT = strtol(entry->d_name, NULL, 10);

            char path[100];
            strcpy(path, dirname);
            strcat(path, entry->d_name);

            FILE *pFile = fopen(path, "r");
            if (pFile == NULL)
            {
                printf("%s", path);
                perror("Error opening file");
            }
            else
            {
                int lineN = 0;
                long int old_ts = -1;
                char line[1024];
                while (fgets(line, 1024, pFile))
                {
                    if (lineN)
                    {
                        long int ts, x, y, z;
                        // file format: Time (ms),X,Y,Z
                        char *tmp = strdup(line);
                        char *pEnd;
                        char *tok = strtok(tmp, ",");
                        ts = strtol(tok, &pEnd, 10);
                        tok = strtok(NULL, ",\n");
                        x = strtol(tok, &pEnd, 10);
                        tok = strtok(NULL, ",\n");
                        y = strtol(tok, &pEnd, 10);
                        tok = strtok(NULL, ",\n");
                        z = strtol(tok, &pEnd, 10);
                        free(tmp);

                        processStep(ts, x, y, z);
                    }
                    lineN++;
                }

                // print out results
                printSteps(prefix, entry->d_name, GT);

                fclose(pFile);
            }
        }
    }
    closedir(folder);
}

int main()
{
    printf("Testing step counters\n\n");

    initStepCounters();

    becnhmarkFolder("steps-controlled", STEPS_CONTROLLED_PATH);

    resetStepCounters();

    becnhmarkFolder("steps-uncontrolled", STEPS_UNCONTROLLED_PATH);

    resetStepCounters();

    return 0;
}