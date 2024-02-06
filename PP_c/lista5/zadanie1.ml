type 'a llist = LCons of 'a * (unit -> 'a llist);;

let rec irep k = LCons (k, function () -> irep (k+1));;



let rec lrepeat n (LCons (h, tf)) =
  let rec helper k =
    match k with
    | 0 -> lrepeat n (tf())
    | k -> LCons (h, fun () -> helper (k-1))
  in
  helper n;;
  

  
  
let lhd = function
  LCons (x, _) -> x;;
  
  
let ltl = function
  LCons (_, xf) -> xf();;
  
