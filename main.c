#include <stdio.h>
#include <stdlib.h>
#include "leak_detector_c.h"

void remove_crlf(char *s);

/*
    Function Objective:
        - Within the file that is currently being read do the following:
            1. Skip blank lines
            2. Read information into "buf" array

    This function is meant to aid in the reading files without worrying about the issues of blank lines
    interrupting function processes.

*/
int get_next_nonblank_line(FILE *ifp, char *buf, int max_length)
{
    buf[0] = '\0';

    while(!feof(ifp) && (buf[0] == '\0'))
    {
        fgets(buf, max_length, ifp);
        remove_crlf(buf);
    }

    if(buf[0] != '\0') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Function Objective:
        - Find the end of the strings line and get rid of null terminator
*/
void remove_crlf(char *s)
{
    char *t = s + strlen(s);

    t--;


    while((t >= s) && (*t == '\n' || *t == '\r'))
    {
        *t = '\0';
        t--;
    }
}

struct Fail_Groups {
    char *name;
    char *type;
    struct Fail_Groups *next;
    struct Fail_Groups *prev;
};

typedef struct Fail_Groups FailGroup;


struct pond_list_struct {
    FailGroup *head;
    Fail_Group *tail;
};

typedef struct monster_list_struct monster_list;




int main()
{
    FILE *ipf; // Input File
    FILE *opf; // Output File

    ipf = fopen("cop3502-as2-input.txt", "r");
    opf = fopen("cop3502-as2-output-jared-delvalle.txt", "w");



    fclose(ipf);
    fclose(opf);


    return 0;
}














