public class AddMapManipulation extends ArrayManipulation{
    private int n;

    public AddMapManipulation(ArrayOperation arrayOperation, int n){
        super(arrayOperation);
        this.n = n;
    }
    public int[] operate(int[] array){
        int[] result = arrayOperation.operate(array);
        for (int i = 0; i < array.length; i++){
          result[i] += n;
        }

        return result;
    }
}