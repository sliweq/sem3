(*lista 7 zadanie 1*)
module type QUEUE_FUN = 
sig 
  type 'a t 
  exception Empty of string 
  val empty: unit -> 'a t 
  val enqueue: 'a * 'a t -> 'a t 
  val dequeue: 'a t -> 'a t         
  val first: 'a t -> 'a 
  val isEmpty: 'a t -> bool 
end;;

module Queue_1 : QUEUE_FUN = struct
  type 'a t = 'a list 
  exception Empty of string
  let empty () = []
  let enqueue (elem, queue)  = queue @ [elem]
  let dequeue queue = 
    match queue with
    | [] -> raise (Empty "Empty Queue")
    | _::tail -> tail
  let first queue = List.hd queue 
  let isEmpty queue = queue = []
end;;

module Queue_2 : QUEUE_FUN = struct 
  type 'a t = 'a list * 'a list 
  exception Empty of string
  let empty () = ([], [])
  let enqueue (elem, (x,y)) = (x, [elem]@y)
  let dequeue queue = 
    match queue with
    | ([],[]) -> raise (Empty "Empty Queue")
    | ([],y) -> (List.tl (List.rev y),[])  
    | (x,y) -> (List.tl x, y)
  
  let first queue = 
    match queue with
    | ([],[]) -> raise (Empty "Empty Queue")
    | ([],y) -> List.hd (List.rev y)
    | (x,y) -> List.hd x

  let isEmpty (x,y) = x = [] and y = []
end;;

(*lista 7 zadanie 2*)

module type QUEUE_MUT = 
sig 
  type 'a t 
  exception Empty of string 
  exception Full of string 
  val empty: int -> 'a t 
  val enqueue: 'a * 'a t -> unit 
  val dequeue: 'a t -> unit 
  val first: 'a t -> 'a 
  val isEmpty: 'a t -> bool 
  val isFull: 'a t -> bool 
end;;

module Queue_M : QUEUE_MUT = struct
  type 'a t = {mutable f: int; mutable r: int; mutable size: int; mutable arr: 'a list}
  exception Empty of string
  exception Full of string

  let empty n = {f = 0; r = 0; size = n; arr = []}

  let enqueue (elem, queue) =
    if (queue.r + 1 mod queue.size = queue.f) then raise (Full "Full Queue")
    else
      queue.r <- (queue.r + 1 mod queue.size);
      queue.arr <- queue.arr @ [elem]

  let dequeue queue =
    if queue.f = queue.r then raise (Empty "Empty Queue")
    else
      let elem = List.hd queue.arr in
      queue.f <- (queue.f + 1 mod queue.size);
      queue.arr <- List.tl queue.arr (* Remove the dequeued element from the list *)

  let first queue =
    if queue.f = queue.r then raise (Empty "Empty Queue")
    else
      List.hd queue.arr

  let isEmpty queue = queue.f = queue.r

  let isFull queue = (queue.r + 1 mod queue.size) = queue.f
end;;
  
      
  
  