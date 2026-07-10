public class StackUnderflowException extends RuntimeException{
    public StackUnderflowException(){
	super("Underflow. There is no element in the stack.");
    }
}
