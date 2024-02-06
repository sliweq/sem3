package Items;

import java.awt.Graphics;

public class Circle extends Shape{ 
    private int radius;
    public Circle(Point point,int radius, boolean filled){
        super(filled);
        this.point = point;
        this.radius = radius;
    }

    @Override
    public Point[] getBoundingBox(){
        Point[] boundingBox = {
        new Point(point.getX(), point.getY()),
        new Point(point.getX() + 2*radius, point.getY()),
        new Point(point.getX(), point.getY() + 2*radius),
        new Point(point.getX() + 2*radius, point.getY() + 2*radius)};
        return boundingBox;
    }

    public int getRadius() {
        return this.radius;
    }

    public void setRadius(int radius) {
        this.radius = radius;
    }

    @Override
    public void draw(Graphics g){
        System.out.println("Drawing a circle at (" + point.getX() + ", " + point.getY() + ")");
        if(this.filled){
            g.fillOval(this.point.getX(), this.point.getY(), 2 * radius, 2 * radius);
        }
        else{
            g.drawOval(this.point.getX(), this.point.getY(), 2 * radius, 2 * radius);
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
        this.point.translate(point_translate);
    }

}
