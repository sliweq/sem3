package Items;
import java.awt.Graphics;
import java.awt.geom.Rectangle2D;

public class TextItem extends Item {
    protected String text;
    protected Point[] bound_points;

    public TextItem(Point point, String text){
        super();
        this.point = point;
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
        g.drawString(text, point.getX(), point.getY());
        Rectangle2D bounds = g.getFontMetrics().getStringBounds(this.text, g);
    
        this.bound_points = new Point[] {
            new Point(this.point.getX(), this.point.getY() - ((int) bounds.getHeight())),
            new Point(this.point.getX(), this.point.getY()),
            new Point(this.point.getX() + ((int) bounds.getWidth()), this.point.getY()),
            new Point(this.point.getX() + ((int) bounds.getWidth()), this.point.getY()- ((int) bounds.getHeight()))
        };
    }
    @Override
    public void translate(Point point_translate){
        point.translate(point_translate);
    }
    @Override
    public Point[] getBoundingBox(){
        return bound_points;
    }
    @Override
    public Point getPoint() {
        return point;
    }
    @Override
    public void setPoint(Point point) {
        this.point = point;
    }
}
