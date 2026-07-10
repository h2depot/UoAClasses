package impl;
import template.BinaryTreeTraverser;
import template.BinaryTreeNode;

class InOrderTraversal extends BinaryTreeTraverser{
  public void initialize(){
    System.out.println("Begin In-order Traversal");
  }

  public void performIn(BinaryTreeNode u){
    System.out.print(" " + u.getKey());
  }

  public void finalize(){
    System.out.println();
    System.out.println("End In-order Traversal");
  }
}