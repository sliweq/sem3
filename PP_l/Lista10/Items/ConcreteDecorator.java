package Items;

import java.awt.BasicStroke;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

public class ConcreteDecorator extends BaseDecorator{

    public ConcreteDecorator(Item item) {
        super(item);
        
    }
    @Override
    public void draw(Graphics g) {
        super.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        Point[] boundingBox = getBoundingBox();
        Rectangle rectangle = new Rectangle(boundingBox[0].getX(), 
        boundingBox[0].getY(), 
        boundingBox[3].getX() - boundingBox[0].getX(), 
        boundingBox[3].getY() - boundingBox[0].getY());

        g2d.setStroke(new BasicStroke(4.0f, BasicStroke.CAP_SQUARE, BasicStroke.JOIN_MITER,10f, new float[] {16.0f,20.0f},  0.0f ));
        g2d.draw(rectangle);
        g2d.setStroke(new BasicStroke(1));
    }
}
