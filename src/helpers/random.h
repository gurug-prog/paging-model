#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>

#define UNIQ_BUF_SIZE   256
#define GEN_VALUE(min, max) (rand() % (max - min + 1) + min)

typedef struct Random Random;
struct Random
{
    size_t generatedSizes[UNIQ_BUF_SIZE];
    int uniqSizesCount;
    int generatedInts[UNIQ_BUF_SIZE];
    int uniqIntsCount;
};

Random* Random_init         (void);
void    Random_free         (Random* self);
int     Random_genUniqInt   (Random* self, int min, int max);
size_t  Random_genUniqSize  (Random* self, size_t min, size_t max);


#endif // RANDOM_H
