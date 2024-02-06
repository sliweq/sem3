enum LList[+A]:
  case LCons(head: A, tail: () => LList[A])

def irep[A](k: A): LList[A] =
  LList.LCons(k, () => irep(k + 1))

def lrepeat[A](n: Int, llist: LList[A]): LList[A] =
  def helper(k: Int, l: LList[A]): LList[A] =
    k match
      case 0 => lrepeat(n, l.tail())
      case _ => LList.LCons(l.head, () => helper(k - 1, LList.LCons(l.head, () => l.tail())))

  helper(n, llist)

object LListExample extends App {
  val infiniteList: LList[Int] = irep(1)

  val finiteList: LList[Int] = lrepeat(5, infiniteList)


  printList(finiteList)

  def printList[A](llist: LList[A], n: Int = 5): Unit = {
    var currentList = llist
    for (_ <- 1 to n) {
      currentList match {
        case LList.LCons(head, tail) =>
          println(s"Element: $head")
          currentList = tail()
        case _ => println("End of the list")
      }
    }
  }
}