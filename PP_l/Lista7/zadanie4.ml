module type Number = 
sig  
  type 'a p
  val create : 'a -> 'a p
  val value : 'a ->'a p
end;;

module ModNumber : Number = struct
  type 'a p = 'a
  let create x = x
  let value x = x
end;;

module MakePoint = functor (N1 : Number)(N2 : Number) -> struct
  type 'a point = { x: 'a N1.p; y: 'a N2.p }  
  let create x y = {x = N1.create x; y = N2.create y}
  let return_point point = (N1.value point.x, N2.value point.y)
end;;

module MPfunctor = MakePoint(ModNumber)(ModNumber);;

let point = MPfunctor.create 10. 20.;;
let coordinates = MPfunctor.return_point point;;