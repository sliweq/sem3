(*type point2D = (float*float)*(float*float);;*)
type point2D = float*float;;

let distance2 (p1:point2D)(p2:point2D):float = 
  sqrt((fst p1 -. fst p2)** 2.+.(snd p1 -. snd p2) ** 2.)

type point3D = float*float*float;;

let distance3 (p1:point3D)(p2:point3D):float =
  let x1, y1, z1 = p1 in
  let x2, y2, z2 = p2 in
  sqrt((x1 -. x2)** 2.+.(y1 -. y2) ** 2.+.(z1 -. z2) ** 2.)


type pointND = float list;;
(*sqrt*)
  
let rec disatnceN (p1:pointND)(p2:pointND):float =
  match p1,p2 with
  | [],[] -> 0.
  | hp1::tp1, hp2::tp2 -> (hp1 -. hp2)** 2. +. disatnceN tp1 tp2  
