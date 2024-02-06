package zad2;

import java.util.Random;

public class Client implements Runnable{
    private int id;
    Random rand = new Random();
    Bank bank;
 
    public Client(int id, Bank bank){
        this.id = id;        
        this.bank = bank;
    }

    public int getId(){
        return id;
    }

    @Override
    public void run() {
        while(!Thread.interrupted()){
            int operation = rand.nextInt(3);
            int amount = rand.nextInt(50,1000);
            int another_account = rand.nextInt(0, bank.get_accouts_amount()+5);
            switch (operation) {
                case 0:
                    bank.deposit(id, amount);
                    break;
                case 1:
                    bank.transfer(id, amount, another_account);
                    break;
                case 2:
                    bank.withdraw(id, amount);
                    break;
                default:
                    break;
            }
            try {
                Thread.sleep(rand.nextInt(10, 100));
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                //e.printStackTrace();
            }
        }   
    }
}