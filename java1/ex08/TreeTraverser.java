class TreeTraverser{
    private int N = 0;

    public TreeTraverser(int N){
	this.N = N;
    }

    public void traverse(OpenList list){
	list.push(0);

	while(!list.isEmpty()){
	    int u = list.pop();
	    if ( u >= N ) continue;
	    System.out.print(u + " ");
	    list.push(2*u + 1);
	    list.push(2*u + 2);
	}
	System.out.println();
    }
}
