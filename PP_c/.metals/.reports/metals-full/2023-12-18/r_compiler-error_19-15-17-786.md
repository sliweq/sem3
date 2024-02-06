file://<WORKSPACE>/lista6/Porownanie.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 429
uri: file://<WORKSPACE>/lista6/Porownanie.java
text:
```scala
public class Porownanie{ 
    public static void main(String[] args){ 
      String s1 = "foo"; 
      String s2 = "foo"; 
      //aliasowanie s1 i s2 - obie zmienne wskazują na ten sam obiekt
      System.out.println(s1 == s2); 
      System.out.println(s1.equals(s2)); 
      String s3 = new String("foo");   
      System.out.println(s1 == s3);  //referencje wsakzuja na różne obiekty w pamięci
      System.out.println(s1.equ@@als(s3));  
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