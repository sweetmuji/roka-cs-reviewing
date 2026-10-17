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
    
    while(index !=1 && (h->heap[index/2].key < item.key)) {
        h->heap[index] = h->heap[index/2];
        index /= 2;
    }
    
    h->heap[index] = item;
}

element delete_max_heap(HeapType* h)
{
    element item = h->heap[1];
    element temp = h->heap[h->heap_size--];
    int parent = 1;
    int child = 2;
    
    while(child <= h->heap_size) {
        if(h->heap[child].key < h->heap[child + 1].key)
            child++;
        
        if(temp.key >= h->heap[child].key)
            break;
        
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    
    h->heap[parent] = temp;
    return item;
}

void heap_sort(element a[], int n)
{
    HeapType* h;
    
    h = create();
    init(h);
    
    for(int i = 0; i < n; i++)
    {
        insert_max_heap(h, a[i]);
    }
    
    for(int i = (n-1); i >= 0; i--)
    {
        a[i] = delete_max_heap(h);
    }
    
    free(h);
}

#define SIZE 10 
int main(void)
{
    element list[SIZE] = { 13, 34, 12, 23, 0, 19, 6, 31, 9, 10 };
    heap_sort(list, SIZE);
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d -> ", list[i].key);
    }
    printf("\n");
    
    return 0;
}