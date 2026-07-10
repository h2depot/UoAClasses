package impl;
import template.BinaryTreeTraverser;
import template.BinaryTreeNode;

class PostOrderTraversal extends BinaryTreeTraverser{
  public void initialize(){
    System.out.println("Begin Post-order Traversal");
  }

  public void performPost(BinaryTreeNode u){
    System.out.print(" " + u.getKey());
  }

  public void finalize(){
    System.out.println();
    System.out.println("End Post-order Traversal");
  }
}