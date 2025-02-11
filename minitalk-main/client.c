#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"

void send_bits(int pid ,char *str_msg)
{
    int i;
    int j;
    
    i = 0;
    while (str_msg[i])
    {
        j = 0;
        while(j < 8)
        {
            if ((str_msg[i] >> j) & 1)
                if (kill(pid, SIGUSR1) == -1)
                {
                    printf("Error sending SIGUSR1");
                    exit(1);
                }
            else
                if (kill(pid, SIGUSR2) == -1)
                {
                    printf("Error sending SIGUSR2");
                    exit(1);
                }
            j++;
            usleep(10000);
        }
        i++;
    }

    j = 0;
    while(j < 8)
    {
        if(kill(pid, SIGUSR2) == -1)
        {
            printf("Error sending SIGUSR1 for null terminator");
            exit(1);
        }
        j++;
        usleep(10000);
    }
}

int main (int ac ,char *av[])
{
    int     server_pid;
    char    *msg;
    if (ac != 3)
    {
        printf("Usage: %s <server_pid> <message>\n", av[0]);
        return (1);
    }
    server_pid = ft_atoi(av[1]);
    if (server_pid <= 0)
    {
        printf("Invalid PID: %d\n", server_pid);
        return (1);
    }
    msg = av[2];
    printf("Sending message to server PID %d: %s\n", server_pid, msg);
    send_bits(server_pid ,msg);

    return (0);
}