type 'x result = Success of 'x | Failure of string;;

let input_string channel =
  let s = ref "" and ch = ref (input_char channel) in
  begin
    while not (!ch = '\n') do
      s := !s^(String.make 1 !ch);
      ch := input_char channel
  done;
  if String.length !s = 0 then Failure "Empty string" else Success !s
  end;;


let string_to_int s = 
  match s with
  | Failure msg -> Failure msg
  | Success x -> 
    try
      Success (int_of_string x )
    with
      Failure _ -> Failure "Input dont contains integers";;

let calculate_complementary x =
  let rec calculate_iter x acc =
    if x = 0 then acc
    else
      let len = String.length (string_of_int x) in
      let digit = x / (int_of_float (10. ** (float_of_int (len - 1)))) in
      let acc = (acc * 10) + (9 - digit ) in
      calculate_iter (x - digit * (int_of_float (10. ** (float_of_int (len - 1))))) acc in

  match x with
  | Failure x -> Failure x
  | Success x when x >= 0 -> Success (calculate_iter x 0)
  | Success _ -> Failure "Input is negative";;

let f = 
  let x = input_string stdin in
  let y = string_to_int x in
  let z = calculate_complementary y in
  match z with 
  | Success comp -> Printf.printf "Success: %d\n" comp
  | Failure msg -> Printf.printf "Failure: %s\n" msg ;;

