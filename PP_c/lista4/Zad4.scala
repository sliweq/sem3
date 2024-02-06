sealed trait BT[+A]
case object Empty extends BT[Nothing]
case class Node[+A](elem:A, left:BT[A], right:BT[A]) extends BT[A]

val t = Node(1, Node(2, Node(4, Empty, Empty ), Empty ), Node(3,Node(5, Empty, Node(6, Empty, Empty ) ), Empty ) )
  def main(args: Array[String]): Unit = {


    val inter = inter_path(t)
    val outer = outer_path(t)
    println(inter)
    println(outer)
  }

  def inter_path[A](tree: BT[A]) : Int ={
    def inter_help(tree: BT[A], amount:Int):Int = {
        tree match{
            case Empty => 0
            case Node(_,Empty,Empty) => amount
            case Node(_, Empty, n2) => amount + inter_help(n2,amount+1)
            case Node(_, n1, Empty) => amount + inter_help(n1,amount+1)
            case Node(_, n1, n2) => amount + inter_help(n2,amount+1) + inter_help(n1,amount+1)
        }
    }
    inter_help(tree,0)
  }

  def outer_path[A](tree: BT[A]) : Int ={
    def outer_help(tree: BT[A], amount: Int) : Int = {
        val newamount = amount + 1
        tree match{
            case Empty => 0
            case Node(_,Empty,Empty) => 2*newamount
            case Node(_, Empty, n2) => newamount + outer_help(n2,newamount)
            case Node(_, n1, Empty) => newamount + outer_help(n1,newamount)
            case Node(_, n1, n2) => outer_help(n2,newamount) + outer_help(n1,newamount) 
        }
    }
    outer_help(tree,0 )
  }
  
