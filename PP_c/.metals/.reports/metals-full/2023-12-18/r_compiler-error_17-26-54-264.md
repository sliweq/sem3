file://<WORKSPACE>/lista8/MyQueueImplem.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 454
uri: file://<WORKSPACE>/lista8/MyQueueImplem.java
text:
```scala
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
        end_index = end_index + 1@@ % size;
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