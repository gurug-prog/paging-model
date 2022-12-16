#include "page-table/page_table.h"

typedef struct Process Process;
struct Process
{
    PageTable* pageTable;
};
