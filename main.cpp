/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <thread>
#include "thread_safe.h"
#include <iostream>
#include <chrono>
using namespace std;

class A
{
public:
  A (int index)
  {
    index_ = index;
  };
  virtual ~ A ()
  {
  };
  int GetIndex ()
  {
    return index_;
  };
  int index_;
};

int
main ()
{

  threadsafe_queue < A > obj_queue;
  thread *th_v[10];
  for (int i = 0; i < 10; i++)
    {

      th_v[i] = new thread ([&obj_queue] (int index)
			    {
			    while (1)
			    {
			    auto obj_a = obj_queue.wait_and_pop ();
			    printf("thread %d get %d \n", index, obj_a->GetIndex());
			    this_thread::sleep_for(chrono::seconds(1));
			    };
			      
			    }, i);

    }

  for (int j = 0; j < 30; j++)
    {
      A a (j);
      obj_queue.push (a);
    }

  getchar();
  return 0;
}
