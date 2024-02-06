let rec fibo(x) = 
  match x with
  | 0 -> 0 
  | 1 -> 1
  | x -> fibo(x-1) + fibo(x-2);;
  
let rec stirling(n,m) = 
  match (n,m) with
  | (0,0) -> 1
  | (n,0) -> 0 
  | (n,m) when n < m -> 0
  | (_,1) -> 1
  | (n,m) when n = m -> 1
  | (_,_) -> stirling(n-1,m-1) + m*stirling(n-1,m);;

let make_memoize f =
  let h = Hashtbl.create 100 in
  fun x ->
    print_int(Hashtbl.length h);
    print_string(" ");
    try Hashtbl.find h x
  with Not_found ->
      let y = f(x) in
      Hashtbl.add h x y;
      y;;

let memoized = make_memoize fibo;;
print_int(memoized 10);;
print_int(memoized 20);;
print_int(memoized 40);;
print_int(memoized 40);;
