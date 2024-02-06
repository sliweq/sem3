let replaceNth (lista, n, x) =
  let rec replaceNthIter(lista, n, x,currnet) =
    match lista with
    | [] -> lista
    | h::t -> 
      if n == currnet then [x]@t
      else [h]@replaceNthIter(t,n,x, currnet+1) in    
  replaceNthIter(lista, n, x,0);;
