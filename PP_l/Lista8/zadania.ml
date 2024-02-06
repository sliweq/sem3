(*zadanie 1*)
type 'x result = Success of 'x | Failure of string;;

(*zadanie 2*)
let input_string () =
  let s = read_line () in
  if String.length s = 0 then Failure "Empty string" else Success s;;

let string_to_int str = 
  try
    Success (int_of_string str )
  with
    Failure _ -> Failure "Input doesn't contain integers";;

let calculate_complementary x =
  let rec calculate_iter x acc =
    if x = 0 then acc
    else
      let len = String.length (string_of_int x) in
      let digit = x / (int_of_float (10. ** (float_of_int (len - 1)))) in
      let acc = (acc * 10) + (9 - digit ) in
      calculate_iter (x - digit * (int_of_float (10. ** (float_of_int (len - 1))))) acc
  in
  if x > 0 then Success (calculate_iter x 0)
  else Failure "Input is not natural number";;

(*przykład*)
let f1 ()= 
  let result = input_string () in
  match result with
  | Failure msg -> print_endline msg
  | Success x -> 
    match string_to_int x with
    | Failure msg -> print_endline msg
    | Success x -> 
      match calculate_complementary x with
      | Success comp -> print_int comp; print_endline ""
      | Failure msg -> print_endline msg ;;

f1();;
(*zadanie 3*)

let bind x f = 
  match x with
  | Failure msg -> Failure msg
  | Success x -> f x;;

(*przykład*)
let f2 () = 
  let result = input_string() in
  let result = bind result string_to_int in
  let result = bind result calculate_complementary in
  match result with 
  | Success comp -> Printf.printf "Success: %d\n" comp
  | Failure msg -> Printf.printf "Failure: %s\n" msg ;;

f2();;

(*zadanie 4*)

let (>>=) x f = bind x f;;

(*przykład*)
let f3 () = 
  (* let result = input_string() in 
  let result = result >>= string_to_int in
  let result = result >>= calculate_complementary in *)
  let result = input_string() >>= string_to_int >>= calculate_complementary in
  
  match result with
  | Success comp -> Printf.printf "Success: %d\n" comp
  | Failure msg -> Printf.printf "Failure: %s\n" msg ;;

f3();;

