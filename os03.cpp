// memory_manager.h

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <cstddef>

class MemoryManager {
public:
    void initialize(void* start, size_t size);
    void* allocate(size_t size);
    void free(void* ptr);

private:
    struct MemoryBlock {
        size_t size;
        bool is_free;
        MemoryBlock* next;
    };
    MemoryBlock* head;
};

#endif // MEMORY_MANAGER_H