#include "task.h"
#include "memory/memory.h"
#include "memory/heap/kheap.h"
#include "status.h"
#include "kernel.h"
#include "process.h"


//current task is running
struct task* current_task = 0x00;
//linked list part
//end
struct task* task_tail = 0x00;
//begin
struct task* task_head = 0x00;

struct task* task_current()
{
    return current_task;
}

struct task* task_get_next()
{
    if (!current_task->next)
        return task_head;
    return current_task->next;
}

static void task_list_remove(struct task* task)
{
    if (task->previous)   
        task->previous->next = task->next;
    
    if (task == task_head)
        task_head = task->next;

    if (task == task_tail)
        task_tail = task->previous;
    
    if (task == current_task)
        current_task = task_get_next();   
}

int task_free(struct task* task)
{
    paging_free_4gb(task->page_directory);
    task_list_remove(task);

    //removing task
    kfree(task);
    return 0;
}

int task_init(struct task* task, struct process* process)
{
    memset(task, 0x00, sizeof(task));
    // map entire 4gb address space to its self 
    task->page_directory = paging_new_4gb(PAGING_IS_PRESENT | PAGING_ACCESS_FROM_ALL);
    if (!task->page_directory)
        return -EIO;
    task->registers.ip = PEACHOS_PROGRAM_VIRTUAL_ADDRESS;
    task->registers.ss = USER_DATA_SEGMENT;
    task->registers.esp = PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_START;
    task->process = process;

    return 0;

    
}

struct task* task_new(struct process* process)
{
    int res = 0;
    struct task* task = kzalloc(sizeof(struct task));
    if (!task)
    {
        res = -ENOMEM;
        goto out;
    }

    res = task_init(task, process);
    if (res != PEACHOS_ALL_OK)
        goto out;
    if (task_head == 0x00)
    {
        task_head = task;
        task_tail = task;
    }

    task_tail->next = task;
    task->previous = task_tail;
    task_tail = task;
out:   
    if (ISERR(res))
    {
        task_free(task);
        return ERROR(res);
    }
    return task;
}

