#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int total_frames;
    printf("Enter total number of frames to send: ");
    if (scanf("%d", &total_frames) != 1 || total_frames <= 0) return 0;

    int current_frame = 1;
    int seq_no = 0;

    while (current_frame <= total_frames) {
        printf("\n[Sender] Sending Frame %d (Seq No: %d)...\n", current_frame, seq_no);

        int status;
        printf("Enter transmission result (1: ACK Received, 0: Frame/ACK Lost): ");
        scanf("%d", &status);

        if (status == 1) {
            printf("[Receiver] Frame %d received. ACK %d sent.\n", current_frame, 1 - seq_no);
            printf("[Sender] ACK %d received. Sliding window forward.\n", 1 - seq_no);
            seq_no = 1 - seq_no;
            current_frame++;
        } else {
            printf("[Receiver] Frame not received or damaged.\n");
            printf("[Sender] Timer expired for Frame %d. Retransmitting...\n", current_frame);
        }
    }

    printf("\nAll %d frames sent and acknowledged successfully.\n", total_frames);
    return 0;
}