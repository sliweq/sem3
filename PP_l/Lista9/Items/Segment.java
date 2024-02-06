package Items;

import java.awt.Graphics;

public class Segment extends Primitive{
    private Point startPoint;
    private Point endPoint;

    public Segment(Point startPoint, Point endPoint){
        super();
        int minX = Math.min(startPoint.getX(), endPoint.getX());
        int minY = Math.min(startPoint.getY(), endPoint.getY());
        point = new Point(minX, minY);
        this.startPoint = startPoint;
        this.endPoint = endPoint;
    }

    public Point getStartPoint() {
        return this.startPoint;
    }

    public void setStartPoint(Point startPoint) {
        this.startPoint = startPoint;
    }

    public Point getEndPoint() {
        return this.endPoint;
    }

    public void setEndPoint(Point endPoint) {
        this.endPoint = endPoint;
    }
    
    public int getLength(){
        return (int) Math.sqrt(Math.pow(endPoint.getX() - startPoint.getX(), 2) + Math.pow(endPoint.getY() - startPoint.getY(), 2));
    }
    @Override
    public void draw(Graphics g){
        g.drawLine(startPoint.getX(), startPoint.getY(), endPoint.getX(), endPoint.getY());
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
        this.startPoint.translate(point_translate);
        this.endPoint.translate(point_translate);
        this.point.translate(point_translate);
    }

    @Override
    public Point[] getBoundingBox() {
        int minX = Math.min(startPoint.getX(), endPoint.getX());
        int minY = Math.min(startPoint.getY(), endPoint.getY());
        int maxX = Math.max(startPoint.getX(), endPoint.getX());
        int maxY = Math.max(startPoint.getY(), endPoint.getY());
        Point p2 = new Point(minX, maxY);
        Point p3 = new Point(maxX, maxY);
        Point p4 = new Point(maxX, minY);
        return new Point[] {point, p2, p3, p4};
    }

}
