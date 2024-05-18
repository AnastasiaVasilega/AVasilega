#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

const int num_philosophers = 5;
mutex forks[num_philosophers];

void philosopher(int id) {
    
    forks[id].lock();
    forks[(id + 1) % num_philosophers].lock();

    cout << "Философ " << id << " ест" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    forks[(id + 1) % num_philosophers].unlock();
    forks[id].unlock();
}


int main() {
  thread philosophers[num_philosophers];

  for (int i = 0; i < num_philosophers; i++) {
    philosophers[i] = thread(philosopher, i);
  }

  for (int i = 0; i < num_philosophers; i++) {
    philosophers[i].join();
  }

  return 0;
}