class Queue implements OpenList{
    private int[] queue = new int[100];
    private int head = 0,tail = 0;

    public void push( int n ) { queue[tail++] = n; }
    public int pop(){ return queue[head++]; }
    public boolean isEmpty(){ return head == tail; }
}
    
