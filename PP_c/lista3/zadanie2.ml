(*zwiajnie funckji*)
let uncurry3 f (x,y,z) = f x y z ;; 
let uncurry31 = function (x,y,z) -> function x ->function y -> function z -> x (y (z));; 
(* Rozwijanie funkcji *)

let curry31 = function x ->function y -> function z -> (x y z) ;;
let curry3 f x y z= f (x, y, z );; 
