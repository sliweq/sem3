type person = {name:string; surename:string; age:int; gender:string; shoe_size:int };;
type partnership = {p1:person; p2:person}

let pfunction (x:partnership):person = if x.p1.age > x.p2.age then x.p1 else x.p2;;


type person2 = string*string*int*string*int;;
type partnership2 = person2*person2;;

let pfuncition2 (((name1, surname1, age1, gender1, shoe_size1),(name2, surname2, age2, gender2, shoe_size2):
(string*string*int* string* int)*(string*string*int* string* int)):partnership2): string*string*int*string*int = 
  if age1 > age2 then (name1, surname1, age1, gender1, shoe_size1) else (name2, surname2, age2, gender2, shoe_size2);;