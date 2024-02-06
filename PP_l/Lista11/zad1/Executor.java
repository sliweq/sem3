package zad1;

import java.util.Random;
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;

public class Executor {
    Thread[] threads;
    int n;
    int time;

    public Executor() {
        Scanner scanner = new Scanner(System.in);
        n = get_number_n(scanner);
        time = get_time(scanner);
        scanner.close();

        threads = new Thread[n];
        Random rand_seed = new Random();
        int pos = 0;
        int neg = 0;
        for(int i = 0; i < n; i++){
            Increaser tmp = new Increaser(rand_seed);
            if(tmp.get_increase() == 1){
                pos++;
            }else{
                neg++;
            }
            threads[i] = new Thread(tmp);
        }
        System.out.println("Increasers:" + pos + " Decreasers:" + neg);
    }

    public int get_number_n(Scanner scanner) {

        System.out.println("Enter number:");
        int input_number = scanner.nextInt();
        while(input_number <= 0){
            System.out.println("Enter  positive numebr:");
            input_number = scanner.nextInt();
        }
        return input_number;
    }
    public int get_time(Scanner scanner) {
        System.out.println("Enter time (s):");
        int input_number = scanner.nextInt();
        while (input_number <= 0 || input_number > 1000) {
            System.out.println("Time must be positive and not too big:");
            input_number = scanner.nextInt();
        }
        return input_number*1000;
    }

    void start_multithreading() {

        Timer timer = new Timer();
        for(Thread thr: threads){
            thr.start();
        }
        timer.schedule(new TimerStop(threads, timer), time);

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
            System.out.println("Result: " + Main.tmp_number);
            timer.cancel();
        }
    }
}
