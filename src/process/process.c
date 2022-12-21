#include "process.h"
#include "process_generator.h"
#include "helpers/random.h"

#include <stdio.h>


static void Process_accessWorkingSet(Process* self);
static void Process_accessAny(Process* self);
static void Process_accessPage(PageTableEntry* page, bool accessType, int pageIndex);
static void Process_readPage(PageTableEntry* page, int pageIndex);
static void Process_modifyPage(PageTableEntry* page, int pageIndex);


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

void Process_run(Process* self)
{
    bool oneOfCountersIsOver = false;
    bool isWorkingSetAccess = false;
    int wsAccessCount = (self->timeSlice * 9) / 10;
    int anyAccessCount = self->timeSlice - wsAccessCount;

    for (int i = 0; i < self->timeSlice; i++)
    {
        if (!oneOfCountersIsOver)
        {
            isWorkingSetAccess = GEN_VALUE(false, true);
        }

        if (isWorkingSetAccess)
        {
            Process_accessWorkingSet(self);
            wsAccessCount--;

            if (wsAccessCount == 0)
            {
                oneOfCountersIsOver = true;
                isWorkingSetAccess = !isWorkingSetAccess;
                continue;
            }
        }
        else
        {
            Process_accessAny(self);
            anyAccessCount--;

            if (anyAccessCount == 0)
            {
                oneOfCountersIsOver = true;
                isWorkingSetAccess = !isWorkingSetAccess;
                continue;
            }
        }
    }
}

static void Process_accessWorkingSet(Process* self)
{
    bool accessType = GEN_VALUE(false, true);
    int pageIndex = GEN_VALUE(0, self->workingSet->size - 1);
    PageTableEntry* page = self->workingSet->pages[pageIndex];

    printf("WS: ");
    Process_accessPage(page, accessType, pageIndex);
}

static void Process_accessAny(Process* self)
{
    bool accessType = GEN_VALUE(false, true);
    int pageIndex = GEN_VALUE(0, self->pageTable->size - 1);
    PageTableEntry* page = self->pageTable->pageEntries[pageIndex];

    printf("ANY: ");
    Process_accessPage(page, accessType, pageIndex);
}

static void Process_accessPage(PageTableEntry* page, bool accessType, int pageIndex)
{
    if (accessType)
    {
        Process_readPage(page, pageIndex);
    }
    else
    {
        Process_modifyPage(page, pageIndex);
    }
}

static void Process_readPage(PageTableEntry* page, int pageIndex)
{
    page = page;
    printf("Page #%d read\n", pageIndex);
}

static void Process_modifyPage(PageTableEntry* page, int pageIndex)
{
    page = page;
    printf("Page #%d modified\n", pageIndex);
}
