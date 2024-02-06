(*zadanie 1 *)
(*podpunkt a*)
module type Point = 
sig  
  type p = {x:float;y:float;z:float} 
  val create : float->float->float->p
  val distance : p->p->float
end;;
(*podpunkt b*)
module ModPoint : Point = struct
   type p = {x:float;y:float;z:float} 
   let create p1 p2 p3 = {x=p1;y=p2;z=p3}
   let distance p1 p2 = sqrt ( (p1.x -. p2.x)**2. +. (p1.y -. p2.y)**2. +. (p1.y -. p2.y)**2. )
end;;
(*podpunkt c*) 

let p1 = ModPoint.create 0. 0. 0. ;;
let p2 = ModPoint.create 1. 1. 1. ;;
let dist = ModPoint.distance p1 p2;;

(*zadanie 2*)
module type LineSegment = sig 
  type t = {p1:ModPoint.p;p2:ModPoint.p}
  val create_segment : ModPoint.p -> ModPoint.p -> t 
  val segment_len : t->float
end;;

module ModLineSegment : LineSegment = struct
  type t = {p1:ModPoint.p;p2:ModPoint.p}
  let create_segment p1 p2 = {p1=p1;p2=p1}

  let segment_len segment = ModPoint.distance segment.p1 segment.p2
end;;


let our_segment = ModLineSegment.create_segment p1 p2;;
let segment_l = ModLineSegment.segment_len our_segment;;



(*zadanie 5*)
module type Translation = 
sig  
  type p = {x:float;y:float;z:float} 
  val create : float-> float->float -> p
  val value : p -> float*float*float
end;;

module ModTranslation : Translation = struct
  type p = {x:float ; y:float; z:float}
  let create x y z = {x;y;z}
  let value tmp = (tmp.x, tmp.y, tmp.z)
end;;

(*zadanie 6*)
module Translate_Point = functor (T : Translation)(P : Point) -> struct
  let get_translated_point point trans = P.create (point.P.x +. trans.T.x) (point.P.y +. trans.T.z) (point.P.z +. trans.T.z)
end;;

module TranslatedPoint = Translate_Point (ModTranslation) (ModPoint)

module Translate_Segment = functor (T : Translation)(L : LineSegment ) -> struct
  
  let get_translated_segment line trans =
    let point1 = ModPoint.create line.L.p1.x line.L.p1.y  line.L.p1.z in
    let point2 = ModPoint.create line.L.p2.x line.L.p2.y  line.L.p2.z in
    let trans1 = ModTranslation.create trans.T.x trans.T.y trans.T.z in
    L.create_segment  (TranslatedPoint.get_translated_point point1 trans1) (TranslatedPoint.get_translated_point point2 trans1)
end;;


let example_translation = ModTranslation.create 1.0 2.0 3.0;;
let translated_value = ModTranslation.value (ModTranslation.create 1.0 2.0 3.0);;


let translated_point_example = TranslatedPoint.get_translated_point p1 example_translation;;


module Translated_segment_example = Translate_Segment(ModTranslation)(ModLineSegment);;
let x = Translated_segment_example.get_translated_segment our_segment example_translation;;