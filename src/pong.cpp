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
#define END_COMMAND 'q'
#define TRUE 1
#define FALSE 0
#define END_GAME 21

void draw_window(int score_left, int score_right, int racket_left, int racket_right, int ball_x, int ball_y);
void draw_score(int x, int score_left, int score_right);
int game_state(char command, int score_left, int score_right);
void congratulations(int score_left, int score_right);
void pong();

int main() {
    pong();
    RETURN;
}

void draw_window(int score_left, int score_right, int racket_left, int racket_right, int ball_x, int ball_y) {
    cout << "\033[2J\033[H";
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
        cout << score_right / 10;
    } else if (x == 42 && score_right > 9) {
        cout << score_right % 10;
    } else if (x == 41) {
        cout << score_right;
    } else {
        cout << SPACE;
    }
}

int game_state(char command, int score_left, int score_right) {
    int game = TRUE;
    if (score_left == END_GAME || score_right == END_GAME) {
        game = FALSE;
    } else if (command == END_COMMAND) {
        game = FALSE;
    }
    return game;
}

void congratulations(int score_left, int score_right) {
    cout << "\033[2J\033[H";
    if (score_left == END_GAME) {
        cout << "Congratulations Racket Left Player! You Win!" << endl;
    } else if (score_right == END_GAME) {
        cout << "Congratulations Racket Right Player! You Win!" << endl;
    }
}

void pong() {
    int game = TRUE, score_left = 0, score_right = 11, racket_left = RACKET_LEFT_Y,
        racket_right = RACKET_RIGHT_Y, ball_x = BALL_X, ball_y = BALL_Y, ball_v_x = 1, ball_v_y = 1;
    draw_window(score_left, score_right, racket_left, racket_right, ball_x, ball_y);
    while (game) {
        char command = getchar();
        if (command == SPACE) {
            if (ball_x > RACKET_RIGHT_X) {
                score_left++;
                ball_x = BALL_X;
                ball_y = BALL_Y;
            } else if (ball_x < RACKET_LEFT_X) {
                score_right++;
                ball_x = BALL_X;
                ball_y = BALL_Y;
            } else if (ball_x == RACKET_RIGHT_X - 1 &&
                       (ball_y == racket_right || ball_y == racket_right + 1 || ball_y == racket_right + 2)) {
                ball_v_x = -1;
                ball_x += ball_v_x;
                ball_y += ball_v_y;
            } else if (ball_x == RACKET_LEFT_X + 1 &&
                       (ball_y == racket_left || ball_y == racket_left + 1 || ball_y == racket_left + 2)) {
                ball_v_x = 1;
                ball_x += ball_v_x;
                ball_y += ball_v_y;
            } else if ((ball_x != RACKET_RIGHT_X - 1 || ball_x != RACKET_LEFT_X + 1) &&
                       ball_y == BOUND_BOT - 1) {
                ball_v_y = -1;
                ball_y += ball_v_y;
                ball_x += ball_v_x;
            } else if ((ball_x != RACKET_RIGHT_X - 1 || ball_x != RACKET_LEFT_X + 1) &&
                       ball_y == BOUND_TOP + 1) {
                ball_v_y = 1;
                ball_y += ball_v_y;
                ball_x += ball_v_x;
            } else {
                ball_x += ball_v_x;
                ball_y += ball_v_y;
            }
        } else if (command == RACKET_LEFT_UP && racket_left != BOUND_TOP + 1) {
            racket_left--;
        } else if (command == RACKET_LEFT_DOWN && racket_left != BOUND_BOT - 3) {
            racket_left++;
        } else if (command == RACKET_RIGHT_UP && racket_right != BOUND_TOP + 1) {
            racket_right--;
        } else if (command == RACKET_RIGHT_DOWN && racket_right != BOUND_BOT - 3) {
            racket_right++;
        }
        game = game_state(command, score_left, score_right);
        draw_window(score_left, score_right, racket_left, racket_right, ball_x, ball_y);
    }
    congratulations(score_left, score_right);
}