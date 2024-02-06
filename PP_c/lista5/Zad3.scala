sealed trait LBT[+A]
case object LEmpty extends LBT[Nothing]
case class LNode[+A](value: A, left: () => LBT[A], right: () => LBT[A]) extends LBT[A]

object LBT {
  def lbt[A](x: Int): LBT[Int] = x match {
    case x if x < 0 => throw new IllegalArgumentException("x less than 0")
    case 0 => LEmpty
    case _ => LNode(x, () => lbt(x - 1), () => lbt(x - 1))
  }

  def lBreadth[A](x: LBT[A]): List[A] = {
    def iterBreadth(queue: List[LBT[A]], values: List[A]): List[A] =
      queue match {
        case Nil => values
        case LEmpty :: tl => iterBreadth(tl, values)
        case LNode(v, n1, n2) :: tl => iterBreadth(tl ::: List(n1(), n2()), values :+ v)
      }

    iterBreadth(List(x), List.empty)
  }
}

object Main extends App {
  val exampleTree = LBT.lbt(3)
  val breadthValues = LBT.lBreadth(exampleTree)
  println(breadthValues)
}

sealed trait LBT[+A]
case class LNode[+A](value: A, left: () => LBT[A], right: () => LBT[A]) extends LBT[A]

object LBT {
  def lbt[A](x: Int): LBT[Int] = x match {
    case x if x < 0 => throw new IllegalArgumentException("x less than 0")
    case _ => LNode(x, () => lbt(2 * x), () => lbt(2 * x + 1))
  }

  def lBreadth2[A](x: LBT[A], k: Int): List[A] = {
    def iterBreadth2(queue: List[LBT[A]], values: List[A], k: Int): List[A] =
      (queue, k) match {
        case (Nil, _) => values
        case (_, 0) => values
        case (hd :: tl, _) =>
          hd match {
            case LNode(v, n1, n2) =>
              iterBreadth2(tl ::: List(n1(), n2()), values ::: List(v), k - 1)
            case _ => iterBreadth2(tl, values, k - 1)
          }
      }

    iterBreadth2(List(x), List.empty, k)
  }
}

object Main extends App {
  val exampleTree = LBT.lbt(3)
  val breadthValues = LBT.lBreadth2(exampleTree, 5)
  println(breadthValues)
}