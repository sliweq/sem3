file://<WORKSPACE>/zadania.scala
### java.lang.IllegalArgumentException: Comparison method violates its general contract!

occurred in the presentation compiler.

action parameters:
offset: 866
uri: file://<WORKSPACE>/zadania.scala
text:
```scala


def main(args: Array[String]): Unit = {
    //println(stirling(10,10))
    //println(memoized_stirling(10,10))
    println(make_memoize(fibonacci,10))

}

//zadanie 1 a)
def stirling(n: Int,m: Int): Int ={
    (n,m) match
    case (_,1) => 1
    case (n,m) if n == m => 1
    case (_,_) => stirling(n-1,m-1) + m * stirling(n-1,m)
}
//zadanie 1 b)

def memoized_stirling:(Int,Int) => Int ={
    var memoMap = scala.collection.mutable.Map.empty[(Int, Int), Int]
    def memoize(n: Int, m: Int): Int = {
      memoMap.getOrElseUpdate((n,m), stirling(n,m))
    }
    memoize
}

def fibonacci(n: Int): Int = {
    if (n <= 1) n
    else fibonacci(n - 1) + fibonacci(n - 2)
}

def make_memoize:(fun: Int => Int, x :Int) => Int = {
    var memoMap = scala.collection.mutable.Map.empty[(Int => Int), Int]
    def memoize(fun: Int => Int, x :Int): Int = {
        println(x@@)
      memoMap.getOrElseUpdate(fun ,x )
    }
    memoize
}

```



#### Error stacktrace:

```
java.base/java.util.TimSort.mergeLo(TimSort.java:781)
	java.base/java.util.TimSort.mergeAt(TimSort.java:518)
	java.base/java.util.TimSort.mergeForceCollapse(TimSort.java:461)
	java.base/java.util.TimSort.sort(TimSort.java:254)
	java.base/java.util.Arrays.sort(Arrays.java:1233)
	scala.collection.SeqOps.sorted(Seq.scala:727)
	scala.collection.SeqOps.sorted$(Seq.scala:719)
	scala.collection.immutable.List.scala$collection$immutable$StrictOptimizedSeqOps$$super$sorted(List.scala:79)
	scala.collection.immutable.StrictOptimizedSeqOps.sorted(StrictOptimizedSeqOps.scala:78)
	scala.collection.immutable.StrictOptimizedSeqOps.sorted$(StrictOptimizedSeqOps.scala:78)
	scala.collection.immutable.List.sorted(List.scala:79)
	scala.meta.internal.pc.completions.Completions.completions(Completions.scala:210)
	scala.meta.internal.pc.completions.CompletionProvider.completions(CompletionProvider.scala:86)
	scala.meta.internal.pc.ScalaPresentationCompiler.complete$$anonfun$1(ScalaPresentationCompiler.scala:123)
```
#### Short summary: 

java.lang.IllegalArgumentException: Comparison method violates its general contract!