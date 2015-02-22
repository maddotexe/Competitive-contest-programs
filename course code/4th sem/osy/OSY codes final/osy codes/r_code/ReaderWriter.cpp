#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

struct thread {

        int read_lock ;
        int write_lock;
        int priority;
};

int main()
{
        int n;
        srand(time(NULL));

        cout << "Enter the number of threads accessing the shared memory" << endl;
        cin >> n;

        struct thread t[n];

        for (int i = 0; i < n; i++) {

                        t[i].priority = 0;
                        t[i].read_lock = 0;
                        t[i].write_lock = 0;
        }

        int m = rand()%1000;
        int global_read = 0;
        int global_write = 0;
        int pro_write = 0;
        int pro_read = 0;

        while (m) {

                int thread_no = rand()%n;

                int check = rand()%3;

                if (check == 1) {

                        if (t[thread_no].read_lock == 0) {

                                if (global_write == 0) {

                                        t[thread_no].read_lock = 1;
                                        t[thread_no].priority = 1;
                                        cout << "Process :  " << thread_no <<  " has requested a read lock and has been granted" << endl;
                                        global_read =  1;

                                } else {

                                        cout << "Process : " << thread_no << " has requested a read lock" << endl;
                                        cout << "But it cannot be granted" << endl;
                                        cout << "Write lock is held by  " << "Process : " << pro_write << endl;
                                        t[thread_no].priority += 1;
                                }

                                if (t[thread_no].priority >= 5) {

                                          cout << "Process : " << thread_no << " has obtained the read lock by priority ugrade" << endl;
                                          t[thread_no].read_lock = 1;
                                          global_write = 0;
                                          pro_write = 0;
                                          global_read = 1;
                                          t[thread_no].priority = 0;
                                }

                                Sleep(100);
                        }

                } else if (check == 2) {

                        if (global_write == 0 && global_read == 0) {

                                cout << "Process " << thread_no << " has requested a write lock\n";
                                cout <<  " It has been granted the same" << endl;
                                global_write = 1;
                                pro_write = thread_no;

                        } else if (global_write == 0 && global_read != 0) {

                                cout << "Process " << thread_no << " has requested a write lock\n";
                                cout << "But read lock is held by " << pro_read << endl;
                                t[thread_no].priority += 2;

                        }

                           if (t[thread_no].priority >= 3) {

                                cout << "Process " << thread_no << " obtained a write lock by priority upgrade" << endl;
                                global_write  = 1;
                                pro_write = thread_no;
                                global_read = 0;
                                t[thread_no].priority = 0;
                           }

                           Sleep(100);
                } else {}

                m--;
        }
        return 0;
}
