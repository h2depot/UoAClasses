package impl;
import template.BinaryTreeTraverser;
import template.BinaryTreeNode;

class PreOrderTraversal extends BinaryTreeTraverser{
  public void initialize(){
    System.out.println("Begin Pre-order Traversal");
  }

  public void performPre(BinaryTreeNode u){
    System.out.print(" " + u.getKey());
  }

  public void finalize(){
    System.out.println();
    System.out.println("End Pre-order Traversal");
  }
}