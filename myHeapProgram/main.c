#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 100

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_HEAP_SIZE];
    int heap_size;
} HeapType;

HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
    int index = ++h->heap_size;
    
    while(index != 1 && (item.key > h->heap[index / 2].key))
    {
        h->heap[index].key = h->heap[index/2].key;
        index /= 2;
    }
    
    h->heap[index] = item;
}

element delete_max_heap(HeapType* h)
{
    element temp, item;
    int parent = 1;
    int child = 2;
    
    item = h->heap[1]; // 반환할 최고 값
    temp = h->heap[h->heap_size--];
    
    while(child <= h->heap_size) {
        if(child < h->heap_size && (h->heap[child].key < h->heap[child + 1].key)) 
            child++;
            
        if(temp.key > h->heap[child].key)
            break;
        
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    
    h->heap[parent] = temp;
    return item;
}

void print_heap(HeapType* heap)
{
    if(heap->heap_size == 0)
    {
        return;
    }
    
    for(int i = 1; i <= heap->heap_size; i++)
    {
        printf("%d: %d -> ", i, heap->heap[i].key);
    }
    printf("\n");
}

int main(void)
{
    element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
    element e4, e5, e6;
    
    HeapType* heap;
    heap = create();
    init(heap);
    
    insert_max_heap(heap, e1); print_heap(heap);
    insert_max_heap(heap, e2); print_heap(heap);
    insert_max_heap(heap, e3); print_heap(heap);
    
    e4 = delete_max_heap(heap); print_heap(heap);
    e5 = delete_max_heap(heap); print_heap(heap);
    e6 = delete_max_heap(heap); print_heap(heap);
    
    free(heap);
    return 0;
}