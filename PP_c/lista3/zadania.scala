def main(args: Array[String]): Unit = {
  
  val x=List(1,2,3,4,5)
  print(x.foldLeft((0,1))((m,n) => (m._1+n,m._2*n)))

  //print(sumProd(List(1,2,3,4,5)))
}
//zadanie 2
def uncurry3[A, B, C, D](f: A => B => C => D): (A, B, C) => D = (x, y, z) => f(x)(y)(z)

def curry3[A, B, C, D](f: (A, B, C) => D): A => B => C => D = x => y => z => f(x, y, z)
//def curry31

//zadanie 3 
def sumProd(xs : List[Int]):(Int,Int) = {
  xs match 
    case h::t => {
      val (s,p)=sumProd(t)
      (h+s,h*p)
    }
    case Nil => (0,1)
}
