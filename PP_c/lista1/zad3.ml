let k = ("aaa", 5);;

let rec replicate = fun a -> 
  if (snd a) == 0 
    then [] 
  else (replicate (fst a, (snd a)-1))@[fst a] ;;

