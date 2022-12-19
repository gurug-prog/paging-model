#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include "page_table_entry.h"

typedef struct PageTable PageTable;
struct PageTable
{
    PageTableEntry** pageEntries;
    size_t size;
};

PageTable*  PageTable_initSize  (size_t size);
void    PageTable_free  (PageTable* self);

#endif // PAGE_TABLE_H
