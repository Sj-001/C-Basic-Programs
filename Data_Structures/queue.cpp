#include <bits/stdc++.h>
using namespace std;
class Queue {
public:
    int front, rear , size;
    unsigned capacity;
    int* array;
};


Queue* createQueue(unsigned capacity)
{
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;


    queue->rear = capacity - 1;
    queue->array = new int[(queue->capacity * sizeof(int))];
    return queue;
}

int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}


int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}


void insert(Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " insert to queue\n";
}


int delet(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}


int front(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}


int main()
{
    Queue* queue = createQueue(1000);

    insert(queue, 10);
    insert(queue, 20);
    insert(queue, 30);
    insert(queue, 40);

    cout << delet(queue)
	     << " delete from queue\n";

    cout << "Front item is "
         << front(queue) << endl;
    cout << "Rear item is "
         << rear(queue) << endl;

    return 0;
}
