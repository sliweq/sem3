file://<WORKSPACE>/lista8/MyQueue.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 320
uri: file://<WORKSPACE>/lista8/MyQueue.java
text:
```scala
public interface MyQueue<E>{ 
    public void enqueue( E x ) throws FullException;  
    public void dequeue( ) throws EmptyException; 
    public E first( ) throws EmptyException;       
    public boolean isEmpty( ); 
    public boolean isFull( ); 
}

class EmptyException extends Exception {
    public EmptyException@@( ) { 
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
```



#### Error stacktrace:

```
scala.collection.Iterator$$anon$19.next(Iterator.scala:973)
	scala.collection.Iterator$$anon$19.next(Iterator.scala:971)
	scala.collection.mutable.MutationTracker$CheckedIterator.next(MutationTracker.scala:76)
	scala.collection.IterableOps.head(Iterable.scala:222)
	scala.collection.IterableOps.head$(Iterable.scala:222)
	scala.collection.AbstractIterable.head(Iterable.scala:933)
	dotty.tools.dotc.interactive.InteractiveDriver.run(InteractiveDriver.scala:168)
	scala.meta.internal.pc.MetalsDriver.run(MetalsDriver.scala:45)
	scala.meta.internal.pc.HoverProvider$.hover(HoverProvider.scala:34)
	scala.meta.internal.pc.ScalaPresentationCompiler.hover$$anonfun$1(ScalaPresentationCompiler.scala:342)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator