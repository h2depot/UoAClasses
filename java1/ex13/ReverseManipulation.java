import java.util.Arrays;

public class ReverseManipulation extends ArrayManipulation{

    public ReverseManipulation(ArrayOperation arrayOperation){
        super(arrayOperation);
    }

    public int[] operate(int[] array){
        int[] result_test = arrayOperation.operate(array);
        //System.out.println(Arrays.toString(array) + " this is test "); 
        //System.out.println(Arrays.toString(result_test) + " this is test "); 
        int[] result = new int[array.length];
        for(int i = 0; i < array.length; i++){
            result[result.length - i - 1] = result_test[i];
        }

        return result;
    }
}
