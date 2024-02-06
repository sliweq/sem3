import scala.math._

def main(args: Array[String]) = {    
    var x = 1::2::Nil
    println("Zadanie 1:")
    println(list_last(x))
    println("Zadanie 2:")
    println(list_last2(x))
    println("Zadanie 3:")
    println(list_len(x))
    println("Zadanie 4:")
    println(list_reverse(x))
    println("Zadanie 5:")
    println(palindorme("kamilslimak"))
    println("Zadanie 6:")
    println(kill_repetitions(x))
    println("Zadanie 7:")
    println(even_list(x))
    println("Zadanie 8:")
    println(prime_number(2))
}
//zadanie 1
def list_last(lista:List[Any]) : Any = {
    if (lista == Nil) {
        return None
    }
    if (lista.tail == Nil){
        return lista.head
    } else {
        list_last(lista.tail)
    }
}
//zadanie2
def list_last2(lista:List[Any]) : Any = {
    if (lista == Nil) {
        return None
    }
    if (lista.tail == Nil){
        return None
    }
    if(lista.tail.tail == Nil){
        return lista
    }
    else{
        list_last2(lista.tail)  
    }
}
//zadanie3
def list_len(lista:List[Any]) : Int = {
    if(lista == Nil){
        return 0
    }else{
        return 1 + list_len(lista.tail)
    }
}
//zadanie4
def list_reverse(lista:List[Any]) : List[Any] = {
    if(lista == Nil){
        return Nil
    }else{
        return list_reverse(lista.tail):::List(lista.head)
    }
}

//zadanie5
def palindorme(our_string:String) : Boolean = {
    if(our_string == ""){
        return true
    }
    if(our_string.size == 1){
        return true 
    }
    if(our_string.charAt(0) == our_string.charAt(our_string.size-1)){
        return palindorme(substring(our_string,1,our_string.size-1))
    }
    return false
}

def substring(str:String,start:Int,end:Int): String ={
    if(start == end){
        return ""
    }else{
        return str.charAt(start)+substring(str,start+1,end)
    }
}

//zadanie6
def kill_repetitions(lista:List[Any]) : List[Any] = {
    if(lista == Nil){
        return lista
    }
    if(lista.tail == Nil){
        return lista
    }
    return List(lista.head):::kill_repetitions(kill_repetitions(lista.head,lista.tail))
}
def kill_repetitions(elem:Any, lista:List[Any]) : List[Any] = { 
    if(lista == Nil){
        return lista
    }
    if(lista.head == elem){
        if(lista.tail == Nil){
            return Nil
        }
        return kill_repetitions(elem, lista.tail)
    }
    return List(lista.head):::kill_repetitions(elem, lista.tail)
}
//zadanie7
def even_list(lista:List[Any]) : List[Any] = {
    if(lista == Nil){
        return lista
    }
    if(lista.tail == Nil){
        return lista
    }
    return List(lista.head):::(even_list(lista.tail.tail))
}
//zadanie8
def prime_number(number: Int) : Boolean = {
    if(number <= 1){
        return false
    }
    return prime_number(2,number)
}
def prime_number(divider:Int, number:Int) : Boolean = { 
    if(divider >= sqrt(number).toInt+1){
        return true
    }
    else{
        if(number%divider == 0){
            return false
        }
        return(prime_number(divider+1, number))
    }
}