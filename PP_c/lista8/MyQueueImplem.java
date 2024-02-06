import java.util.ArrayList;

public class MyQueueImplem<E> implements MyQueue<E> {
    private int size = 0;
    private int start_index = 0 ;
    private int end_index = 0;
    private ArrayList<E> elements = new ArrayList<E>();

    public void enqueue( E x ) throws FullException{
        if (end_index+2 % size == start_index){
            throw new FullException("Queue is full");
        }
        elements.add(x);
        end_index = end_index + 1 % size;
    };  
    public void dequeue() throws EmptyException{
        if (isEmpty()){
            throw new EmptyException("Queue is empty");
        }
        else{
            elements.remove(0);
            start_index = start_index + 1 % size;
        }

    }; 
    public E first() throws EmptyException{
        if (isEmpty()) throw new EmptyException("Queue is empty");
        return elements.get(0);
    }; 

    public boolean isEmpty( ){
        return start_index == end_index;
    }; 
    public boolean isFull(){
        return end_index+1 % size == start_index;
    }; 

    
}