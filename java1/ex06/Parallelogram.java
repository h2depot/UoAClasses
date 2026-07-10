class Parallelogram extends Quadrangle{
    public Parallelogram(Point p1, Point p2, int len){
	    super(p1,new Point(p1.getX() + len, p1.getY()), p2, new Point(p2.getX() - len, p2.getY()));
    }
}
