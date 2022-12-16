#include "page-table/page_table.h"

PageTable*          ProcessGenerator_genPageTable           ();
PageTableEntry**    ProcessGenerator_genWorkingSet          ();
int                 ProcessGenerator_genTimeSlice           ();
int                 ProcessGenerator_genWorkingSetLifetime  ();
