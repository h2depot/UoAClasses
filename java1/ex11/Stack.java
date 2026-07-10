class Stack implements OpenList{
    private int[] stack;
    private int size = 0;

    Stack(int n){
       stack = new int[n];
    }
    
    public void push( int n ) {
	if(size == stack.length)throw new StackOverflowException(n);
	stack[size++] = n;
    }
    public int pop() {
	if(size == 0)throw new StackUnderflowException();
	return stack[--size];
    }
    public boolean isEmpty() { return size == 0; }
}
