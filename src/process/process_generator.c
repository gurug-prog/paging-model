#include "process_generator.h"
#include "process_conf.h"
#include "page-table/page_table_entry.h"
#include "helpers/random.h"


PageTable* ProcessGenerator_genPageTable()
{
    PageTable* pt = malloc(sizeof(PageTable));
    size_t vasSize = 16;
    pt->pageEntries = malloc(vasSize * sizeof(PageTableEntry*));
    // int vasSize = GEN_VALUE(
    //     PROCESS_MIN_VAS_SIZE, PROCESS_MAX_VAS_SIZE);

    for (size_t i = 0; i < vasSize; i++)
    {
        PageTableEntry* entry = pt->pageEntries[i];
        entry = malloc(sizeof(PageTableEntry));
        PageTableEntry_initDefault(entry);
    }

    return pt;
}

PageTableEntry** ProcessGenerator_genWorkingSet()
{
    // Not implemented
    return (PageTableEntry**)NULL;
}

int ProcessGenerator_genTimeSlice()
{
    // Not implemented
    return 0;
}

int ProcessGenerator_genWorkingSetLifetime()
{
    // Not implemented
    return 0;
}
