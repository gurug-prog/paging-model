#include "page-table/page_table.h"
#include "working_set.h"


PageTable*          ProcessGenerator_genPageTable           ();
WorkingSet*         ProcessGenerator_genWorkingSet          (PageTable* pageTable);
int                 ProcessGenerator_genTimeSlice           ();
int                 ProcessGenerator_genWorkingSetLifetime  ();
