import java.util.Scanner;

class ByaccoGas{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);

	int num_lane = sc.nextInt();
	int num_act = sc.nextInt();
    Queue[] lane_array = new Queue[num_lane];
    for(int i = 0; i < num_lane; i++){
	    lane_array[i] = new Queue();
	}
	int min=0,min_index=0;

	for( int i = 0; i < num_act; i++){
	    int judge = sc.nextInt();
	    if(judge == 0){
		int key_lane = sc.nextInt();
		System.out.println(lane_array[key_lane-1].Dequeue());
	    }else{
		int key_car = sc.nextInt();
		for (int j = 0; j < num_lane; j++){
			int size = lane_array[j].tail-lane_array[j].head;
		    if( j == 0){
			    min = size;
				min_index = 0;
		    }else{
			    if(min > size){
                    min = size;
			        min_index = j;
			    }
		    }
		}
		//System.out.println(min_index);
		lane_array[min_index].Enqueue(key_car);
	    }
	}
    }
}
