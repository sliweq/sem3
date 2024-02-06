package Items;

import java.awt.Graphics;

public class BaseDecorator extends Item {
    Item item;

    public BaseDecorator(Item item) {
        this.item = item;
    }

    @Override
    public Point[] getBoundingBox() {
        return item.getBoundingBox();
    }

    @Override
    public void draw(Graphics g) {
        item.draw(g);
    }

    public Item getItem(){
        return item;
    }
}
