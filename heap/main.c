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

void insert_max_heap_ver1(HeapType* heap, element key) 
{ // 시도 실패1 : 신규 노드를 실제로 넣지 말고 마지막에 들어간다고 가정하고 그 뒤 자리를 정한 뒤 마지막에 직접 넣어보도록 바꾸자
    int index;
    if(heap->heap_size == MAX_HEAP_SIZE) {
        printf("HEAP_IS_FULL!\n");
        return;
    }
    
    heap->heap[++heap->heap_size] = key;
    
    index = heap->heap_size;
    while(index != 1 && (key.key > heap->heap[index / 2].key)) {
        if(key.key > heap->heap[index / 2].key) {
            element temp = heap->heap[index / 2]; // 부모 노드 값 포인터에 임시 저장 ( 동적 생성 안 하게 )
            heap->heap[index / 2] = key;
            heap->heap[index] = temp;
            
            index = index / 2; // 부모 노드로 이동
        } // 만약 현재 노드가 부모 노드보다 키 값이 크면 교환한다.
    }
} // 최대 히프에 새로운 요소를 삽입하는 함수

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
    HeapType heap1;
    heap1.heap_size = 0;
    
    printf("===== insert 1차 시도 =====");
    insert_max_heap_ver1(&heap1, (element){10}); print_heap(&heap1);
    insert_max_heap_ver1(&heap1, (element){5}); print_heap(&heap1);
    insert_max_heap_ver1(&heap1, (element){6}); print_heap(&heap1);
    insert_max_heap_ver1(&heap1, (element){100}); print_heap(&heap1);
    insert_max_heap_ver1(&heap1, (element){101}); print_heap(&heap1);
    
    HeapType heap2;
    heap2.heap_size = 0;
    
    printf("===== insert 2차 시도 =====");
    insert_max_heap_ver2(&heap2, (element){10}); print_heap(&heap2);
    insert_max_heap_ver2(&heap2, (element){5}); print_heap(&heap2);
    insert_max_heap_ver2(&heap2, (element){6}); print_heap(&heap2);
    insert_max_heap_ver2(&heap2, (element){100}); print_heap(&heap2);
    insert_max_heap_ver2(&heap2, (element){101}); print_heap(&heap2);
}