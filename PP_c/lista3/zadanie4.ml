let rec quicksort = function
 [] -> [] 
 | [x] -> [x]
 | xs -> let small = List.filter (fun y -> y < List.hd xs ) xs (*nie możemy brać list.hd ponieważ przez to się zapętluje*)
 and large = List.filter (fun y -> y >= List.hd xs ) xs (*wszystko przez to równa się chyba*)
 in quicksort small @ quicksort large;; (*ona mi sie nigdy nie kończ, dokładnie na tym etapie*)

(*usuwa nam duplikaty ;/ wstarczy w jednym miejscu dać >= i tyle*)
let rec quicksort' = function
 | [] -> []
 | x::xs -> 
  let small = List.filter (fun y -> y < x ) xs
  and large = List.filter (fun y -> y > x ) xs
in quicksort' small @ (x :: quicksort' large);;
