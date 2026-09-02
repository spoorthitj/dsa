class MyStack {
public:
    queue<int> que;

    MyStack() {
        
    }

    void push(int x) {
        
        // Step 1: Add the new element to the back
        que.push(x);

        // Step 2: Number of old elements in the queue
        int n = que.size() - 1;

        // Step 3: Move all old elements from front to back
        // This brings the newly added element to the front
        while (n--) {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
    }

    int pop() {
        
        // Since the stack top is always at the front,
        // save the front element
        int x = que.front();

        // Remove it from the queue
        que.pop();

        // Return the removed stack element
        return x;
    }

    int top() {
        
        // Front of the queue represents the top of the stack
        return que.front();
    }

    bool empty() {
        
        // Use the queue's built-in empty function
        return que.empty();
    }
};