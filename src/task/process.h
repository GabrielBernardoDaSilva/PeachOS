#pragma once
#include <stdint.h>
#include "config.h"
#include "task.h"

struct process
{
    // process id
    uint16_t id;

    char filename[PEACHOS_MAX_PATH];
    // main task
    struct task* task;
    // the memory malloc of the process
    void* allocation[PEACHOS_MAX_PROGRAM_ALLOCATION];
    // physical pointer to process memory
    void* ptr;
    // physical pointer to the stack memory
    void* stack;
    // size of the data pointed to by "ptr"
    uint32_t size;

};
int process_load(const char* filename, struct process** process);

int process_load_for_slot(const char* filename, struct process** process, int process_slot);