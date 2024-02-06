

def main(args: Array[String]): Unit = {
    println(stirling(10,9))
    //println(memoized_stirling(10,10))
    //println(make_memoize(fibonacci,10))

}

//zadanie 1 a)
def stirling(n: Int,m: Int): Int ={
    (n,m) match
    case (0,0) => 1
    case (n,0) => 0
    case (n,m) if n < m => 0
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

// def make_memoize:(fun: Int => Int) => Int => Int = {
//     var memoMap = scala.collection.mutable.Map.empty[(Int => Int), Int]
//     def memoize(fun: Int => Int, x :Int): Int => Int = {
//       memoMap.getOrElseUpdate(fun ,x)
//     }
//     memoize
// }
