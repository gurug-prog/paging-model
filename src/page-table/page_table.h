#include <page_table_entry.h>

typedef struct PageTable PageTable;
struct PageTable
{
    PageTableEntry** pageEntries;
};
