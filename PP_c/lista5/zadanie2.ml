type 'a llist = LCons of 'a * (unit -> 'a llist);;

let rec lfib =
  LCons(0, lazy (
    LCons(1, lazy (
      let rec fib a b = LCons(a + b, lazy (fib b (a + b))) in
      fib 0 1
    ))
  ));;


let lhd = function
  LCons (x, _) -> x;;
  
  
let ltl = function
  LCons (_, xf) -> xf();;
      