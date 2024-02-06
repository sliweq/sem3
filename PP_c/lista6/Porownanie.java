public class Porownanie{ 
    public static void main(String[] args){ 
      String s1 = "foo"; 
      String s2 = "foo"; 
      //aliasowanie s1 i s2 - obie zmienne wskazują na ten sam obiekt
      System.out.println(s1 == s2); 
      System.out.println(s1.equals(s2)); 
      String s3 = new String("foo");   
      System.out.println(s1 == s3);  //referencje wsakzuja na różne obiekty w pamięci
      System.out.println(s1.equals(s3));  
    } 
}