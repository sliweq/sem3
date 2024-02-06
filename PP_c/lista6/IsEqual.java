// Działanie programów z zadań 3-5 należy wyjaśniać, rysując „obrazy pamięci”  tych programów, 
// tzn. rysując referencje jako strzałki, komórki pamięci i ich zawartości jako prostokąty. Należy 
// pokazać, co znajdzie się na stosie, a co na stercie (patrz wykład 2, str. 15-16). 

// Co i dlaczego wydrukuje poniższy program w Javie

public class IsEqual{ 
  static boolean isEqual1(int m, int n){return m == n;} 
     // w tym przypadku porównujemy typy prymitywne, więc porównujemy wartości, inaczerj mówiąc porównujemy 
     // zawartości komórek pamięci, w których są przechowywane wartości

      // w tym przypadku porównujemy typy obiektowe, więc porównujemy referencje, inaczej mówiąc porównujemy
      // zawartości komórek pamięci, w których są przechowywane referencje do obiektów
  static boolean isEqual2(Integer m, Integer n){
    return m == n;
  } 
  public static void main(String[] args){ 
    System.out.println(isEqual1(500,500));  
    System.out.println(isEqual2(500,500));  

  } 
}