//Base code from: https://algorithmtutor.com/Data-Structures/Tree/Priority-Queues/
//Refractored for dynamic sizing.

// C implementation of a max priority queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE __INT32_MAX__

struct binaryheap
{
    int* index0;
    size_t size;
    int lastelement;
};
//Allocates space for heap. Returns EXIT_SUCCESS if the operation was successful. EXIT_FAILURE otherwise
int create_heap(struct binaryheap* heap){
    //if the reference is empty do nothing
    if(heap==NULL) return EXIT_FAILURE;
    //if the size of heap is 0 get some space
    if(heap->size==0){
        heap->index0 = (int*)calloc(4,sizeof(int));
        heap->size=4;
        return EXIT_SUCCESS;
    }
    //if the next resize is bigger than max don't resize
    if(heap->size*2>=MAX_SIZE) 
    {
        printf("%s\n","The heap is full, cannot insert or enlarge");
        return EXIT_FAILURE;
    }
    //Allocate space
    int* tmp = (int*)calloc(heap->size*2,sizeof(int));
    //copy current data
    memcpy(tmp,heap->index0,heap->size*sizeof(int));
    //free space for current data
    free(heap->index0);
    heap->index0=tmp;
    heap->size*=2;
    return EXIT_SUCCESS;
}

// returns the index of the parent node
int parent(int i)
{
    return (i - 1) / 2;
}

// return the index of the left child 
int left_child(int i)
{
    return 2 * i + 1;
}

// return the index of the right child 
int right_child(int i)
{
    return 2 * i + 2;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// insert the item at the appropriate position
void enqueue(struct binaryheap* heap, int data){
    if(heap->lastelement>=heap->size){

        int res = create_heap(heap);
        if (res==EXIT_FAILURE) return;
    }
    // first insert the time at the last position of the array 
    // and move it up
    *(heap->index0+heap->lastelement)=data;
    heap->lastelement++;

    // move up until the heap property satisfies
    int i = heap->lastelement-1;
    while (i!=0 && *(heap->index0+parent(i))<*(heap->index0+i))
    {
        swap(heap->index0+parent(i),heap->index0+i);
        i = parent(i);
    }
}

// moves the item at position i of array a
// into its appropriate position
void max_heapify(struct binaryheap* heap,int i){
    // find left child node
    int left = left_child(i);
    // find right child node
    int right = right_child(i);
    // find the largest among 3 nodes
    int largest = i;
    // check if the left node is larger than the current node
    if (left <= heap->lastelement && *(heap->index0+left)>*(heap->index0+largest)){
        largest=left;
    }
    // check if the right node is larger than the current node
    if (right <= heap->lastelement && *(heap->index0+right)>*(heap->index0+largest)){
        largest=right;
    }
    // swap the largest node with the current node 
    // and repeat this process until the current node is larger than 
    // the right and the left node
    if (largest!=i){
        swap(heap->index0+i,heap->index0+largest);
        max_heapify(heap,largest);
    }
}
// returns the  maximum item of the heap
int get_max(struct binaryheap* heap)
{
    return *(heap->index0);
}

// deletes the max item and return
int dequeue(struct binaryheap* heap){
    int max_item=*(heap->index0);
    // replace the first item with the last item
    *(heap->index0)=*(heap->index0+heap->lastelement-1);
    heap->lastelement-=1;
    // maintain the heap property by heapifying the 
    // first item
    max_heapify(heap,0);
    return max_item;
}
// prints the heap
void print_heap(struct binaryheap* heap)
{
    int i;
    for (i = 0; i < heap->lastelement; i++)
    {
        printf("%d: %d\n",i, *(heap->index0+i));
    }
    printf("\n");
}


int main()
{
    struct binaryheap heap;
    heap.index0=NULL;
    heap.lastelement=0;
    heap.size=0;
    srand(time(NULL));
    int t[30];
    for (size_t i = 0; i < 30; i++)
    {
        t[i] = rand()%__INT16_MAX__;
    }

    for (size_t i = 0; i < 30; i++)
    {
        enqueue(&heap, t[i]);
    }
    int i=0;
    while (heap.lastelement>0)
    {
        printf("%d: %d\n",i++,dequeue(&heap));
    }
    
    return EXIT_SUCCESS;
}
