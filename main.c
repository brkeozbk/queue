#include "queue.h"
#include "stack.h"

int main() {
    queue first = init_queue(10);

    int i = 10, temp;
    while(i--){
        scanf("%d", &temp);
        enqueue(&first, temp);
    }
    displayQueue(first);

    stack second;
    second.top = NULL;

    largerToStack(first, &second);
    displayStack(second);

    int * arr = toArray(second);

    for(i = 0;i<second.size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}