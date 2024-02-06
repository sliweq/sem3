module type BST = 
sig  
  type 'a bt = Empty | Node of 'a * 'a bt * 'a bt;;

  val create : unit -> 'a bt
  val add : 'a -> 'a bt -> 'a bt
  val delete : 'a -> 'a bt -> 'a bt
  val preorder : int bt -> unit
  val postorder : int bt -> unit
  val inorder : int bt -> unit
  val get_leaves : 'a bt -> 'a list 
end;;

module ModBST : BST = struct
  type 'a bt = Empty | Node of 'a * 'a bt * 'a bt
  
  let create() = Empty

  let rec add number root = 
    match root with
    | Empty -> Node(number, Empty,Empty)
    | Node(value, left, right) -> 
      if number > value then Node(value, left,add number right) else Node(value,add number left,right)
  
  let rec delete number root = 
    match root with
    | Empty -> Empty
    | Node(value, left, right) -> 
      if number > value then
        Node(value, left, delete number right)
      else if number < value then
        Node(value, delete number left, right)
      else 
        match root with
        (* | Empty -> failwith "Empty Node" *)
        | Node(_, left, Empty) -> left
        | Node(_, Empty, right) -> right
        | Node(_, left, right) -> 
          let rec find_min root = 
            match root with
            (* | Empty -> failwith "Empty Node" *)
            | Node(v, Empty, _) -> v
            | Node(v, l, _) -> find_min l 
          in
          let tmp = find_min right in
          Node(tmp, left, delete tmp right)

  let rec preorder root =
    match root with
    | Empty -> print_string ""
    | Node (value, left, right) -> 
      print_string (string_of_int value ^ " ");
      preorder left;
      preorder right

  let rec postorder root =
    match root with
    | Empty -> print_string ""
    | Node (value, left, right) -> 
      postorder left;
      postorder right;
      print_string (string_of_int value ^ " ")

  let rec inorder root =
    match root with
    | Empty -> print_string ""
    | Node (value, left, right) -> 
      inorder left;
      print_string(string_of_int value ^ " ");
      inorder right

  let get_leaves root = 
    match root with
    | Empty -> []
    | Node (value, left, right) ->
      let rec get_leaves_iter root list =
        match root with 
        | Empty -> list
        | Node(v,Empty,Empty) -> list@[v]
        | Node(v,left ,Empty) -> get_leaves_iter left list
        | Node(v,Empty,right) -> get_leaves_iter right list
        | Node(v,left,right) -> get_leaves_iter right (get_leaves_iter left list) in
    get_leaves_iter right (get_leaves_iter left []) 
  
end;;

let tree = ModBST.create ();;

let tree = ModBST.add 5 tree;;
let tree = ModBST.add 3 tree;;
let tree = ModBST.add 7 tree;;
let tree = ModBST.add 2 tree;;
let tree = ModBST.add 4 tree;;
let tree = ModBST.add 6 tree;;
let tree = ModBST.add 8 tree;;

ModBST.preorder tree;;

ModBST.postorder tree;;

ModBST.inorder tree;;

let leaves = ModBST.get_leaves tree;;
let tree = ModBST.delete 3 tree;;
let tree = ModBST.delete 7 tree;;
let tree = ModBST.delete 12 tree;;