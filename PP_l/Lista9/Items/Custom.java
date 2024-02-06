package Items;

import java.awt.Graphics;
import java.util.ArrayList;

public class Custom extends Shape {
    ArrayList<Point> points;
    int radius = 50;

    public Custom(boolean filled,Point point, int sides) {
        super(filled);
        if(sides < 5){
            if(sides == 3 || sides == 4){
                System.out.println("Srsly, you have a rect and a triangle class for that");    
            }
            else{

                System.out.println("Sides must be greater than 4, correcting to 5");
            }

            sides = 5;
        }
        this.point = point;
        generatePoints(sides);
        this.point = getBoundingBox()[0];
        
    }
    private int calculateSideLength(int sides){
        return (int) (2*radius*Math.sin(Math.PI/sides));
    }

    private void generatePoints(int sides){
        points = new ArrayList<Point>();
        
        int sideLength = calculateSideLength(sides);

        points.add(new Point(point.getX(),point.getY()));

        for(int i = 1; i < sides; i++){
            double angle = i * (2 * Math.PI / sides);
            int x = points.get(i-1).getX() + ((int) (sideLength* Math.sin(angle)));
            int y = points.get(i-1).getY() + ((int) (sideLength* Math.cos(angle)));
            points.add(new Point(x,y));
        }
    }

    public void translate(Point point) {
        this.point.translate(point);
        for (Point p : this.points) {
            p.translate(point);
        }
    }

    public void draw(Graphics g) {
        int[] xPoints = new int[points.size()];
        int[] yPoints = new int[points.size()];
        for (int i = 0; i < points.size(); i++) {
            System.out.println("Drawing point " + i + " at " + points.get(i).getX() + " " + this.points.get(i).getY());
            xPoints[i] = points.get(i).getX();
            yPoints[i] = points.get(i).getY();
        }
        if (this.filled) {
            g.fillPolygon(xPoints, yPoints, points.size());
        } else {
            g.drawPolygon(xPoints, yPoints, points.size());
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
    public Point[] getBoundingBox() {
        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE;
        int maxY = Integer.MIN_VALUE;
        for(Point p : points){
            minX = Math.min(minX,p.getX());
            maxX = Math.max(maxX,p.getX());
            minY = Math.min(minY,p.getY());
            maxY = Math.max(maxY,p.getY());
        }
        return new Point[]{new Point(minX,minY),new Point(maxX,minY),new Point(maxX,maxY),new Point(minX,maxY)};
    }
    
}

