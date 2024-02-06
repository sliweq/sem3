type 'a maybe = 
  |Just of 'a 
  | Nothing;;

let safeHead lista =
  match lista with
  | [] -> Nothing 
  | h::t -> Just h


