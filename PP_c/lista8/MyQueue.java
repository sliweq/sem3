public interface MyQueue<E>{ 
    public void enqueue( E x ) throws FullException;  
    public void dequeue( ) throws EmptyException; 
    public E first( ) throws EmptyException;       
    public boolean isEmpty( ); 
    public boolean isFull( ); 
}

class EmptyException extends Exception {
    public EmptyException( ) { 
        super(); 
    }
    public EmptyException( String msg ) { 
        super( msg ); 
    }
}

class FullException extends Exception {
    public FullException( ) { 
        super(); 
    }
    public FullException( String msg ) { 
        super( msg ); 
    }
}