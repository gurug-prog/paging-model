#include "random.h"
#include <stdbool.h>

Random* Random_init()
{
    Random* self = malloc(sizeof(Random));
    self->uniqIntsCount = 0;
    self->uniqSizesCount = 0;
    return self;
}

void Random_free(Random* self)
{
    free(self);
}

int Random_genUniqInt(Random* self, int min, int max)
{
    int value;
    bool isUnique = false;
    while (!isUnique)
    {
        value = GEN_VALUE(min, max);
        isUnique = true;
        for (int i = 0; i < self->uniqIntsCount; i++)
        {
            if (value == self->generatedInts[i])
            {
                isUnique = false;
                break;
            }
        }
    }

    return value;
}

size_t Random_genUniqSize(Random* self, size_t min, size_t max)
{
    size_t value;
    bool isUnique = false;
    while (!isUnique)
    {
        value = GEN_VALUE(min, max);
        isUnique = true;
        for (int i = 0; i < self->uniqSizesCount; i++)
        {
            if (value == self->generatedSizes[i])
            {
                isUnique = false;
                break;
            }
        }
    }

    return value;
}
