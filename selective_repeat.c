#include <stdio.h>
#include <stdbool.h>

int main() {
    int total_frames, window_size;
    printf("Enter total number of frames to send: ");
    scanf("%d", &total_frames);
    printf("Enter Window Size: ");
    scanf("%d", &window_size);

    bool acked[100] = {false};
    int base = 1;
    int transmissions = 0;

    while (base <= total_frames) {
        int end = base + window_size - 1;
        if (end > total_frames) end = total_frames;

        printf("\n--- Active Window [%d to %d] ---\n", base, end);
        for (int i = base; i <= end; i++) {
            if (!acked[i]) {
                printf("[Sender] Transmitting Frame %d\n", i);
                transmissions++;
            }
        }

        for (int i = base; i <= end; i++) {
            if (!acked[i]) {
                int status;
                printf("Did Frame %d arrive successfully? (1: Yes, 0: No): ", i);
                scanf("%d", &status);

                if (status == 1) {
                    acked[i] = true;
                    printf("[Receiver] Frame %d accepted and buffered.\n", i);
                } else {
                    printf("[Receiver] Frame %d dropped. Negative ACK (NAK) generated.\n", i);
                }
            }
        }

        // Slide the base forward across contiguous acknowledged frames
        while (base <= total_frames && acked[base]) {
            base++;
        }
    }

    printf("\nAll frames delivered. Total frame transmissions: %d\n", transmissions);
    return 0;
}