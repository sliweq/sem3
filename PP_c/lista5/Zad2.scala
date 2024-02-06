def lfib: LazyList[Long] = {
    def fib(a:Long, b:Long): LazyList[Long] ={
        a #:: fib(b, a + b)
    }
    fib(0,1)
}