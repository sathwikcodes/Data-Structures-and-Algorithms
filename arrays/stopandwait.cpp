#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FRAME_SIZE 100
#define TIMEOUT 3

typedef struct
{
    int seq_num;
    char data[FRAME_SIZE];
} Frame;

void send_frame(Frame frame)
{
    printf("Sending frame with sequence number %d\n", frame.seq_num);
}

Frame receive_frame()
{
    Frame received_frame;
    received_frame.seq_num = rand() % 2;
    return received_frame;
}

bool is_frame_corrupted(Frame frame)
{
    return rand() % 2 == 0;
}

int main()
{
    srand(time(NULL));

    Frame sender_frame, receiver_frame;
    int expected_seq_num = 0;

    while (true)
    {
        sender_frame.seq_num = expected_seq_num;
        printf("Sender: Creating frame with sequence number %d\n", sender_frame.seq_num);

        send_frame(sender_frame);
        receiver_frame = receive_frame();

        if (receiver_frame.seq_num == expected_seq_num && !is_frame_corrupted(receiver_frame))
        {
            printf("Receiver: Frame received with sequence number %d (ACK)\n", receiver_frame.seq_num);
            expected_seq_num = (expected_seq_num + 1) % 2;
        }
        else
        {
            printf("Receiver: Frame lost or corrupted, requesting retransmission\n");
        }
        sleep(1);
    }

    return 0;
}