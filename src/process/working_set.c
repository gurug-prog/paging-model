#include "working_set.h"

WorkingSet* WorkingSet_initSize(size_t size)
{
    WorkingSet* self = malloc(sizeof(WorkingSet));
    self->size = size;
    self->pages = malloc(size * sizeof(PageTableEntry*));

    return self;
}

void WorkingSet_setPage(WorkingSet* self, PageTableEntry* page, int index)
{
    // we assume that a passed index is in bounds
    // of the working set array and a page is in bounds
    // of the virtual address space (process page table)
    self->pages[index] = page;
}

void WorkingSet_free(WorkingSet* self)
{
    free(self->pages);
    free(self);
}
