package zad2;

import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

public class Bank {
    private Account[] accounts;
    private int n;

    Bank(int n){
        this.n = n;
        accounts = new Account[n];
        Random rand = new Random();
        for(int i = 0; i < n; i++){
            accounts[i] = new Account(rand.nextInt(1000,7000), i);
        }
    }

    public int get_accouts_amount(){
        return n;
    }

    public boolean transfer(int owner, int amount, int new_owner){
        if(!accounts_exixts(new_owner) || !accounts_exixts(owner)){
            return false;
        }
        if(accounts[owner].withdraw(amount)){
            accounts[new_owner].deposit(amount);
            return true;
        }
        return false;
    }

    public boolean deposit(int owner, int amount){
        if(accounts_exixts(owner) == false){
            return false;
        }
        accounts[owner].deposit(amount);
        return true;
    }

    private boolean accounts_exixts(int id){
        for(Account acc: accounts){
            if(acc.getId() == id){
                return true;
            }
        }
        return false;
    }

    private Account get_account(int id){
        for(Account acc: accounts){
            if(acc.getId() == id){
                return acc;
            }
        }
        return null;
    }

    public boolean withdraw(int id, int amount){
        if(accounts_exixts(id) == false){
            return false;
        }
        return accounts[id].withdraw(amount);
    }

    public void print_info(){
        for(Account acc: accounts){
            System.out.println(acc.getId() + " " + acc.getBalance());
        }
    }

    public static void main(String[] args) {

        Bank bank = new Bank(10);
        Thread[] threads = new Thread[10];

        for(int i = 0; i < 10; i++){
            threads[i] = new Thread(new Client(i, bank));
        }
        Timer timer = new Timer();
        for(Thread thr: threads){
            thr.start();
        }
        timer.schedule(bank.new TimerStop(threads, timer),10000);

    }

    
    class TimerStop extends TimerTask {
        Thread[] threads;
        Timer timer;
        public TimerStop(Thread[] threads,Timer timer) {
            this.threads = threads;
            this.timer = timer;
        }

        public void run() {
            for(Thread thr: threads){
                thr.interrupt();
            }

            timer.cancel();
            for(Account acc: accounts){
                System.out.println(acc.getId() + " " + acc.getBalance());
            }
            System.exit(0);
        }
    }
}
