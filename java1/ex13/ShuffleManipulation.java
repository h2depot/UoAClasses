import java.util.Random;

class ShuffleManipulation extends ArrayManipulation{

    public ShuffleManipulation(ArrayOperation arrayOperation){
        super(arrayOperation);
    }

    public int[] operate(int[] array){
        int[] result = arrayOperation.operate(array);
        Random rnd = new Random();
        for (int i = array.length - 1; i > 0; i--){
            int index = rnd.nextInt(i+1);
            int temp = result[index];
            result[index] = result[i];
            result[i] = temp;
        }
        return result;
    }
}
