class MovingPoint2D extends Point2D{
    double vx, vy;

    public MovingPoint2D(double x, double y, double vx, double vy){
        setX(x);
	setY(y);
	setVelocity(vx, vy);
    }

    void setVelocity(double a, double b) {
	vx = a;
	vy = b;
    }

    void move(){
	x += vx;
	y += vy;
    }
}
