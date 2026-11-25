#include <stdio.h>

int main() {
    int total_frames, window_size;
    printf("Enter total number of frames to send: ");
    scanf("%d", &total_frames);
    printf("Enter Sender Window Size (N): ");
    scanf("%d", &window_size);

    int base = 1;
    int transmissions = 0;

    while (base <= total_frames) {
        int end = base + window_size - 1;
        if (end > total_frames) end = total_frames;

        printf("\n--- Current Window [%d to %d] ---\n", base, end);
        for (int i = base; i <= end; i++) {
            printf("[Sender] Transmitting Frame %d\n", i);
            transmissions++;
        }

        int lost_frame;
        printf("Enter first lost frame in this window (Enter 0 if all delivered successfully): ");
        scanf("%d", &lost_frame);

        if (lost_frame == 0 || lost_frame > end || lost_frame < base) {
            printf("[Receiver] All frames up to %d received. Cumulative ACK %d sent.\n", end, end + 1);
            base = end + 1;
        } else {
            printf("[Receiver] Frame %d lost! Discarding subsequent frames in window.\n", lost_frame);
            printf("[Sender] Timeout! Going back to Frame %d.\n", lost_frame);
            base = lost_frame;
        }
    }

    printf("\nTransmission complete. Total transmissions (including retransmits): %d\n", transmissions);
    return 0;
}