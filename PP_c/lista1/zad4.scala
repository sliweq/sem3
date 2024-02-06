
    def main(args: Array[String]) = {
        val listaLiczb = 1::2::3::(-5)::Nil
        lazy val sqrListFunction: List[Int] => List[Int] = xs => if (xs == Nil) then xs else (List(xs.head*xs.head):::sqrListFunction(xs.tail))
        println(sqrListFunction(listaLiczb))
        println(sqrList(listaLiczb))
    }
    def sqrList(xs: List[Int]): List[Int] = {
        if(xs == Nil){
            return xs
        }
        else{
            return List(xs.head*xs.head):::sqrList(xs.tail)
        }
    }  

