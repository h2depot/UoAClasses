class Stack implements OpenList{
    private int[] stack = new int[100];
    private int size = 0;
    
    public void push( int n ) { stack[size++] = n; }
    public int pop() { return stack[--size]; }
    public boolean isEmpty() { return size == 0; }
}
