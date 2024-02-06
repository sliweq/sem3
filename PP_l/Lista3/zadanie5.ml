let rec palindrome = fun our_string -> 
  if our_string = ""
    then true
  else 
    if String.length our_string = 1
      then true
    else
      if our_string.[0] = our_string.[(String.length our_string) -1 ]
        then palindrome (String.sub our_string 1 ((String.length our_string) -2) )
      else false;;

let rec substring = fun our_string s_index e_index -> 
  if s_index = e_index
    then ""
else
  (String.make 1 our_string.[s_index])^(substring our_string (s_index+1) e_index);;

  
let napis = "kamilslimak";;
let x = palindrome napis;;
print_endline (string_of_bool x);