#include <iostream>
using namespace std;
#define RETURN return 0
#define WIDTH 80
#define HEIGHT 28
#define RACKET_LEFT_X 1
#define RACKET_RIGHT_X 78
#define RACKET_LEFT_Y 13
#define RACKET_RIGHT_Y 13
#define SPACE ' '
#define RACKET '|'
#define BALL '*'
#define BALL_X 40
#define BALL_Y 14
#define BOUND_TOP 1
#define BOUND_BOT 27
#define BOUND '-'
#define SCORE_DELIM ':'
#define RACKET_LEFT_UP 'a'
#define RACKET_LEFT_DOWN 'z'
#define RACKET_RIGHT_UP 'k'
#define RACKET_RIGHT_DOWN 'm'
#define TRUE 1
#define FALSE 0
#define END_GAME 21

void draw_window(int score_left, int score_right, int racket_left, int racket_right, int ball_x, int ball_y);
void draw_score(int x, int score_left, int score_right);
int game_state(int score_left, int score_rigt);

int main() {
    int game = TRUE, score_left = 0, score_right = 0, racket_left = RACKET_LEFT_Y,
        racket_right = RACKET_RIGHT_Y;
    draw_window(score_left, score_right, racket_left, racket_right, BALL_X, BALL_Y);
    while (game) {
        char command = getchar();
        if (command == SPACE) {
            score_left++;
            score_right++;
        } else if (command == RACKET_LEFT_UP && racket_left != BOUND_TOP + 1) {
            racket_left--;
        } else if (command == RACKET_LEFT_DOWN && racket_left != BOUND_BOT - 3) {
            racket_left++;
        } else if (command == RACKET_RIGHT_UP && racket_right != BOUND_TOP + 1) {
            racket_right--;
        } else if (command == RACKET_RIGHT_DOWN && racket_right != BOUND_BOT - 3) {
            racket_right++;
        }
        game = game_state(score_left, score_right);
        draw_window(score_left, score_right, racket_left, racket_right, BALL_X, BALL_Y);
    }
    RETURN;
}

void draw_window(int score_left, int score_right, int racket_left, int racket_right, int ball_x, int ball_y) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == BOUND_TOP - 1) {
                draw_score(x, score_left, score_right);
            } else if (y == BOUND_BOT || y == BOUND_TOP) {
                cout << BOUND;
            } else if ((y == racket_left || y == racket_left + 1 || y == racket_left + 2) &&
                       x == RACKET_LEFT_X) {
                cout << RACKET;
            } else if ((y == racket_right || y == racket_right + 1 || y == racket_right + 2) &&
                       x == RACKET_RIGHT_X) {
                cout << RACKET;
            } else if (y == ball_y && x == ball_x) {
                cout << BALL;
            } else {
                cout << SPACE;
            }
        }
        cout << endl;
    }
}

void draw_score(int x, int score_left, int score_right) {
    if (x == 40) {
        cout << SCORE_DELIM;
    } else if (x == 38 && score_left > 9) {
        cout << score_left / 10;
    } else if (x == 39 && score_left > 9) {
        cout << score_left % 10;
    } else if (x == 39) {
        cout << score_left;
    } else if (x == 41 && score_right > 9) {
        cout << score_left / 10;
    } else if (x == 42 && score_right > 9) {
        cout << score_right % 10;
    } else if (x == 41) {
        cout << score_right;
    } else {
        cout << SPACE;
    }
}

int game_state(int score_left, int score_rigt) {
    int game = TRUE;
    if (score_left == END_GAME || score_rigt == END_GAME) {
        game = FALSE;
    }
    return game;
}