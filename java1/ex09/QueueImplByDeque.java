class QueueImplByDeque implements Queue{
  private Deque deque;

  QueueImplByDeque(){
    this.deque = new DequeImplByDLL();
  }

  public void enqueue(int key){ deque.insertFront(key); }
  public int dequeue(){ 
    int tmp = this.front();
    deque.removeBack(); 
    return tmp;
  }
  public int front(){ return deque.back(); }
  public int size(){ return deque.size(); }
  public boolean empty(){ return deque.empty(); }
}
