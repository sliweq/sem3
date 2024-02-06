object Klasa {
    def main(args: Array[String]) = {
        val listaLiczb = 1::3::2::1::Nil
        println(palindrome(listaLiczb))
    }
    def palindrome[A] (xs: List[A]): Boolean = {
        if(xs == Nil){
            return true
        }
    
        if(xs.head == reverse(xs).head){
            if(xs.tail == Nil){
                return true
            }
            return palindrome(reverse(xs.tail).tail)
        }
        return false
    }  
    def reverse[A] (xs: List[A]): List[A] = {
        if(xs == Nil){
            return xs
        }
        else{
            return reverse(xs.tail):::List(xs.head)
        }
    }
}