class MergeSort implements Strategy{
    public void sort(int[] data){
        mergeSort(data, 0, data.length - 1);
    }

    public void mergeSort(int[] data, int left, int right){
        
    	if (left < right) {
            int mid = (left + right) / 2;
	        mergeSort(data, left, mid);
	        mergeSort(data, mid + 1, right);
	        merge(data, left, mid, right);
	}
    }

    public void merge(int[] data, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int[] L = new int[n1+1];
	int[] R = new int[n2 + 1];

	for(int i = 0; i < n1; i++)L[i] = data[left + i];
	for(int i = 0; i < n2; i++)R[i] = data[mid + i + 1];
	L[n1] = Integer.MAX_VALUE;
	R[n2] = Integer.MAX_VALUE;

        int i = 0;
	int j = 0;
	for(int k = left; k <= right; k++){
	    if ( L[i] <= R[j] ) {
		    data[k] = L[i];
		   i++;
	    } else {
            data[k] = R[j];
		    j++;
	    }
	}
    }
}
