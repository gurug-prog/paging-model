#include <stdio.h>
#include <time.h>
#include "process/process.h"


int main()
{
    srand(time(NULL));

    printf("sizeof(Process) = %ld\n", sizeof(Process));
    printf("Before allocation\n");

    Process* p = Process_initRandomized();
    printf("After allocation\n");

    Process_run(p);

    Process_free(p);

    printf("After freeing\n");

    return 0;
}
