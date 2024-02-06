    
    def main(args: Array[String]) = {
        var tmpa = 1::2::3::4::1::2::3::4::1::Nil
        println(fcount(1, tmpa))
    }
    def fcount[A] (x: A, xs: List[A]): Int = {
        if (xs == Nil){
            return 0
        }
        if(xs.head == x){
            return 1 + fcount(x, xs.tail)
        }
        else{
            return fcount(x, xs.tail)
        }
    }  
