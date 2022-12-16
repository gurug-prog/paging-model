#include <stdbool.h>

typedef struct PageTableEntry PageTableEntry;
struct PageTableEntry
{
    bool presence;
    bool reference;
    bool modification;
};
