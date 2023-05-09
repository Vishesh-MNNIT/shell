#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 1024

struct message {
    long type;
    char data[MSG_SIZE];
};

int main(int argc, char *argv[])
{
    key_t key;
    int msqid;
    struct message msg;

    // Generate a key for the message queue
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a message queue with the generated key
    if ((msqid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Write a message to the message queue
    msg.type = 1;
    strcpy(msg.data, "Hello, World!");
    if (msgsnd(msqid, &msg, sizeof(msg.data), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    // Read a message from the message queue
    if (msgrcv(msqid, &msg, sizeof(msg.data), 0, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    // Print the received message
    printf("Received message: %s\n", msg.data);

    // Delete the message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
