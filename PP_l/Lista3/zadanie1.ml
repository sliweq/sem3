let rec last_elem = fun lista -> 
  if lista == [] 
    then None 
  else 
    if List.tl lista == [] 
      then Some (lista) 
    else last_elem( List.tl lista);;

let lista = [1;2;3;4;5;6;7;8;9;10];;
let wynik = last_elem lista;;

