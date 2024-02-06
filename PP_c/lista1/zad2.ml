let rec count = fun a -> 
  if (snd a) == [] 
    then 0 
else 
  if (List.hd (snd a)) == (fst a) 
    then 1+(count (fst a, List.tl(snd a))) 
      else (count (fst a, List.tl(snd a)));;