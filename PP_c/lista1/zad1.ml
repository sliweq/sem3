let tmp = [[1;2;3];[3;2;1]];;
let rec flatten1 = fun a -> if a == [] then [] else (List.hd a)@(flatten1 (List.tl a)) ;;