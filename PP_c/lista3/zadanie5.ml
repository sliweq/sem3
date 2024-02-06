(*sortowanie*)

let rec insertSort comp l = 
  let rec insert x l = 
    match l with
    | [] -> [x]
    | y::ys -> if comp x y  then x::y::ys else y::insert x::ys
  in match l with 
  | [] -> []
  | x::xs -> insert x (insertSort comp xs)


