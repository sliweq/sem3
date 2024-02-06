let rec fib x =  
match x with
| 0 -> 0
| 1 -> 1 
| _ -> fib(x-2) + fib(x-1)

let fibTail x =
  let rec fibIter(x, a, b )= 
    match x with
    | 0 -> a
    | _ -> fibIter(x-1, b, a+b) in
  match x with
  | 0 -> 0
  | 1 -> 1
  | _ -> fibIter(x , 0, 1)
