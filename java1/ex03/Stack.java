class Stack{
    int[] stack = new int[100];
    int top = 0;

    int pop() { 
     --top;
     return stack[top];
     }
    void push(int x) { stack[top++] = x;}
}
