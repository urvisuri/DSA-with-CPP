class MinStack {
    private:
        stack<int> mainStack;
        stack<int> minStack;
        
    public:
        MinStack() {
            // Constructor initializes the stacks
        }
        
        void push(int val) {
            mainStack.push(val);
            // Only push to minStack if it's the smallest so far
            if (minStack.empty() || val <= minStack.top()) {
                minStack.push(val);
            }
        }
        
        void pop() {
            // If the top of both stacks is the same, pop both
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
        
        int top() {
            return mainStack.top();
        }
        
        int getMin() {
            return minStack.top();
        }
    };
    
