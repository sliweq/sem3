
    def main(args: Array[String]) = {
        var tmpa = 1::2::3::4::Nil
        var tmpb = 5::6::7::Nil

        println(flatten1(List(tmpa,tmpb)))
    }
    def flatten1[A](xss:List[List[A]]) :List[A] = {
        if (xss == Nil){
            return Nil
        }
        else{
            return xss.head:::flatten1(xss.tail)
        }
    }  
