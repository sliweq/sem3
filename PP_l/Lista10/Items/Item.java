package Items;
import java.awt.Graphics;

public abstract class Item {

    private Point point;

    public Item(){
    }

    public Point getPoint(){ return point; }

    public void setPoint(Point point){  this.point = point; }

    public void translate(Point point_translate){   point.translate(point_translate);   }

    public abstract Point[] getBoundingBox();

    public abstract void draw(Graphics g);
}
