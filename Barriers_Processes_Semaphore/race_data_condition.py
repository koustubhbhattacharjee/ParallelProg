'''data races means fighting for the same data by different threads and it gets STUCK.
---------------------------------------------------------------------
race condition occur due to timing/ordering of the program and leads to bad behavior.
They are (pun intended), mutually exclusive

Different orders of execution create different outcomes. That is called a race condition.
----------------------------------------------------------------------------------------
Heisenbug, it dissapears when you study it.

ALSO, the way OS Schedules threads can be 🚩{non-deterministic}'''

#from concurrent.futures import thread
import os
import random
import threading
import time
import queue
import pandas as pd

bags_of_chips= 1
pencil=threading.Lock()
fist_bump=threading.Barrier(10)


def cpu_work(work_units):
    x=0
    for work in range(work_units*1_000_000):
        x+=1

def shopper_one():
    global bags_of_chips
    cpu_work(1)
    ''' pencil is meant to hold the lock below

        |
        |
        |
       \_/

    so these threads are data safe and dont have data racing. But they have RACE condition.
         
    '''
    with pencil:               
        bags_of_chips*=2
        print('User1 Doubled the bag of chips')

def shopper_two():
    global bags_of_chips
    cpu_work(1)
    with pencil:
        bags_of_chips+=3
        print('User2 Added 3 bags of chips')
    fist_bump.wait()  #literally a waiting spot
if __name__=='__main__':
    shoppers=[]
    for s in range(5):
        shoppers.append(threading.Thread(target=shopper_one))
        shoppers.append(threading.Thread(target=shopper_two))
    for s in shoppers:
        s.start()
    for s in shoppers:
        s.join()
    print("we need to buy ",bags_of_chips,' bags of chips ')



    ''' 
    How to avoid such a race condition?
    -------------------------------------------------------------
    BARRIERS(huddling)

    For functions which are susceptible to a race condition, we can have a barrier in the middle which is akin to huddling.
    Remember we need to make a barrier between 🚨{ONLY those GROUPS} of threads which may have a race condition. 

    User1                    User2
      |                        |
      |                        |
      |                        |
      |                       Job1
      |                        |
      |_____(👍)Barrier(👌)____|Job1 completion
      |                        |
      |                        |
      |                        |
    Job2                       |
      |                        |
      |                        |                       
Job2  |                        |
comple|                        |
-tion |_____(👍)Barrier(👌)____|    
      |                        |
      .                        .
      .                        .
      .                        .
      (and So on..)
    
    
    
    
    '''



