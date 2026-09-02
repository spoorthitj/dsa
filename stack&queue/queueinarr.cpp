class ArrayQueue {
public:
    int arr[100];
    int front, rear;

    ArrayQueue() {
        front = 0;
        rear = -1;
    }

    void push(int x) {
        arr[++rear] = x;
    }

    int pop() {
        return arr[front++];
    }

    int peek() {
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};