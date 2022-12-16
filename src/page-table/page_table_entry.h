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

void    PageTableEntry_init         (PageTableEntry* self);
void    PageTableEntry_initDefault  (PageTableEntry* self);

#endif // PAGE_TABLE_ENTRY_H
