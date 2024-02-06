import java.awt.Graphics;
import javax.swing.*;

import Items.Item;

import java.util.ArrayList; 


public class Scene extends JPanel {
    ArrayList<Item> shapes; 
    public Scene() {
        shapes = new ArrayList<Item>();
    }

    public void addItems(Item item){
        shapes.add(item);
    }

    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for(Item item : shapes){
            item.draw(g);
        }

    }
}
