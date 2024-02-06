case class Graph[A](graph: A => List[A])

val g = Graph[Int] {
  case 0 => List(3)
  case 1 => List(0, 2, 4)
  case 2 => List(1)
  case 3 => List()
  case 4 => List(0, 2)
  case n => throw new IllegalArgumentException(s"Graph g: node $n doesn't exist")
}

// Pobieram danyc wierzchołek i dodaje do kolejki wszystkich sąsiadów
// I dodaje obecny do odwiedzonych. 
// Jesli damy wierzchołek jest w odwiedzonych to skip  


def depthSearch[A](graph: Graph[A], startNode: A): List[A] = {
  def dfs(visited: List[A], stack: List[A]): List[A] = stack match {
    case Nil => visited
    case hd :: tl =>
      if (visited.contains(hd)) then dfs(visited, tl)
      else dfs(visited ::: List(hd), graph.graph(hd) ::: stack)
  }

  dfs(List(), List(startNode))
}

object Main {
  def main(args: Array[String]): Unit = {
    val result = depthSearch(g, 4)
    println(result)
  }
}
