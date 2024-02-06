1(*zadanie 1 *)
(*podpunkt a*)

module type Point = sig  
  type p
  val create : float->float->float->p
  val distance : p->p->float
  val get_x: p -> float
  val get_y: p -> float
  val get_z: p -> float
end;;
(*podpunkt b*)
module ModPoint : Point = struct
   type p = {x:float;y:float;z:float} 
   let create x y z = {x;y;z}
   let distance p1 p2 = sqrt ( (p1.x -. p2.x)**2. +. (p1.y -. p2.y)**2. +. (p1.y -. p2.y)**2. )
   let get_x p1 = p1.x
   let get_y p1 = p1.y
   let get_z p1 = p1.z
end;;
(*podpunkt c*) 

let p1 = ModPoint.create 0. 0. 0. ;;
let p2 = ModPoint.create 1. 1. 1. ;;
let dist = ModPoint.distance p1 p2;;

(*zadanie 2*)
module type LineSegment = sig 
  type t 
  val create_segment : ModPoint.p -> ModPoint.p -> t 
  val segment_len : t->float
  val get_point_1 : t -> ModPoint.p 
  val get_point_2 : t -> ModPoint.p 
end;;

module ModLineSegment : LineSegment = struct
  type t = {p1:ModPoint.p;p2:ModPoint.p}
  let create_segment p1 p2 = {p1;p2}
  let segment_len segment = ModPoint.distance segment.p1 segment.p2
  let get_point_1 p = p.p1
  let get_point_2 p = p.p2
end;;

let our_segment = ModLineSegment.create_segment p1 p2;;
let segment_l = ModLineSegment.segment_len our_segment;;

(*zadanie 5*)
module type Translation = 
sig  
  type p
  val create : float-> float->float -> p
  val value : p -> float*float*float
  val get_x: p -> float
  val get_y: p -> float
  val get_z: p -> float
end;;

module ModTranslation : Translation = struct
  type p = {x:float ; y:float; z:float}
  let create x y z = {x;y;z}
  let value tmp = (tmp.x, tmp.y, tmp.z)
  let get_x p = p.x
  let get_y p = p.y
  let get_z p = p.z
end;;

(*zadanie 6*)  

module Translate_Point = functor (T : Translation)(P : Point) -> struct
  let get_translated_point point trans = P.create 
    (P.get_x point +. T.get_x trans) 
    (P.get_y point +. T.get_y trans) 
    (P.get_z point +. T.get_z trans)
end;;


module TranslatedPoint = Translate_Point (ModTranslation) (ModPoint);;

module Translate_Segment = functor (T : Translation)(L : LineSegment ) -> struct
  
  let get_translated_segment line trans =
    let point1 = ModPoint.create
      (ModPoint.get_x (L.get_point_1 line)) 
      (ModPoint.get_y (L.get_point_1 line)) 
      (ModPoint.get_z (L.get_point_1 line)) in

    let point2 = ModPoint.create 
      (ModPoint.get_x (L.get_point_2 line)) 
      (ModPoint.get_y (L.get_point_2 line))
      (ModPoint.get_z (L.get_point_2 line))  in

    let trans1 = ModTranslation.create
      (T.get_x trans)
      (T.get_y trans)
      (T.get_z trans) in

    L.create_segment  (TranslatedPoint.get_translated_point point1 trans1) (TranslatedPoint.get_translated_point point2 trans1)
end;;

let example_trans= ModTranslation.create 1.0 2.0 3.0;;
let translated_val = ModTranslation.value (ModTranslation.create 1.0 2.0 3.0);;

let translated_point_tmp = TranslatedPoint.get_translated_point p1 example_trans;;

module Translated_segment_tmp = Translate_Segment(ModTranslation)(ModLineSegment);;
let x = Translated_segment_tmp.get_translated_segment our_segment example_trans;;