#include<iostream>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
#include<sys/shm.h>
#include<thread>
#include<atomic>
using namespace std;

atomic<bool> exit_flag(false);

void input_thread() {
    string input;
    while (true) {
        getline(cin, input);
        if (input == "0") {
            exit_flag = true;
            break;
        }
    }
}

int main()
{
    int *shared_memory;
    int shmid;
    shmid = shmget((key_t)1122, sizeof(int), 0666);

    shared_memory = (int*)shmat(shmid, NULL, 0);
    int new_data = *shared_memory - 30;
    *shared_memory = new_data;

    if (shmdt(shared_memory) == -1) {
        perror("shmdt error");
        exit(1);
    }

    thread t(input_thread); // Launch a thread to handle user input

    int sec_prev = -1;

    while (!exit_flag)
    {
        int seconds, minutes, hours;
        string str;

        time_t total_seconds = time(0);
        struct tm* ct = localtime(&total_seconds);

        seconds = ct->tm_sec;
        minutes = ct->tm_min;
        hours = ct->tm_hour;

        str = (hours >= 12) ? "PM" : "AM";
        hours = hours > 12 ? hours - 12 : hours;

        if (seconds == sec_prev + 1 || (sec_prev == 59 && seconds == 0) || sec_prev == -1)
        {
            system("clear");
            cout << "\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
            cout << "\t\t\tWELCOME TO DIGITAL CLOCK SYSTEM!" << endl;
            cout << "\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
            cout << "\t\t\t\t" << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str << endl;
            cout << "\n\t\t\tPress 0 to exit: ";
            cout.flush();
        }

        sec_prev = seconds;
        usleep(100000); // Small delay to reduce CPU usage
    }

    t.join(); // Wait for input thread to finish
    cout << "\nExited clock system." << endl;
    return 0;
}

