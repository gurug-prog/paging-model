#include "process_generator.h"
#include "process_conf.h"
#include "helpers/random.h"


PageTable* ProcessGenerator_genPageTable()
{
    size_t vasSize = GEN_VALUE(
        PROCESS_MIN_VAS_SIZE, PROCESS_MAX_VAS_SIZE);
    PageTable* pt = PageTable_initSize(vasSize);

    return pt;
}

WorkingSet* ProcessGenerator_genWorkingSet(PageTable* pageTable)
{
    size_t wsSize = GEN_VALUE(PROCESS_MIN_VAS_SIZE, pageTable->size);
    WorkingSet* ws = WorkingSet_initSize(wsSize);
    Random* rand = Random_init();

    for (size_t i = 0; i < wsSize; i++)
    {
        int randIndex = Random_genUniqInt(rand, 0, pageTable->size - 1);
        PageTableEntry* page = pageTable->pageEntries[randIndex];
        WorkingSet_setPage(ws, page, i);
    }
    Random_free(rand);

    return ws;
}

int ProcessGenerator_genTimeSlice()
{
    return GEN_VALUE(PROCESS_MIN_TIMESLICE, PROCESS_MAX_TIMESLICE);
}

int ProcessGenerator_genWorkingSetLifetime()
{
    return GEN_VALUE(PROCESS_MIN_WS_LIFETIME, PROCESS_MAX_WS_LIFETIME);
}
