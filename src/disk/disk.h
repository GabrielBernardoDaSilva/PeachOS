#pragma once
#include "fs/file.h"

//represents real physical disk
#define PEACHOS_DISK_TYPE_REAL 0

typedef unsigned int PEACHOS_DISK_TYPE;
struct disk
{
    PEACHOS_DISK_TYPE type;
    int sector_size; 
    //the disk id
    int id;
    struct filesystem* filesystem;
    //private data of our filesystem
    void* fs_private;
};

struct disk* disk_get(int index);
void disk_search_and_init();
int disk_read_block(struct disk* idisk, unsigned int lba, int total, void* buf);