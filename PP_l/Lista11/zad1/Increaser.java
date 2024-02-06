package zad1;
import java.util.Random;

class Increaser implements Runnable {
    private int increase;

    public Increaser(Random rand_seed) {
        int tmp = rand_seed.nextInt(2);
        if(tmp == 0){
            increase = -1;
        }else{
            increase = 1;
        }
    }

    public int get_increase() {
        return increase;
    }

    public void run() {
        while (!Thread.interrupted()) {
            increase_number();  
        }
    }

    private synchronized void increase_number(){
        Main.tmp_number += increase;
    }

}