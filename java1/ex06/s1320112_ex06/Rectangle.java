class Rectangle extends Parallelogram{

    public Rectangle(Point p1, Point p2){
	    super(p1, p2, p2.getX() - p1.getX());
    }
}
