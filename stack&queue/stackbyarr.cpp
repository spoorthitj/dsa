class ArrayStack {
public:
    int arr[100];
    int topIndex;

    ArrayStack() {
        topIndex = -1;
    }

    void push(int x) {
        topIndex++;
        arr[topIndex] = x;
    }

    int pop() {
        if (topIndex == -1) {
            return -1;
        }

        return arr[topIndex--];
    }

    int top() {
        if (topIndex == -1) {
            return -1;
        }

        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};