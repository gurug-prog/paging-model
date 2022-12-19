#ifndef WORKING_SET_H
#define WORKING_SET_H

#include "page-table/page_table_entry.h"

typedef struct WorkingSet WorkingSet;
struct WorkingSet
{
    PageTableEntry** pages;
    size_t size;
};

WorkingSet* WorkingSet_initSize (size_t size);
void    WorkingSet_free (WorkingSet* self);
void    WorkingSet_setPage  (WorkingSet* self, PageTableEntry* page, int index);


#endif // WORKING_SET_H
