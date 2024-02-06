package Items;

import java.awt.Graphics;

public class Circle extends Shape{ 
    private int radius;
    public Circle(Point point,int radius, boolean filled){
        super(filled);
        setPoint(point);
        this.radius = radius;
    }

    @Override
    public Point[] getBoundingBox(){
        Point[] boundingBox = {
        new Point(getPoint().getX(), getPoint().getY()),
        new Point(getPoint().getX() + 2*radius, getPoint().getY()),
        new Point(getPoint().getX(), getPoint().getY() + 2*radius),
        new Point(getPoint().getX() + 2*radius, getPoint().getY() + 2*radius)};
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
        //System.out.println("Drawing a circle at (" + getPoint().getX() + ", " + getPoint().getY() + ")");
        if(this.filled){
            g.fillOval(getPoint().getX(), getPoint().getY(), 2 * radius, 2 * radius);
        }
        else{
            g.drawOval(getPoint().getX(), getPoint().getY(), 2 * radius, 2 * radius);
        }
    }
}
