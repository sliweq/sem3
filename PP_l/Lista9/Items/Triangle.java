package Items;

import java.awt.Graphics;

public class Triangle extends Shape {
    private Point p1;
    private Point p2;
    private Point p3;

    public Triangle(Point p1, Point p2, Point p3, boolean filled){
        super(filled);
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
        point = getBoundingBox()[0];
    }

    public Point getP1() {
        return this.p1;
    }

    public void setP1(Point p1) {
        this.p1 = p1;
    }

    public Point getP2() {
        return this.p2;
    }

    public void setP2(Point p2) {
        this.p2 = p2;
    }

    public Point getP3() {
        return this.p3;
    }

    public void setP3(Point p3) {
        this.p3 = p3;
    }

    public void draw(Graphics g){
        System.out.println("Drawing a triangle at (" + p1.getX() + ", " + p1.getY() + ")");
        if(this.filled){
            g.fillPolygon(new int[]{p1.getX(), p2.getX(), p3.getX()}, new int[]{p1.getY(), p2.getY(), p3.getY()}, 3);
        }
        else{
            g.drawPolygon(new int[]{p1.getX(), p2.getX(), p3.getX()}, new int[]{p1.getY(), p2.getY(), p3.getY()}, 3);
        }
    }

    @Override
    public Point getPoint() {
        return point;
    }

    @Override
    public void setPoint(Point point) {
        this.point = point;
    }

    @Override
    public void translate(Point point_translate) {
        point.translate(point_translate);
        p1.translate(point_translate);
        p2.translate(point_translate);
        p3.translate(point_translate);
    }

    @Override
    public Point[] getBoundingBox() {
        int minX = Math.min(p1.getX(), Math.min(p2.getX(), p3.getX()));
        int minY = Math.min(p1.getY(), Math.min(p2.getY(), p3.getY()));
        int maxX = Math.max(p1.getX(), Math.max(p2.getX(), p3.getX()));
        int maxY = Math.max(p1.getY(), Math.max(p2.getY(), p3.getY()));
        Point p1 = new Point(minX, minY);
        Point p2 = new Point(minX, maxY);
        Point p3 = new Point(maxX, maxY);
        Point p4 = new Point(maxX, minY);
        return new Point[] {p1, p2, p3, p4};
    } 
}