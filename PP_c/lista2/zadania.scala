import scala.annotation.tailrec
def main(args: Array[String]): Unit = {

  
  
  println(root3(10))
  // val fib1: (Int) => Int = x => x match {
    //   case 0 => 0
    //   case 1 => 1
    //   case _ => fib1(x - 2) + fib1(x - 1)}

    //zadanie 4 a

    val wzorzec = (-2, -1, 0, 1, 2)
    val (_,_,x,_,_) = wzorzec;
  
    //val lista = List(-2, -1, 0, 1, 2);
    //val List(_,_,x,_,_) = lista

    //zadanie 4 b 
    //val lista =((1,2),(0,1))
    //val ((_,_),(x,_)) = lista

    //val lista = List((1,2),(0,1));
    //val List((_,_),(x,_)) = lista

    val y = 1::2::3::Nil
    val z = 1::2::3::4::Nil
    println(initSegment(y,z))

    val a = 'a'::'b'::'c'::'d'::'e'::Nil
    println(replaceNth(a,7,'b'))
    
    val root4 = (x:Double) => 
        lazy val tak :((Double, Double) => (Double))= (x, a) => if (math.abs((x*x*x)-a) <= 1e-15 * math.abs(a)) then x else tak(x + (((a/(x*x))-x)/3),a)
      if x > 1 then tak(x/3,x ) else tak(x,x)
  }   

  def root3(x:Double): Double ={
    @tailrec
    def rootIter(x:Double, a:Double): Double = {
      //x + (((a/(x*x))-x)/3) 
      if (math.abs((x*x*x)-a) <= 1e-15 * math.abs(a)){
        return x
      }else{
        return rootIter(x + (((a/(x*x))-x)/3),a)
      }
    }
    if (x >1){
      return rootIter(x/3,x)
    }else{
      return rootIter(x,x)
    }
  }
  
def fib(x:Int): Int= {

    x match{
        case 0 => 0
        case 1 => 1
        case _ => fib(x-2) + fib(x-1)
    }
}

def fibTail(x: Int): Int = {
  @tailrec
  def fibIter(n: Int, a: Int, b: Int): Int = {
    n match {
      case 0 => a
      case _ => fibIter(n - 1, b, a + b)
    }
  }
  x match {
    case 0 => 0
    case 1 => 1
    case _ => fibIter(x, 0, 1)
  }
}


//zadanie 5
def initSegment[A](xs: List[A], ys: List[A]): Boolean = {
   (xs,ys) match{
    case (Nil,Nil) => true
    case (Nil,_) => true
    case (_,Nil)=> false
    case (_,_) => if(xs.head == ys.head) then initSegment(xs.tail,ys.tail) else false
   }
}
//zadanie 6


def replaceNth[A](xs: List[A], n: Int, x: A): List[A] = {

   def replaceNthIter[A](xs: List[A], n: Int, x: A, index:Int): List[A] = {
    xs match{
      case Nil => xs
      case head::tail => 
        if n == index then List(x):::tail
        else List(head):::replaceNthIter(tail, n, x, index+1)
    }
   }
    return replaceNthIter(xs, n , x, 0)
}