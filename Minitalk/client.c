#include "minitalk.h"

int g_ack;

int ft_atoi(char *str)
{
    int number;
    int sign;

    number = 0;
    sign = 1;
    while ((*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    if (*str == '+')
        str++;
    else if(*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        number = number * 10 + (*str - '0');
        str++;
    }
    return (number * sign);
}

void get_ack(int sig, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;
    if (sig == SIGUSR1)
        g_ack = 1;
    if (sig == SIGUSR2)
        write(1, "Message received\n", 17);
}

void send_char(int pid, char c)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i--;
        while (g_ack == 0)
            pause();
        g_ack = 0;
    }
}

int main(int argc, char **argv)
{
    int pid;
    char *message;
    struct sigaction sa;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        message = argv[2];
        sa.sa_sigaction = get_ack;
        sa.sa_flags = SA_SIGINFO;
        sigemptyset(&sa.sa_mask); 
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        while (*message)
            send_char(pid, *message++);
        send_char(pid, '\0');
    }
    else
    {
        ft_printf("%s","Invalid argument count\n");
        exit (1);
    }
    return (0);
}