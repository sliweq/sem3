let rec funkcja (xs, ys) = 
  match (xs, ys) with
  | ([],[]) -> true
  | (_,[]) -> false
  | ([],_) -> true
  | (x::s1,y::s2) when x=y-> funkcja(s1,s2)
  | _ -> false;;

  