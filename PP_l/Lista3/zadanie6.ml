let rec kill_repetitions2 = fun element  ->
  if snd element = []
    then snd element
  else 
    if List.hd (snd element) = fst element
      then 
        if List.tl (snd element) = []
          then []
        else kill_repetitions2((fst element,  (List.tl (snd element))))
    else [List.hd (snd element)]@kill_repetitions2((fst element,  (List.tl (snd element))));;

let rec kill_repetitions = fun lista -> 
  if lista = []
    then lista
  else 
    if List.tl lista = []
      then lista
  else [List.hd lista]@kill_repetitions (kill_repetitions2 ((List.hd lista),(List.tl lista)));;

let rec print_list = fun lista -> 
  if lista = [] then print_endline ""
  else (if List.tl lista = [] 
    then print_int (List.hd lista) 
  else
    print_int (List.hd lista); print_char ' '; print_list(List.tl lista));;

let x = [1;2;3;1;2;3;4;5;5;6;5;6;4;5;6];;
print_list x;;
print_list (kill_repetitions x);;