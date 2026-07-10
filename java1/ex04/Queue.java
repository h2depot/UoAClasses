class Queue{
    int[] array = new int[9999];
    public int head, tail;

    Queue(){
	head = 0;
	tail = 0;
    }

    void Enqueue(int key){
	array[tail++] = key;
    }

    int Dequeue(){
	if(head == tail){
	    return -1;
	}
	int retval = array[head++];
	return retval;
    }
}
