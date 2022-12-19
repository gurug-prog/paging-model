#include "page_table.h"

PageTable* PageTable_initSize(size_t size)
{
    PageTable* self = malloc(sizeof(PageTable));
    self->size = size;
    self->pageEntries = malloc(size * sizeof(PageTableEntry*));

    for (size_t i = 0; i < size; i++)
    {
        self->pageEntries[i] = PageTableEntry_initDefault();
    }

    return self;
}

void PageTable_free(PageTable* self)
{
    for (size_t i = 0; i < self->size; i++)
    {
        PageTableEntry_free(self->pageEntries[i]);
    }

    free(self->pageEntries);
    free(self);
}
