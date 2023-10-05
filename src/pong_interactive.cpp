#include <ncurses.h>
#include <unistd.h>
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
void racket_move(char command, int &racket_left, int &racket_right);
void ball_moution(int &ball_x, int &ball_y, int &ball_v_x, int &ball_v_y, int &score_left, int &score_right,
                  int racket_left, int racket_right);
void congratulations(int score_left, int score_right);
void pong();

int main() {
    pong();
    RETURN;
}

void draw_window(int score_left, int score_right, int racket_left, int racket_right, int ball_x, int ball_y) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_GREEN);
    attron(COLOR_PAIR(1));
    move(0, 0);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == BOUND_TOP - 1) {
                draw_score(x, score_left, score_right);
            } else if (y == BOUND_BOT || y == BOUND_TOP) {
                printw("%c", BOUND);
            } else if ((y == racket_left || y == racket_left + 1 || y == racket_left + 2) &&
                       x == RACKET_LEFT_X) {
                printw("%c", RACKET);
            } else if ((y == racket_right || y == racket_right + 1 || y == racket_right + 2) &&
                       x == RACKET_RIGHT_X) {
                printw("%c", RACKET);
            } else if (y == ball_y && x == ball_x) {
                printw("%c", BALL);
            } else {
                printw("%c", SPACE);
            }
        }
        printw("\n");
    }
    refresh();
    attroff(COLOR_PAIR(1));
}

void draw_score(int x, int score_left, int score_right) {
    if (x == 40) {
        printw("%c", SCORE_DELIM);
    } else if (x == 38 && score_left > 9) {
        printw("%d", score_left / 10);
    } else if (x == 39 && score_left > 9) {
        printw("%d", score_left % 10);
    } else if (x == 39) {
        printw("%d", score_left);
    } else if (x == 41 && score_right > 9) {
        printw("%d", score_right / 10);
    } else if (x == 42 && score_right > 9) {
        printw("%d", score_right % 10);
    } else if (x == 41) {
        printw("%d", score_right);
    } else {
        printw("%c", SPACE);
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

void racket_move(char command, int &racket_left, int &racket_right) {
    if (command == RACKET_LEFT_UP && racket_left != BOUND_TOP + 1) {
        racket_left--;
    } else if (command == RACKET_LEFT_DOWN && racket_left != BOUND_BOT - 3) {
        racket_left++;
    } else if (command == RACKET_RIGHT_UP && racket_right != BOUND_TOP + 1) {
        racket_right--;
    } else if (command == RACKET_RIGHT_DOWN && racket_right != BOUND_BOT - 3) {
        racket_right++;
    }
}

void ball_moution(int &ball_x, int &ball_y, int &ball_v_x, int &ball_v_y, int &score_left, int &score_right,
                  int racket_left, int racket_right) {
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
    } else if ((ball_x != RACKET_RIGHT_X - 1 || ball_x != RACKET_LEFT_X + 1) && ball_y == BOUND_BOT - 1) {
        ball_v_y = -1;
        ball_y += ball_v_y;
        ball_x += ball_v_x;
    } else if ((ball_x != RACKET_RIGHT_X - 1 || ball_x != RACKET_LEFT_X + 1) && ball_y == BOUND_TOP + 1) {
        ball_v_y = 1;
        ball_y += ball_v_y;
        ball_x += ball_v_x;
    } else {
        ball_x += ball_v_x;
        ball_y += ball_v_y;
    }
}

void congratulations(int score_left, int score_right) {
    if (score_left == END_GAME) {
        printw("%65s", "Congratulations Racket Left Player! You Win!\n");
    } else if (score_right == END_GAME) {
        printw("%65s", "Congratulations Racket Right Player! You Win!\n");
    }
    refresh();
}

void pong() {
    initscr();
    noecho();
    nodelay(stdscr, 1);
    int game = TRUE, score_left = 0, score_right = 0, racket_left = RACKET_LEFT_Y,
        racket_right = RACKET_RIGHT_Y, ball_x = BALL_X, ball_y = BALL_Y, ball_v_x = 1, ball_v_y = 1;
    int speed = 80000;
    draw_window(score_left, score_right, racket_left, racket_right, ball_x, ball_y);
    while (game) {
        char command = getch();
        if ((command == RACKET_LEFT_UP || command == RACKET_LEFT_DOWN || command == RACKET_RIGHT_UP ||
             command == RACKET_RIGHT_DOWN) &&
            speed > 30000) {
            racket_move(command, racket_left, racket_right);
            speed -= 10000;
        } else if (speed < 90000) {
            speed += 10000;
        }
        ball_moution(ball_x, ball_y, ball_v_x, ball_v_y, score_left, score_right, racket_left, racket_right);
        usleep(speed);
        game = game_state(command, score_left, score_right);
        draw_window(score_left, score_right, racket_left, racket_right, ball_x, ball_y);
    }
    if (score_left == 21 || score_right == 21) {
        congratulations(score_left, score_right);
        usleep(2000000);
    }
    endwin();
}
