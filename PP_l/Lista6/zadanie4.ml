let rec stirling n m = 
  match (n,m) with
  | (0,0) -> 1
  | (n,0) -> 0 
  | (n,m) when n < m -> 0
  | (_,1) -> 1
  | (n,m) when n = m -> 1
  | (_,_) -> (stirling (n-1) (m-1) )+ m*stirling (n-1) m;;

type 'a bellseq = Cons of 'a * (unit -> 'a bellseq);;

let rec bell_number n k = 
  if n > k then 
    stirling n k + bell_number n (k+1)
  else if k=n then stirling n k 
    else 0;;

let rec bell n = Cons(bell_number n 0 , fun() -> bell(n+1));;

(*podpunkt b*)

let stream_tail b = 
  match b with
  | Cons (_,x) -> (x());;

let rec stream_head b n = 
  match b with
  | Cons(x,_) when n = 0 -> x
  | Cons(x,y) -> stream_head (y()) (n-1);;


(*podpunkt c 1*)
let n_stream_elements stream n = 
  let rec helper_iterator stream n lista = 
    if n = 0 then lista 
    else 
      helper_iterator (stream_tail stream) (n-1) (lista@[stream_head stream 0])
  in 
  helper_iterator stream n [];;

(*podpunkt c 2*)
let n2_stream_elements stream n = 
  let rec helper_iterator stream n tmp lista = 
    if n = tmp then lista 
    else if tmp mod 2 = 1 then helper_iterator (stream_tail stream) n (tmp+1) (lista@[stream_head stream 0]) else
      helper_iterator (stream_tail stream) (n-1) (tmp +1) lista
  in 
  helper_iterator stream n 0 [];;

(*podpunkt c 3*)
let rec skip_n_elements stream n =
  if n == 0 then stream
  else
    skip_n_elements (stream_tail stream) (n-1);;

(*podpunkt c 4*)

(* let concatenate_streams s1 s2 n =
  let rec concat_iterator s1 s2 n lista =
    if n = 0 then lista else
      concat_iterator (stream_tail s1) (stream_tail s2) (n-1) lista@[(stream_head s1 0);(stream_head s2 0)]
     in
  concat_iterator s1 s2 n [];; *)

let rec stream_concat s1 s2 n =
  match n with
  | 0 -> failwith "Enought elements"
  | _ -> Cons(((stream_head s1),(stream_head s2)) , fun() -> stream_concat (stream_tail s1) (stream_tail s2) (n-1));;

(*podpunkt c 5*)
let make_sqrt x = x*x;;

let rec map_s f (Cons (h, tf)) = 
  Cons(f h ,fun() ->  map_s f (tf()));;