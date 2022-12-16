#include "page_table_entry.h"

void PageTableEntry_init(PageTableEntry* self)
{
    // TODO: implement
    self = self;
    // (void*)self;
}

void PageTableEntry_initDefault(PageTableEntry* self)
{
    self->presence = false;
    self->reference = false;
    self->modification = false;
}
