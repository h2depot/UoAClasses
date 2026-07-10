class Point{
    private int point_x,point_y;
    static int X_MAX,Y_MAX,X_MIN,Y_MIN;

    Point(){
	point_x = 0;
	point_y = 0;
    }

    void setX(int x) { point_x = x; }
    void setY(int y) { point_y = y; }

    int getX() { return point_x; }
    int getY() { return point_y; }

    void move(int dx, int dy){
        if(point_x + dx > X_MAX || point_x + dx < X_MIN || point_y + dy > Y_MAX || point_y + dy < Y_MIN)return;
	point_x += dx;
	point_y += dy;
    }
}
