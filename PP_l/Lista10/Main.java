import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JFrame;
import Items.Rect;
import Items.Segment;
import Items.TextItem;
import Items.Triangle;
import Items.Circle;
import Items.ComplexItem;
import Items.Custom;
import Items.Point;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Simple Shapes");
        
        frame.setSize(800, 800);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Scene gui = new Scene();
        gui.addItems(new Circle(new Point(300, 20), 100, true));
        gui.addItems(new Segment(new Point(0, 400), new Point(250, 250)));
        gui.addItems(new TextItem(new Point(500, 500), "Szczesliwego Nowego Roku xddd!"));
        gui.addItems(new Triangle(new Point(200, 420), new Point(300, 460), new Point(230, 520), true));

        ComplexItem complexitem = new ComplexItem();
        complexitem.addItem(new Circle(new Point(375, 250), 25, false));
        complexitem.addItem(new Circle(new Point(350, 300), 50, false));
        complexitem.addItem(new Circle(new Point(325, 400), 75, false));
        
        complexitem.addItem(new Circle(new Point(385, 260), 5, false));
        complexitem.addItem(new Circle(new Point(405, 260), 5, false));
        complexitem.addItem(new Segment(new Point(390, 285), new Point(410, 285)));

        complexitem.addItem(new TextItem(new Point(375,475),"Bawlan"));

        gui.addItems(complexitem);
    
        gui.addItems(new Custom(false, new Point(100, 100), 8));

        gui.addItems(new Triangle(new Point(40, 40), new Point(140, 240), new Point(40, 140)));

        frame.setContentPane(gui);
        frame.setVisible(true);
        
    }
}
