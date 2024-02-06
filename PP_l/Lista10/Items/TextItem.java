package Items;
import java.awt.Graphics;
import java.awt.geom.Rectangle2D;

public class TextItem extends Item {
    protected String text;
    protected Point[] bound_points;

    public TextItem(Point point, String text){
        super();
        setPoint(point);
        this.text = text;
        bound_points = new Point[] {new Point(point.getX(), point.getY()),new Point(point.getX(), point.getY()),new Point(point.getX(), point.getY()),new Point(point.getX(), point.getY())};

    }
    public String getText(){
        return text;
    }
    public void setText(String text){
        this.text = text;
    }
    @Override
    public void draw(Graphics g){
        g.drawString(text, getPoint().getX(), getPoint().getY());
        Rectangle2D bounds = g.getFontMetrics().getStringBounds(this.text, g);
    
        this.bound_points = new Point[] {
            new Point(getPoint().getX(), getPoint().getY() - ((int) bounds.getHeight())),
            new Point(getPoint().getX(), getPoint().getY()),
            new Point(getPoint().getX() + ((int) bounds.getWidth()), getPoint().getY()- ((int) bounds.getHeight())),
            new Point(getPoint().getX() + ((int) bounds.getWidth()), getPoint().getY())
        };
    }
    @Override
    public Point[] getBoundingBox(){
        return bound_points;
    }
}
