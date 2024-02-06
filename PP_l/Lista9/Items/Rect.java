package Items;

import java.awt.Graphics;

public class Rect extends Shape{
    private int width;
    private int height; 
    public Rect(Point point, int width, int height, boolean filled){
        super(filled);
        setPoint(point);
        this.width = width;
        this.height = height;
    }

    @Override
    public Point[] getBoundingBox(){
        Point[] boundingBox = {
        new Point(point.getX(), point.getY()),
        new Point(point.getX() + width, point.getY()),
        new Point(point.getX(), point.getY() + height),
        new Point(point.getX() + width, point.getY() + height)};
        return boundingBox;
    }

    public int getWidth(){
        return width;
    }
    public int getHeight(){
        return height;
    }
    public void setWidth(int width){
        this.width = width;
    }
    public void setHeight(int height){
        this.height = height;
    }

    public void draw(Graphics g){
        System.out.println("Drawing a rectangle at (" + point.getX() + ", " + point.getY() + ")");
        if(this.filled){
            g.fillRect(this.point.getX(), this.point.getY(), width, height);
        }
        else{
            g.drawRect(this.point.getX(), this.point.getY(), width, height);
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
    public void translate(Point point) {
        this.point.translate(point);
    } 
}
