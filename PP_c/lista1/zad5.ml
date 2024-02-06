let rec reverse = fun x -> 
  if x == [] 
    then x 
  else (reverse (List.tl x))@[List.hd x];;

let rec palindrome = fun a -> 
  if a == [] then true 
  else if (List.tl a) == [] 
    then true 
  else 
    if (List.hd (reverse (List.tl a)) == List.hd a) 
      then palindrome (List.tl (reverse (List.tl a))) 
    else false ;;

