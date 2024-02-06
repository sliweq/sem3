type soildFigure = 
  | Cubeoid of {a:float;b:float;h:float} 
  | Cone of {r:float;h:float} 
  | Sphere of {r:float} 
  | Cylinder of {r:float;h:float};;


let volume (f:soildFigure):float =
  match f with
  | Cubeoid f -> f.a*.f.b*.f.h
  | Cone f -> (1./.3.)*.3.14*.(f.r ** 2.) *. f.h
  | Sphere f -> (4./.3.)*.3.14*.(f.r ** 3.)
  | Cylinder f -> 3.14*.(f.r ** 2.) *. f.r;;

let x = Cubeoid {a=1.;b=1.;h=1.};;
volume x;;