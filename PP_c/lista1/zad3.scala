object Klasa {
    def main(args: Array[String]) = {
        print(replicate("aa",3))
    }
    def replicate[A] (x: A, n: Int): List[A] = {
        if(n == 0){
            return Nil
        }
        else{
            return List(x):::replicate(x,n-1)
        }
    }  
}