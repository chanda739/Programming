class Foo {
    private Semaphore forOne;
    private Semaphore forTwo;
    private Semaphore forThird;
    public Foo() {
        this.forOne = new Semaphore(1);
        this.forTwo = new Semaphore(0);
        this.forThird = new Semaphore(0);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        forOne.acquire();
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        forTwo.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        forTwo.acquire();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
         forThird.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        forThird.acquire();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}