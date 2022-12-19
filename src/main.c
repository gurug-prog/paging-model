#include <stdio.h>
#include <time.h>
#include "process/process.h"


int main()
{
    srand(time(0));

    printf("sizeof(Process) = %ld\n", sizeof(Process));
    printf("Before allocation\n");

    Process* p = Process_initRandomized();
    printf("After allocation\n");
    Process_free(p);

    printf("After freeing\n");

    return 0;
}
