class Point{
  private  int x,y;
    
  Point(int x, int y){
    this.x = x;
    this.y = y;
  }
  public int getX(){ return this.x; }
  public int getY(){ return this.y; }

  public void print(){ System.out.println("(" + this.x + ", " + this.y + ")"); }
}
