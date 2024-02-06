package zad2;

import java.util.Random;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Account{
    private int max_withdraw = 1000;
    private int balance;
    private int id;
    private Lock lock = new ReentrantLock();
    Random rand = new Random();
 
    public Account(int balance, int id){
        this.balance = balance;
        this.id = id;        
    }
    public int getBalance(){
        return balance;
    }
    public int getId(){
        return id;
    }
    public boolean withdraw(int amount){
        lock.lock();
        try {
            if (amount > max_withdraw || amount > balance){
                return false;
            }
            balance -= amount;
            return true;
        } finally {
            lock.unlock();
        }
    }
    public void deposit(int amount){
        lock.lock();
        try{
            balance += amount;
        }finally{
            lock.unlock();
        }
    }
    public int get_max_withdraw(){
        return max_withdraw;
    }
}
