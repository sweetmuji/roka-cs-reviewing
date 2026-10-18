#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 100

typedef struct {
    int id; // 기계가 사용할 ID
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
    
    while((index != 1) && (item.key > h->heap[index / 2].key)) {
        h->heap[index] = h->heap[index / 2];
        index /= 2;
    }
    
    h->heap[index] = item;
}

void insert_min_heap(HeapType* h, element item)
{
    int index = ++h->heap_size;
    
    while((index != 1) && (item.key < h->heap[index / 2].key)) {
        h->heap[index] = h->heap[index / 2];
        index /= 2;
    }
    
    h->heap[index] = item;
}

element delete_max_heap(HeapType* h)
{
    int parent = 1;
    int child = 2;
    element item = h->heap[1];
    element temp = h->heap[h->heap_size--];
    
    while((child < h->heap_size) && child <= h->heap_size) {
        if(h->heap[child].key < h->heap[child + 1].key)
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

element delete_min_heap(HeapType* h)
{
    int parent = 1;
    int child = 2;
    element item = h->heap[1];
    element temp = h->heap[h->heap_size--];
    
    while(child <= h->heap_size) {
        if((child < h->heap_size) && h->heap[child].key > h->heap[child + 1].key)
            child++;
        
        if(temp.key < h->heap[child].key)
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
    int i;
    HeapType* h;
    
    h = create();
    init(h);
    
    for(int i = 0; i < n; i++)
    {
        insert_max_heap(h, a[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        a[i] = delete_max_heap(h);
    }
}

#define JOBS 7
#define MACHINES 3

int main(void)
{
    element jobs[JOBS];
    
    for(int i = 0; i < JOBS; i++)
    {
        int input;
        printf("%d번 작업의 소요 시간을 입력하세요:", i);
        scanf("%d", &input);
        
        jobs[i].key = input;
        jobs[i].id = 0;
    }
    heap_sort(jobs, JOBS); // 히프 정렬
    
    printf("\n작업은 다음과 같이 정렬되었습니다...   ");
    for(int i = 0; i < JOBS; i++)
    {
        printf("%d ->", jobs[i].key);
    }
    printf("\n\n");
    
    element machine = { 0, 0 };
    
    HeapType* h;
    h = create();
    init(h);
    
    for(int i = 0; i < MACHINES; i++)
    {
        machine.id = i + 1;
        machine.key = 0;
        insert_min_heap(h, machine);
    }
    
    for(int i = 0; i < JOBS; i++)
    {
        machine = delete_min_heap(h);
        printf("JOB %d를 시간 = %d 부터 시간 = %d 까지 기계 %d 번에 할당한다.\n", i, machine.key, machine.key + jobs[i].key - 1, machine.id);
        machine.key += jobs[i].key;
        insert_min_heap(h, machine);
    }
    
    return 0;
}

