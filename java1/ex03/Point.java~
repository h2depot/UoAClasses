class Point{
    private int point_x,point_y;

    Point(){
	point_x = 0;
	point_y = 0;
    }

    void setX(int x) { point_x = x; }
    void setY(int y) { point_y = y; }

    int getX() { return point_x; }
    int getY() { return point_y; }

    void move(int dx, int dy){
        if(point_x + dx > 100 || point_x + dx < -100 || point_y + dy > 100 || point_y + dy < -100)return;
	point_x += dx;
	point_y += dy;
    }
}
