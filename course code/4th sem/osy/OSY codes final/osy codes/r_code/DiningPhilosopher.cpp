#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;

struct philosopher {

        int time_quant;

};

int main()
{
        int philo;
        int time_q;
        int iter;
        srand(time(NULL));

        iter = rand()%100;
        int forks[5] ;
        struct philosopher ph[5];

        for (int i = 0;i < 5; i++) {

                forks[i] = 0;
                ph[i].time_quant = 0;
        }

        while(iter) {

                philo = rand()%5;
                time_q = rand()%10;

                if (ph[philo].time_quant == 0) {

                        ph[philo].time_quant = time_q;

                        if (philo != 0) {

                                if (forks[philo] == 0 && forks[philo-1] == 0) {

                                        cout << "Philosopher : " << philo << " has started to eat \n";
                                        forks[philo] = 1;
                                        forks[philo-1] = 1;

                                } else {

                                        cout << "Forks not available for philosopher : " << philo <<endl;
                                }

                        } else {

                                if (forks[0] == 0 && forks[4] == 0) {

                                  cout << "Philosopher : " << philo << " has started to eat \n";
                                        forks[philo] = 1;
                                        forks[philo-1] = 1;

                                } else {

                                        cout << "Forks not available for philosopher : " << philo <<endl;
                                }

                        }

                        Sleep(100);
                }  else {

                        cout << "Philosopher : " << philo << "  is Still eating \n";
                        ph[philo].time_quant -= 2;
                        Sleep(100);
                        if (ph[philo].time_quant  <= 0) {

                                ph[philo].time_quant = 0;
                                forks[philo] = 0;

                                if (philo-1 > 0) {

                                        forks[philo-1] = 0;

                                } else {

                                        forks[4] = 0;
                                }

                                cout << "Philosopher :  " << philo << "  has finished eating " << endl;
                        }
                }

                iter--;
        }

        return 0;
}
