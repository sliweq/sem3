package Items;

import java.awt.Graphics;
import java.util.ArrayList;

public class ComplexItem extends Item {
    private ArrayList<Item> items;

    public ComplexItem(){
        super();
        items = new ArrayList<Item>();
    }
    
    public void addItem(Item item){
        if(items.size() == 0){
            setPoint(new Point(item.getPoint().getX(), item.getPoint().getY()));
        }else{
            if(item.getPoint().getX() < getPoint().getX()){
                setPoint(new Point(item.getPoint().getX(), getPoint().getY()));
            }
            if(item.getPoint().getY() < getPoint().getY()){
                setPoint(new Point(getPoint().getX(), item.getPoint().getY()));
            }
        }
        items.add(item);
        
    }
    public ArrayList<Item> getItems(){
        return items;
    }

    @Override
    public void draw(Graphics g){
        for(Item item : items){
            item.draw(g);
        }
    }

    public void translate(Point point_translate){
        for(Item item : items){
            item.translate(point_translate);
        }
        translate(point_translate);
    }

    public Point[] getBoundingBox(){
        int minX = this.items.get(0).getBoundingBox()[0].getX();
        int minY = this.items.get(0).getBoundingBox()[0].getY();
        int maxX = this.items.get(0).getBoundingBox()[0].getX();
        int maxY = this.items.get(0).getBoundingBox()[0].getY();
        for (Item child : this.items) {
            Point[] boundingBox = child.getBoundingBox();
            for (Point point : boundingBox) {
                minX = Math.min(minX, point.getX());
                minY = Math.min(minY, point.getY());
                maxX = Math.max(maxX, point.getX());
                maxY = Math.max(maxY, point.getY());
            }
        }
        Point p1 = new Point(minX, minY);
        Point p2 = new Point(minX, maxY);
        Point p4 = new Point(maxX, maxY);
        Point p3 = new Point(maxX, minY);
        return new Point[] {p1, p2, p3, p4};
    }
}
