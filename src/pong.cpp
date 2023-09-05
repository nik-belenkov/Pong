#include <iostream>
using namespace std;
#define RETURN return 0
#define WIDTH 80
#define HEIGHT 27
#define RACKET_LEFT_X 1
#define RACKET_RIGHT_X 78
#define RACKET_LEFT_Y 12
#define RACKET_RIGHT_Y 12
#define SPACE ' '
#define RACKET '|'
#define BALL '*'
#define BALL_X 40
#define BALL_Y 13
#define BOUND_TOP 0
#define BOUND_BOT 26
#define BOUND '-'
#define RACKET_LEFT_UP 'a'
#define RACKET_LEFT_DOWN 'z'
#define RACKET_RIGHT_UP 'k'
#define RACKET_RIGHT_DOWN 'm'
#define TRUE 1

void draw_window(int racket_left, int racket_right, int ball_x, int ball_y);

int main () {
    draw_window(RACKET_LEFT_Y, RACKET_RIGHT_Y, BALL_X, BALL_Y);
    RETURN;
}

void draw_window(int racket_left, int racket_right, int ball_x, int ball_y) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == BOUND_TOP || y == BOUND_BOT) {
                cout << BOUND;
            }
            else if ((y == racket_left || y == racket_left + 1 || y == racket_left + 2) && x == RACKET_LEFT_X) {
                cout << RACKET;
            }
            else if ((y == racket_right || y == racket_right + 1 || y == racket_right + 2) && x == RACKET_RIGHT_X) {
                cout << RACKET;
            }
            else if (y == ball_y && x == ball_x) {
                cout << BALL;
            }
            else {
                cout << SPACE;
            }
        }
        cout << endl;
    }
}