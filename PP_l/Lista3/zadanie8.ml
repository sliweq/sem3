let rec prime_number = fun divider number ->
  if divider >= ((int_of_float (sqrt (float_of_int number)))+1)
    then true
  else 
    if (number mod divider) = 0
      then false
    else (prime_number (divider+1) number);;

let prime_number = fun number ->
  if number <= 1
    then false
  else prime_number 2 number;;

let x = 5;;
let y = 15;;
let z = 13;;

print_int x;;
print_endline "";;
print_endline (string_of_bool (prime_number x));;
print_int y;;
print_endline "";;
print_endline (string_of_bool (prime_number y));;
print_int z;;
print_endline "";;
print_endline (string_of_bool (prime_number z));;
