package Items;
import java.awt.Graphics;

public abstract class Item {

    protected Point point;

    public Item(){
    }

    public abstract Point getPoint();

    public abstract void setPoint(Point point);

    public abstract void translate(Point point_translate);

    public abstract Point[] getBoundingBox();

    public abstract void draw(Graphics g);
}
