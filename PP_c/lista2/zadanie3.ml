let root3 x = 
  let rec rootIter(x,a) = 
    print_float(x);
    print_endline("");
    if (abs_float((x*.x*.x) -. a) <= (10e-15 *. abs_float(a)))
       then x else rootIter(x +. (((a/.(x*.x)) -. x)/. 3.),a) in 
  if x > 1. then rootIter(x /. 3., x) else rootIter(x, x);;
