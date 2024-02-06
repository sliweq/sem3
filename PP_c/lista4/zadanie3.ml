type 'a bt = Empty | Node of 'a * 'a bt * 'a bt

let tt = Node(1, Node(2, Node(4, Empty, Empty ), Empty ), Node(3,Node(5, Empty, Node(6, Empty, Empty ) ), Empty ) );; 

let breadthBT tree = 
  let rec breadthBT_queue tree list = 
    match tree with
    |Empty -> list@[Empty]
    |Node(v, Empty, Empty) -> list@[tree] 
    |Node(v, Empty, n2) -> list@[tree]
    |Node(v, n1,Empty) -> list@[tree]
    |_ -> list@[tree]in 

  let rec breadthBT_helper queue list = 
    match queue with
    | [] -> list
    | hd::tl ->
      match hd with
      |  Node(x,_,_) -> breadthBT_helper tl list@[x]
      | Empty -> breadthBT_helper tl list in
  let queue = breadthBT_queue tree [] in
  breadthBT_helper queue [];;