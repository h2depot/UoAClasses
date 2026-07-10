class Point implements Relatable{
  private  int x,y;
    
  Point(int x, int y){
    this.x = x;
    this.y = y;
  }
  public int getX(){ return this.x; }
  public int getY(){ return this.y; }

  public boolean isSmallerThan(Relatable other){
    Point p = (Point)other;

    if(this.getX() != p.getX()){
	return this.getX() < p.getX();
    }else{
	return this.getY() < p.getY();
    }
  }

  public void print(){ System.out.println("(" + this.x + ", " + this.y + ")"); }
}
