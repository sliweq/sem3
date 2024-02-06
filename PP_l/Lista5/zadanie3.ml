type weekDay = 
| Monday 
| Tuesday 
| Wednesday 
| Thursday 
| Friday 
| Saturday 
| Sunday ;;

let weekDayToString day = 
  match day with 
  | Monday -> "Poniedziałek"
  | Tuesday -> "Wtorek"
  | Wednesday -> "Środa"
  | Thursday -> "Czwartek"
  | Friday -> "Piątek"
  | Saturday -> "Sobota"
  | Sunday -> "Niedziela;";;

let nextDay x =
  match x with
  | Monday -> Tuesday
  | Tuesday -> Wednesday
  | Wednesday -> Thursday
  | Thursday -> Friday 
  | Friday -> Saturday 
  | Saturday -> Sunday
  | Sunday -> Monday ;;

let x = Monday;;
weekDayToString x;;
nextDay x;;