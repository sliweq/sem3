let rec even_list = fun lista -> 
  if lista = []
    then lista
  else 
    if (List.tl lista = [])
      then lista
    else 
      [List.hd lista]@(even_list(List.tl(List.tl lista)));;

let rec print_list = fun lista -> 
  if lista = [] then print_endline ""
  else (if List.tl lista = [] 
    then print_int (List.hd lista) 
  else
    print_int (List.hd lista); print_char ' '; print_list(List.tl lista));;


let x = [1;2;3;4;5;6;7;8;9];;
print_list x;;
let wynik = even_list x;;
print_list wynik;;
