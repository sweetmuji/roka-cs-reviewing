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

element delete_max_heap(HeapType* h)
{
    element item, temp;
    
    item = h->heap[1]; // 반환할 노드 
    temp = h->heap[h->heap_size--]; // 마지막 노드
    int parent = 1;
    int child = 2;
    
    while(child <= h->heap_size) {
        if(child < h->heap_size && (h->heap[child].key < h->heap[child +1 ].key))
            child++; // 자식 노드 중에서 더 큰 것을 찾는다.
        
        if(temp.key < h->heap[child].key) {
            h->heap[parent] = h->heap[child];
            parent = child;
            child *= 2;
        }
        else if(temp.key >= h->heap[child].key) {
            break;
        }
    }
    
    h->heap[parent] = temp;
    return item;
}

void insert_max_heap_ver2(HeapType* heap, element item)
{
    if(heap->heap_size == MAX_HEAP_SIZE) {
        printf("HEAP_IS_FULL!\n");
        return;
    }
    
    int index;
    index = ++(heap->heap_size);
    
    while(index != 1 && (item.key > heap->heap[index / 2].key)) // 신규 노드가 1번 인덱스가 아니고 부모보다 키 값이 클 때
    {
        heap->heap[index] = heap->heap[index / 2];
        index = index / 2; // 부모 노드로 이동해 검사
    }
    
    heap->heap[index] = item;
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
    HeapType heap2;
    heap2.heap_size = 0;
    
    element temp;
    
    printf("===== 삽입 단계 =====\n");
    insert_max_heap_ver2(&heap2, (element){10}); print_heap(&heap2);
    insert_max_heap_ver2(&heap2, (element){5}); print_heap(&heap2);
    insert_max_heap_ver2(&heap2, (element){6}); print_heap(&heap2);
    insert_max_heap_ver2(&heap2, (element){100}); print_heap(&heap2);
    insert_max_heap_ver2(&heap2, (element){101}); print_heap(&heap2);
    
    printf("===== 반환 단계 =====\n");
    temp = delete_max_heap(&heap2); printf("반환된 값은 %d\n", temp.key); print_heap(&heap2);
    temp = delete_max_heap(&heap2); printf("반환된 값은 %d\n", temp.key); print_heap(&heap2);
    temp = delete_max_heap(&heap2); printf("반환된 값은 %d\n", temp.key); print_heap(&heap2);
    temp = delete_max_heap(&heap2); printf("반환된 값은 %d\n", temp.key); print_heap(&heap2);
    temp = delete_max_heap(&heap2); printf("반환된 값은 %d\n", temp.key); print_heap(&heap2);
}