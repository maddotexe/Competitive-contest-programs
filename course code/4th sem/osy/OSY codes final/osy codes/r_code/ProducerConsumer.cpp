#include  <iostream>
#include  <cstdlib>
#include  <cmath>
#include <ctime>
#include <cstdio>
#include <windows.h>

using namespace std;

int current_size = 0;

void consume()
{
        current_size -= 1;
       Sleep(100);
}

void produce()
{
        current_size += 1;
       Sleep(100);
}

int main()
{

        srand(time(NULL));

        int buffer_size;

        cout  <<  "Enter the buffer_size : " << endl;

        cin >> buffer_size;

        int m = rand()%100;

        for (int i = 1; i < m; i++) {

                int k = rand()%10;

                if (k >= 0 && k <= 5) {

                        produce();

                        if (current_size >= buffer_size) {

                                cout << "The Buffer is full\n";
                                cout << "The producer is put to sleep\n";

                                goto con;
                        }

                        cout << "Current Buffer Size is : " << current_size << endl;

                } else {
                                con:

                                if (current_size == 0) {

                                        cout << "The Buffer is empty\n " ;
                                        cout << "The consumer is put to sleep\n";
                                        continue;
                                }

                                consume();
                                cout << "Current Buffer Size is : " << current_size << endl;
                }

        }
        
        return 0;
}

