#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

struct customer {

        int hair_time;
        int flag;
        int done;
};
bool present(int num_cust[],int cust_no)
{
        for (int i = 0;i < 10; i++) {

                if (num_cust[i] == cust_no) {

                        return true;
                }
        }

        return false;
}

int main()
{
        int chairs;
        int cust;

        srand(time(NULL));

        int iter = rand()%100;
        chairs = 10;
        cust = 10;
        struct customer c[cust];

        for (int i = 0;i < cust; i++) {

                c[i].hair_time = 0;
                c[i].flag = 0;
                c[i].done = 0;
        }

        int num_cust[10];
        int tot_time = 0;
        int cur_cust;
        int process_flag  = 0;
        int count = 0;
        int b = 0;
        iter = 100;
        int temp_iter = iter;
        while (iter) {

                    int ht = rand()%5;
                    int cust_no = rand()%10;

                    if (c[cust_no].flag == 0 && c[cust_no].done != 1) {

                                c[cust_no].hair_time = ht;
                                c[cust_no].flag  = 1;
                                if (!present(num_cust,cust_no)) {

                                        num_cust[count] = cust_no;
                                        count++;
                                        cout << "Customer : " << cust_no <<"  has entered the shop\n";
                                        Sleep(100);
                                }

                                process_flag = iter;
                    }

                    if (process_flag == temp_iter) {

                                        cur_cust = cust_no;
                                        tot_time = ht;
                    }

                    if (tot_time != 0) {

                        tot_time = tot_time - 2;

                        if (tot_time <= 0) {

                                        cout << "Barber is now free\n";
                                        tot_time = 0;
                                        c[cur_cust].done = 1;
                                        cout << "He is done with customer :  " << cur_cust << endl;
                                        cur_cust = num_cust[b++];
                                        tot_time = c[cur_cust].hair_time;
                                        Sleep(100);
                        } else {

                                cout << "Barber Still busy with customer : " << cur_cust << endl;
                                Sleep(100);
                        }

                    }

                iter--;
        }

        return 0;
}
