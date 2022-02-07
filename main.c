#include <stdlib.h>
#include <stdio.h>

int main() {

    // N for the number of cities, M for the number of drones
    int N, M;
    printf("Enter the number of cities (N): ");
    scanf("%d", &N);
    while (N < 1 || N > 100) {
        printf("\nInvalid entry! Enter a number between 1 and 100...");
        printf("\nEnter the number of cities (N): ");
        scanf("%d", &N);
    }

    printf("\nEnter the number of drones (M): ");
    scanf("%d", &M);
    while (M < 1 || M > 100) {
        printf("\nInvalid entry! Enter a number between 1 and 100...");
        printf("\nEnter the number of cities (M): ");
        scanf("%d", &M);
    }

    //let's store the drones with the current city location and the distance capability in
    //an array: every second element in the array is the distance capability and vice versa for the city
    int drones[100] = {0};
    //C for the current city and D for the distance capability
    int C, D;
    int shut = 0;
    for (int i = 0; i < 2 * M; i+=2) {
        printf("\nEnter the drone city: ");
        scanf("%d", &C);
        printf("Enter the distance capability: ");
        scanf("%d", &D);
        //check the inputs: city and distance must be between 1 and N
        if (C < 1 || C > N || D < 1 || D > N) {
            printf("\nInvalid input! Program shut down...\n");
            shut = 1;
            break;
        }
        //put the inputs into the array
        drones[i] = C;
        drones[i+1] = D;
    }

    //if the input for the drones was invalid, we shut down the program
    if (shut) {
        return 0;
    }

    printf("\nGot all the drones successfully!\n");

    for (int i = 0; i < 2*M; i += 2) {
        printf("\nDrone city: %d, Distance: %d", drones[i], drones[i+1]);
    }

    int visited[100] = {0};
    int indexer = 0;
    int size = 0;

    int city;
    int cities[100] = {0};
    for (int i = 0; i < 2*M; i += 2) {
        //check back
        city = drones[i];
        if (cities[city-1] == 0) {
            cities[city-1] = city;
            visited[indexer++] = city;
            size++;
        }
        while (city - drones[i+1] > 0) {
            if (cities[city - drones[i+1] - 1] == 0) {
                visited[indexer++] = city - drones[i+1];
                cities[city - drones[i+1] - 1] = visited[indexer-1];
                size++;
            }
            city -= drones[i+1];
        }
        city = drones[i];
        //check front
        while (city + drones[i+1] <= N) {
            if (cities[city + drones[i+1] - 1] == 0) {
                visited[indexer++] = city + drones[i+1];
                size++;
                cities[city + drones[i+1] - 1] = visited[indexer-1];
            }
            city += drones[i+1];
        }
    }

    printf("\n\nThe following cities can be visited: ");
    for (int i = 0; i < 100; i++) {
        if (visited[i] == 0) {
            break;
        }
        printf("%d ", visited[i]);
    }

    return 0;
}

