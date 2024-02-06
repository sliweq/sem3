let rec listLength = fun a -> if a == [] then 0 else 1 +listLength (List.tl a);;
