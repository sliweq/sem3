let rec list_last2 = fun lista -> 
  if lista = [] 
    then None 
  else 
    if List.tl lista = [] 
      then None
    else 
      if (List.tl (List.tl lista)) = []
        then Some lista
      else list_last2(List.tl lista);;


      