public class StackOverflowException extends RuntimeException{
    public StackOverflowException(int n){
	super("Overflow. " + n + " can not be pushed.");
    }
}
