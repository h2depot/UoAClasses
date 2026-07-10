class MovingPoint2D{
    double vx, vy;
    public Point2D point;


    public MovingPoint2D(double x, double y, double vx, double vy){
	point = new Point2D();
	point.setX(x);
	point.setY(y);
	setVelocity(vx, vy);
    }

    void setVelocity(double a, double b) {
	vx = a;
	vy = b;
    }

    void move(){
	point.x += vx;
	point.y += vy;
    }

    public double distance(MovingPoint2D other){ return this.point.distance(other.point); }
    public String toString(){ return this.point.toString(); }
}
