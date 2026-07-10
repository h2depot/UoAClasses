class Square extends Rectangle{

    public Square(Point p, int len){
        super(p, new Point(p.getX() + len, p.getY() + len));
    }
}
