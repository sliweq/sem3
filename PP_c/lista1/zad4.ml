let rec sqrList = fun a -> 
  if a == [] 
    then a 
  else [(List.hd a)*(List.hd a)]@(sqrList (List.tl a));;