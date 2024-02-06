type 'a graph = Graph of ('a -> 'a list)

let g = Graph
(function
0 -> [3]
| 1 -> [0;2;4]
| 2 -> [1]
| 3 -> []
| 4 -> [0;2]
| n -> failwith ("Graph g: node "^string_of_int n^" doesn't exist"));;

(*Pobieram danyc wierzchołek i dodaje do kolejki wszystkich sąsiadów
I dodaje obecny do odwiedzonych. 
Jesli damy wierzchołek jest w odwiedzonych to skip   
*)

let depth_search (Graph grap) startNode =
  let rec dfs visited stack =
    match stack with
    | [] -> visited
    | hd::tl -> if (List.mem hd visited) then dfs visited tl else dfs (visited@[hd]) (grap(hd)@stack)
  in
  dfs [] [startNode];;
