#pragma once

#define KERNAL_CODE_SELECTOR                            0x08
#define KERNAL_DATA_SELECTOR                            0x10
#define PEACHOS_TOTAL_INTERRUPTS                        512
//HEAP
#define PEACHOS_HEAP_SIZE_BYTES                         104857600
#define PEACHOS_HEAP_BLOCK_SIZE                         4096
#define PEACHOS_HEAP_ADDRESS                            0x01000000
#define PEACHOS_HEAP_TABLE_ADDRESS                      0x00007e00


#define PEACHOS_SECTOR_SIZE                             512
#define PEACHOS_MAX_FILESYSTEMS                         12
#define PEACHOS_MAX_FILE_DESCRIPTOR                     512

#define PEACHOS_TOTAL_GDT_SEGMENTS                      6

#define PEACHOS_PROGRAM_VIRTUAL_ADDRESS                 0x400000
#define PEACHOS_USER_PROGRAM_STACK_SIZE                 1024 * 16
#define PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_START     0x3ff00
#define PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_END       PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_START - PEACHOS_USER_PROGRAM_STACK_SIZE

#define USER_DATA_SEGMENT                               0x23
#define USER_CODE_SEGMENT                               0x1b

