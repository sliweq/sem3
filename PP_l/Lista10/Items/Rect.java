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
        new Point(getPoint().getX(), getPoint().getY()),
        new Point(getPoint().getX() + width, getPoint().getY()),
        new Point(getPoint().getX(), getPoint().getY() + height),
        new Point(getPoint().getX() + width, getPoint().getY() + height)};
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
        //System.out.println("Drawing a rectangle at (" + getPoint().getX() + ", " + getPoint().getY() + ")");
        if(this.filled){
            g.fillRect(getPoint().getX(), getPoint().getY(), width, height);
        }
        else{
            g.drawRect(getPoint().getX(), getPoint().getY(), width, height);
        }
    }
}
