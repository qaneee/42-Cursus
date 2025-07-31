#include "minitalk.h"

void signal_handle(int signal, siginfo_t *info, void *context)
{
    static int bit = 0; // clients sends bit by bit
    static char ch = 0; // forming full symbol

    (void)context;  // same logic as (void)argv
    if (signal == SIGUSR1)  // if SIGUSR1  -> 1, if SIGUSR2 -> 0
        ch |= (1 << (7 - bit));
    bit++;
    if (bit == 8)  //fully read
    {
        if (ch == 0)
        {
            write(1,"\n", 1);
            kill(info->si_pid, SIGUSR2);
        }
        else
            write(1, &ch, 1);
        bit = 0;
        ch = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int main(int argc, char **argv)
{
    pid_t pid;
    struct sigaction sa; //Unix struct for handling signals

    (void)argv; // just ignore it, it is unused
    pid = getpid(); // assign current PID
    if (argc == 1) // => execution -> example: ./server only name is needed
    {
        if (pid <= 0) // checking if given pid is legit
            exit(write(2, "Error: PID isn't created\n", 25));
        ft_printf("Process PID: %d\n", pid);
        sa.sa_sigaction = &signal_handle;  // When signal recieved call my signal handler
        sa.sa_flags = SA_SIGINFO;   // for using sa_sigaction
        sigemptyset(&sa.sa_mask); 
        while (1)
        {
            sigaction(SIGUSR1, &sa, NULL); // For SIGUSR1 to use sa
            sigaction(SIGUSR2, &sa, NULL); // For SIGUSR2 to use sa
            pause(); //Waiting for the signa;
        }
    }
    else
        exit(write(2, "Error\n", 6));
}