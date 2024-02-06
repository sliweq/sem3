import scala.annotation.tailrec
// @tailrec
def main(args: Array[String]): Unit = {
    //zad 0 
    val WarnLog=  Log("Warn")
    val NightlyWarnLog = WarnLog("2022-10-26 01:45")
    NightlyWarnLog("Hello")

    //zad 4 
    println("zadanie 4:")
    val lista = 1::2::3::4::5::6::8::9::Nil
    println(lista)
    println(average(lista))

    //zad 5
    println("zadanie 5:")
    val zus = "Zakład Ubezpieczeń Społecznych"
    println(zus)

    //println(akonim(zus.split(" ").toList))
    println(akonim(stringToList(zus)))

    //zad 6
    println("zadanie 6:")
    val szescainy = 1::2::3::4::5::6::8::9::Nil
    println(szescainy)
    println(lower_then_sum(szescainy))

}
//zad 0
def Log(prefix: String)(datetime: String)(text: String):Unit = {
    println("[" + prefix + "]" + " " + datetime + "\t" + text)
} 
//zad 1
def Map[T](lista: List[T],f:T => T ): List[T] ={
    lista match{
        case Nil => lista
        case head::tail =>List(f(head)):::Map(tail,f)
    }
}
//zad 2
def Filter[T](lista: List[T],f:T => Boolean ): List[T] ={
    lista match{
        case Nil => lista
        case head::tail => if f(head) then List(head):::Filter(tail,f) else Filter(tail,f)
    }
}

//zad 3 
def Reduce[T](lista: List[T], op:T => Int, acc: Int): Int ={
    lista match{
        case Nil => acc
        case head::tail => Reduce(tail, op, acc+op(head))
        
    }    
}
//zadnie 4
def sum(x:Int): Int ={
    return x
}

def average(lista: List[Int]): Double = {
    def amount(x:Int): Int ={
        return 1
    }

    return Reduce(lista, sum, 0)/ ((Reduce(lista,amount, 0) *1.0 ))
}
//zadnie 5
def stringToList(txt:String): List[String] = {
    def iter(txt:String, index:Int, lista:List[String], tmp:String): List[String] ={
        
        if(index >= txt.length()){
            if(tmp != ""){

                return lista:::List(tmp)
            }
            return lista
        }
        if(txt.charAt(index) == " ".charAt(0)){
            if(tmp != ""){
                return iter(txt, index+1, lista::: List(tmp),"") 
            }
            return iter(txt, index+1, lista,"") 
        }
        else{
            return iter(txt, index+1, lista,tmp + txt.charAt(index)) 
        }
    }
    if(txt == ""){
        return Nil
    }
    val x = Nil
    return iter(txt, 0, x, "")
}

def akonim(lista:List[String]): String = {
    def tak(str:String): String = {
        return str.charAt(0).toString()
    }
    def naTekst(lista:List[String], txt:String): String ={
        lista match{
            case Nil => txt
            case head :: next => naTekst(next, txt+head)
        }
            
    }
    

    return naTekst(Map(lista, tak), "")
}

//zadnie 6 
def lower_then_sum(lista: List[Int]) : List[Int] = {

    val suma = Reduce(lista, sum, 0)
    def is_smaller(liczba: Int): Boolean = {
        return liczba*liczba*liczba < suma
    }
    return Filter(lista,is_smaller)
}