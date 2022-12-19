#include "page-table/page_table.h"
#include "working_set.h"


typedef struct Process Process;
struct Process
{
    PageTable* pageTable;
    WorkingSet* workingSet;
    int timeSlice;
    int workingSetLifetime;
};

Process*    Process_init                ();
Process*    Process_initRandomized      ();
void        Process_free                (Process* self);
