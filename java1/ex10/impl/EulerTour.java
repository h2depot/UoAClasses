package impl;
import template.BinaryTreeTraverser;
import template.BinaryTreeNode;

class EulerTour extends BinaryTreeTraverser{
  public void initialize(){
    System.out.println("Begin Euler Tour");
  }

  public void performPre(BinaryTreeNode u){
    System.out.print(" " + u.getKey());
  }


  public void performPost(BinaryTreeNode u){
    System.out.print(" " + u.getKey());
  }

  public void finalize(){
    System.out.println();
    System.out.println("End Euler Tour");
  }
}