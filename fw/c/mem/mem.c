#include <stdio.h>
#include <stdlib.h>

#define BYTE_ALIGN          64

void *get_mem(size_t size)
{
    return malloc(size);
}

void free_mem(void *ptr)
{
    free(ptr);
}

int main(void)
{
    size_t size = 100;
    void *buffer;

    buffer = get_mem(size);
    if(NULL != buffer)
    {
        printf("Allocated buffer address is:%p\n",buffer);
        free_mem(buffer);
    }
    return 0;
}
