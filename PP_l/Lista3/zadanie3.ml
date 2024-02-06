let rec list_len = fun lista -> 
  if lista = []
    then 0 
  else 
    1 + list_len(List.tl lista);;

let moja_lista = [1; 2; 3; 4; 5];;
let dlugosc = list_len moja_lista;;
print_int dlugosc;;
print_endline "" ;


