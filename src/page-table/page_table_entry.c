#include "page_table_entry.h"

PageTableEntry* PageTableEntry_init()
{
    PageTableEntry* self = malloc(sizeof(PageTableEntry));

    return self;
}

PageTableEntry* PageTableEntry_initDefault()
{
    PageTableEntry* self = malloc(sizeof(PageTableEntry));
    self->presence = false;
    self->reference = false;
    self->modification = false;

    return self;
}

void PageTableEntry_free(PageTableEntry* self)
{
    free(self);
}
