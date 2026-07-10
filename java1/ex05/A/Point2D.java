

class Point2D{
    double x,y;

    void setX(double point_x) { x = point_x; }
    void setY(double point_y) { y = point_y; }

    void add(Point2D vec){
	x += vec.x;
	y += vec.y;
    }

    void scale(int n){
	x *= n;
	y *= n;
    }

    double length() { return Math.sqrt(x*x + y*y); }

    double dotProduct(Point2D vec) { return x*vec.x + y*vec.y; }

    double crossProduct(Point2D vec) { return x*vec.y - y*vec.x; }

    double distance(Point2D other) { return Math.sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y)); }

    @Override
    public String toString(){ return "( " + x + ", " + y + ")";}

    
}
