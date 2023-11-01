#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define PI 3.1415
void circle() {
    float r, a, p;
    printf("Enter r of the circle: ");
    scanf("%f", &r);
    a = PI * r * r;
    p = 2 * PI * r;
    printf("Area of the circle = %f\n", a);
    printf("Perimeter of the circle = %f\n", p);
}
void square() {
    float s, a, p;
    printf("Enter side length of the square: ");
    scanf("%f", &s);
    a = s * s;
    p = 4 * s;
    printf("Area of the square = %f\n", a);
    printf("Perimeter of the square = %f\n", p);
}
int main() {
    // Create process for circle
    pid_t pid_c = fork();
    if (pid_c == 0) {
        circle();
        exit(0);
    } // Wait
    int status;
    waitpid(pid_c, &status, 0);
    // Create process for square
    pid_t pid_s = fork();
    if (pid_s == 0) {
        square();
        exit(0);
    }
    // Wait
    waitpid(pid_s, &status, 0);
    return 0;
}