class Stack implements Container{
    private int[] stack;
    private int size, max_len;

    Stack(int max_len){
    this.max_len = max_len;
    this.stack = new int[max_len];
    this.size = 0;
    }

    public int pop() { return stack[--size]; }
    public void push(int x) { stack[size++] = x; }
    public boolean isEmpty() { return size == 0; }
    public boolean isFull() { return size == max_len; }
    public int size() { return this.size; }
}