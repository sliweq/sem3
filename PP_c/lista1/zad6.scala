import scala.annotation.tailrec
object Klasa {
    def main(args: Array[String]) = {
        val listaLiczb = Nil
        println(listLength(listaLiczb))
    }
    def listLength[A](xs: List[A]): Int = {
        if(xs == Nil){
            return 0
        }
        else{
            return listLength(xs.tail) + 1
        }
    }  
    scala.annotation.tailrec
    def listLength[A](xs: List[A], tmp: Int): Int = {
        xs match{
            case Nil => 0
            case head :: next => print(tmp); listLength(next,1+tmp)
        }
    }  
}