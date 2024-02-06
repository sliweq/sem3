let rec stirling(n,m) = 
  match (n,m) with
  | (0,0) -> 1
  | (n,0) -> 0 
  | (n,m) when n < m -> 0
  | (_,1) -> 1
  | (n,m) when n = m -> 1
  | (_,_) -> stirling(n-1,m-1) + m*stirling(n-1,m)

let memoized_stirlingInit () =
  let h = Hashtbl.create 100 in
    fun (n, m) ->
      let rec help (n,m) = 
        try Hashtbl.find h (n, m) with Not_found ->
        match (n,m) with
        | (0,0) -> Hashtbl.add h (n, m) 1; 1
        | (n,0) -> Hashtbl.add h (n, m) 0; 0
        | (n,m) when n < m -> Hashtbl.add h (n, m) 0; 0
        | (_,1) -> Hashtbl.add h (n, m) 1; 1
        | (n,m) when n = m -> Hashtbl.add h (n, m) 1; 1
        | (_,_) -> Hashtbl.add h (n,m) (help(n-1,m-1) + m*help(n-1,m)); help(n,m) in      
      try Hashtbl.find h (n, m)
      with Not_found -> 
        help(n,m);;

let memoized_stirling = memoized_stirlingInit();;
memoized_stirling (10,5);; 
