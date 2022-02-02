#pragma once

#include "config.h"
#include "memory/paging/paging.h"

struct registers
{
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;

    uint32_t ip;
    uint32_t cs;
    uint32_t flags;
    uint32_t esp;
    uint32_t ss;
};

struct process;

struct task
{
    // the page directory of the task
    struct paging_4gb_chunk* page_directory;
    // the registers of the task when the task is not running
    struct registers registers;
    // the process of the task
    struct process* process;
    // next task on the link list
    struct task* next;
    // previous task
    struct task* previous;
};

struct task* task_new(struct process* process);
struct task* task_current();
struct task* task_get_next();
int task_free(struct task* task);
int task_switch(struct task* task);

void task_run_first_ever_task();

void restore_general_purpose_registers(struct registers* regs);
void task_return(struct registers* regs);
void user_registers();

