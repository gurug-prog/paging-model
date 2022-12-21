#ifndef PROCESS_H
#define PROCESS_H

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
void        Process_run                 (Process* self);

#endif // PROCESS_H
