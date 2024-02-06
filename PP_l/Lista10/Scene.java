import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import javax.swing.*;
import Items.BaseDecorator;
import Items.ConcreteDecorator;
import Items.Item;
import Items.Point;
import java.util.ArrayList; 
import Items.Single;

public class Scene extends JPanel implements MouseListener, MouseMotionListener{
    ArrayList<Item> shapes; 
    private int mouseX = 0 ;
    private int mouseY = 0;

    public Scene() {
        addMouseListener(this);
        addMouseMotionListener(this);
        shapes = new ArrayList<Item>();
    }

    public void addItems(Item item){
        if(item instanceof Single){
            for(int i = 0; i < shapes.size(); i++){
                if(shapes.get(i) instanceof Single){
                    shapes.remove(i);
                }
            }
        }
        shapes.add(item);
    }

    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for(int i = 0; i < shapes.size(); i++){
            shapes.get(i).draw(g);
            if(detectMouseCollision(shapes.get(i)) && !(shapes.get(i) instanceof BaseDecorator)){
                shapes.set(i, new ConcreteDecorator(shapes.get(i)));
            }else if(!detectMouseCollision(shapes.get(i)) && shapes.get(i) instanceof BaseDecorator){
                shapes.set(i, ((BaseDecorator) shapes.get(i)).getItem());
            }
        }
    }

    private boolean detectMouseCollision(Item item){
        Point[] boundingBox = item.getBoundingBox();
        if(mouseX >= boundingBox[0].getX() && mouseX <= boundingBox[3].getX() && mouseY >= boundingBox[0].getY() && mouseY <= boundingBox[3].getY()){
            return true;
        }
        return false;
    }

    
    @Override
    public void mouseMoved(MouseEvent arg0) {
        //System.out.println("mouseMoved");
        mouseX = arg0.getX();
        mouseY = arg0.getY();   
    }
    
    @Override
    public void mouseClicked(MouseEvent arg0) {
        //System.out.println("mouseClicked");
        mouseX = arg0.getX();
        mouseY = arg0.getY();   
        this.repaint();
    }

    @Override
    public void mousePressed(MouseEvent arg0) {
        //System.out.println("mousePressed");
        mouseX = arg0.getX();
        mouseY = arg0.getY();   
        this.repaint();
    }

    @Override
    public void mouseReleased(MouseEvent arg0) {
        //System.out.println("mouseReleased");
        mouseX = arg0.getX();
        mouseY = arg0.getY();   
        this.repaint();
    }
    
    @Override
    public void mouseDragged(MouseEvent arg0) {
        //System.out.println("mouseDragged");
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        //System.out.println("mouseEntered");
    }

    @Override
    public void mouseExited(MouseEvent e) {
        //System.out.println("mouseExited");
    }

}
