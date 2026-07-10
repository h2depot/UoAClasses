class Quadrangle extends Shape{
    protected Point[] P;

    public Quadrangle(Point p1, Point p2, Point p3, Point p4) {
	P = new Point[4];
	P[0] = new Point(p1.getX(), p1.getY());
	P[1] = new Point(p2.getX(), p2.getY());
	P[2] = new Point(p3.getX(), p3.getY());
	P[3] = new Point(p4.getX(), p4.getY());
    }

    public void print(){
	super.print();
	System.out.println("(" + P[0].getX() + ", " + P[0].getY() + ")" + "-" + "(" + P[1].getX() + ", " + P[1].getY() + ")" + "-" + "(" + P[2].getX() + ", " + P[2].getY() + ")" + "-" + "(" + P[3].getX() + ", " + P[3].getY() + ")");
    }

    public void move(int dx, int dy){
	for( int i = 0; i < 4; i++){ P[i].move(dx, dy); }
    }
}
