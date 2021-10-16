#include <iostream>
 
using namespace std;
int queue[10];
int size = 0, front = 0, rear = -1;
 
void enqueue(int data) {
    if (size >= 10 ) {
        cout << "queue overflow";
    }
    else {
        cout << "enqueue : " << data;
        rear++;
        if (rear >= 10)
            rear %= 10;
        size++;
        queue[rear] = data;
    }
    cout << endl;
}
 
void dequeue() {
    if (size <= 0) {
        cout << "queue underflow";
    }
    else {
        cout << "dequeue : " << queue[front];
        front++;
        if (front >= 10)
            front %= 10;
        size--;
    }
    cout << endl;
}
 

 
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    dequeue();
    enqueue(11);
    dequeue();
 
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    
    
 

 
    return 0;
}
