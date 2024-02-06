type 'a lBT = LEmpty | LNode of 'a * (unit ->'a lBT) * (unit -> 'a lBT);;

let rec lbt x =
  match x with
  | x when x < 0 -> failwith "x less than 0"
  | 0 -> LEmpty
  | x -> LNode (x, (fun () -> lbt (x - 1)), (fun () -> lbt (x - 1)));;


let get_value x =
  match x with
  | LEmpty -> failwith "node is empty"
  | LNode(x,_,_) -> x;;

let get_left_node x =
  match x with
  | LEmpty -> failwith "node is empty"
  | LNode(x,n,_) -> n();;

let get_right_node x =
  match x with
  | LEmpty -> failwith "node is empty"
  | LNode(x,_,n) -> n();;

let lBreadth x =
  let rec iterBreadth queue values =
    match queue with
    | [] -> values
    | hd :: tl ->
        match hd with
        | LEmpty ->  iterBreadth tl values
        | LNode (v, n1, n2) ->
            iterBreadth (tl @ [n1 (); n2 ()]) (values @ [v])
  in
  iterBreadth [x] [];;

type 'a lBT = LNode of 'a * (unit ->'a lBT) * (unit -> 'a lBT);;

let rec lbt x =
  match x with
  | x when x < 0 -> failwith "x less than 0"
  | x -> LNode (x, (fun () -> lbt (2*x) ), (fun () -> lbt ((2*x)+1)));;


let lBreadth2 x k=
  let rec iterBreadth2 queue values k =
    match queue,k with
    | [],_ -> values
    | hd :: tl, 0 -> values
    | hd :: tl,k ->
        match hd with
        | LEmpty ->  iterBreadth2 tl values (k-1)
        | LNode (v, n1, n2) ->
            iterBreadth2 (tl @ [n1 (); n2 ()]) (values @ [v]) (k-1)
  in
  iterBreadth2 [x] [] k;;