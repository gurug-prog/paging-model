#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include "page_table_entry.h"

typedef struct PageTable PageTable;
struct PageTable
{
    PageTableEntry** pageEntries;
};


#endif // PAGE_TABLE_H
