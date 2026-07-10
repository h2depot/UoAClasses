class SortingArraysApplication{
    public static void main(String[] args){
	new SortingArraysApplication().run();
    }

    void run(){
	int [][] arrays = {
	    {3, 2, 1},
	    {9, 7, 10, 4, 8, 2, 5, 3, 1, 6},
	    {7, 2, 3, 2, 2, 1, 1, 1},
	    {2, 1},
	    {100},
	    {888888888, -888888888}
	};

	for (int t = 0; t < arrays.length; t++) sort(arrays[t]);

	for (int i = 0; i < arrays.length; i++){
	    for (int j = 0; j < arrays[i].length; j++){
		System.out.print(" " + arrays[i][j]);
	    }
	    System.out.println();
	}
    }

    void sort(int[] arrays){
	for(int a = 0; a < arrays.length-1; a++){
	    for(int b = 0; b < arrays.length-1; b++){
		if(arrays[b] > arrays[b+1]){
		    int tmp = arrays[b];
		    arrays[b] = arrays[b+1];
		    arrays[b+1] = tmp;
		}
	    }
	}
    }
}
