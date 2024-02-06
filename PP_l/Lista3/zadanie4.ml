let rec list_reverse = fun lista -> 
  if lista = []
    then lista
  else
    list_reverse(List.tl lista)@[List.hd lista];;

let rec print_list = fun lista -> 
  if lista = [] then print_endline ""
  else (if List.tl lista = [] 
    then print_int (List.hd lista) 
  else
    print_int (List.hd lista); print_char ' '; print_list(List.tl lista));;

let x = [1;2;3;4;5;6];;
print_list x;;
print_list (list_reverse x);;