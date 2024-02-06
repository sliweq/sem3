let rec stirling n m = 
  match (n,m) with
  | (0,0) -> 1
  | (n,0) -> 0 
  | (n,m) when n < m -> 0
  | (_,1) -> 1
  | (n,m) when n = m -> 1
  | (_,_) -> (stirling (n-1) m-1 )+ m*stirling (n-1) m;;

let lazy_evaluation f x y = lazy (f x y) ;; 

let lazy_pre_result = lazy_evaluation stirling 10 9;;

let lazy_result = Lazy.force lazy_pre_result;;
