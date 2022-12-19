#ifndef PAGE_TABLE_ENTRY_H
#define PAGE_TABLE_ENTRY_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct PageTableEntry PageTableEntry;
struct PageTableEntry
{
    bool presence;
    bool reference;
    bool modification;
};

PageTableEntry* PageTableEntry_init         ();
PageTableEntry* PageTableEntry_initDefault  ();
void    PageTableEntry_free (PageTableEntry* self);

#endif // PAGE_TABLE_ENTRY_H
