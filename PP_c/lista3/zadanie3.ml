let lista  = [1;2;3;4;5];;

let rec fold_left f acc xs =
  match xs with
  h::t -> fold_left f (f acc h) t
  | [] -> acc ;;

let result = fold_left (fun (x, y) n -> (x + n, y * n)) (0, 1) lista;;


