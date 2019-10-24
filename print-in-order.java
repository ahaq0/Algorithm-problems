
/*
Looked at this video for info on semaphores
Need to recall that you can acquire ( x ) x number of permits but then have to release(x)
Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().



*/
import java.util.concurrent.*;

class Foo {

    Semaphore second, third;

    public Foo() {

        second = new Semaphore(0);
        third = new Semaphore(0);
    }

    public void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.

        printFirst.run();
        second.release();

        // so we want to unlock the second thread to run following the first being
        // printed. Thus we release it.
    }

    public void second(Runnable printSecond) throws InterruptedException {

        // Use acquireUninterruptibly to avoid there being a potential exception throw
        // (happens if you just use acquire))
        second.acquireUninterruptibly();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        third.release();
    }

    public void third(Runnable printThird) throws InterruptedException {

        // printThird.run() outputs "third". Do not change or remove this line.
        third.acquireUninterruptibly();
        printThird.run();
    }
}