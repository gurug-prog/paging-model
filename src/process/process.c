#include "process.h"
#include "process_generator.h"

Process* Process_init()
{
    Process* self = malloc(sizeof(Process));

    self->pageTable = NULL;
    self->workingSet = NULL;
    self->timeSlice = 0;
    self->workingSetLifetime = 0;

    return self;
}

Process* Process_initRandomized()
{
    Process* self = malloc(sizeof(Process));

    self->pageTable = ProcessGenerator_genPageTable();
    self->workingSet = ProcessGenerator_genWorkingSet(self->pageTable);
    self->timeSlice = ProcessGenerator_genTimeSlice();
    self->workingSetLifetime = ProcessGenerator_genWorkingSetLifetime();

    return self;
}

void Process_free(Process* self)
{
    PageTable_free(self->pageTable);
    WorkingSet_free(self->workingSet);
    free(self);
}
