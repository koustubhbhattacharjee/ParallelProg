from concurrent.futures import thread
import multiprocessing as mp

''' Semaphore 
--------------------------------------------
Mutex can be ONLY released by the thread acquiring it
Semaphores can be released by ANY thread.



'''
import random
import threading
import time

charger=threading.Semaphore(4)

def cellphone():
    name1 = threading.current_thread().name
    charger.acquire()
    print(name1,'is charging...')
    time.sleep(random.uniform(1,2))
    print(name1,'is DONE charging')
    charger.release()

if __name__== '__main__':
    for phone in range(10):
        threading.Thread(target=cellphone, name='Cellphone '+str(phone)).start()
