class Rectangle implements Relatable{
    private int s,width,height;
    
    public Rectangle(Point p1, Point p2){
        width = p2.getX() - p1.getX();
	height = p2.getY() - p1.getY();
	s = width * height;
    }
    int getArea(){ return s; }
    
    public boolean isSmallerThan(Relatable other){
	Rectangle r = (Rectangle)other;
        return this.s < r.s;
    }
}
