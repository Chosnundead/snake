#include <iostream>
#include <conio.h>
#include <ctime>
#include <chrono>

using namespace std;

#define FIELD_SIZE 21
#define UP 8
#define RIGHT 6
#define BOTTOM 2
#define LEFT 4
#define VOID -1
#define WALL -37
#define SNAKE -3
#define APPLE 15

class head {
public:
    short int positionX;
    short int positionY;
    short int lastPositionX;
    short int lastPositionY;
    short int lastMove;
    short int view;
    char value;
    char input;
    short int** body = new short int* [(FIELD_SIZE * FIELD_SIZE)];
    short int score;

    head(char (*field)[FIELD_SIZE]) {
        value = SNAKE;
        positionX = FIELD_SIZE / 2;
        positionY = FIELD_SIZE / 2;
        lastMove = BOTTOM;
        view = BOTTOM;
        input = NULL;
        score = 0;
        for (int i = 0; i < (FIELD_SIZE * FIELD_SIZE); i++) {
            body[i] = new short int[5];
        }

        for (int i = 0; i < (FIELD_SIZE * FIELD_SIZE); i++) {
            for (int j = 0; j < 5; j++) {
                body[i][j] = 0;
            }
        }

        field[positionY][positionX] = value;
    }

    void _goUp(char (*field)[FIELD_SIZE]) {
        if (lastMove != BOTTOM) {
            lastPositionX = positionX;
            lastPositionY = positionY;
            positionY -= 1;
            lastMove = UP;
            field[lastPositionY][lastPositionX] = VOID;
            field[positionY][positionX] = value;
            if (score) {
                for (int i = 0; i < score; i++) {
                    if (body[i][0]) {
                        if (i) {
                            body[i][3] = body[i][1];
                            body[i][4] = body[i][2];
                            field[(body[i][2])][(body[i][1])] = VOID;
                            body[i][1] = body[(i - 1)][3];
                            body[i][2] = body[(i - 1)][4];
                            field[(body[i][2])][(body[i][1])] = value;
                        }
                        else {
                            body[i][3] = body[i][1];
                            body[i][4] = body[i][2];
                            field[(body[i][2])][(body[i][1])] = VOID;
                            body[i][1] = lastPositionX;
                            body[i][2] = lastPositionY;
                            field[(body[i][2])][(body[i][1])] = value;
                        }
                    }
                }
            }
        } else {
            _goBottom(field);
        }
    }

    void _goRight(char(*field)[FIELD_SIZE]) {
        if (lastMove != LEFT) {
            lastPositionX = positionX;
            lastPositionY = positionY;
            positionX += 1;
            lastMove = RIGHT;
            field[lastPositionY][lastPositionX] = VOID;
            field[positionY][positionX] = value;
            if (score) {
                for (int i = 0; i < score; i++) {
                    if (body[i][0]) {
                        if (i) {
                            body[i][3] = body[i][1];
                            body[i][4] = body[i][2];
                            field[(body[i][2])][(body[i][1])] = VOID;
                            body[i][1] = body[(i - 1)][3];
                            body[i][2] = body[(i - 1)][4];
                            field[(body[i][2])][(body[i][1])] = value;
                        }
                        else {
                            body[i][3] = body[i][1];
                            body[i][4] = body[i][2];
                            field[(body[i][2])][(body[i][1])] = VOID;
                            body[i][1] = lastPositionX;
                            body[i][2] = lastPositionY;
                            field[(body[i][2])][(body[i][1])] = value;
                        }
                    }
                }
            }
        } else { 
            _goLeft(field);
        }
    }

    void _goBottom(char(*field)[FIELD_SIZE]) {
        if (lastMove != UP) {
            lastPositionX = positionX;
            lastPositionY = positionY;
            positionY += 1;
            lastMove = BOTTOM;
            field[lastPositionY][lastPositionX] = VOID;
            field[positionY][positionX] = value;
            if (score) {
                for (int i = 0; i < score; i++) {
                    if (body[i][0]) {
                        if (i) {
                            body[i][3] = body[i][1];
                            body[i][4] = body[i][2];
                            field[(body[i][2])][(body[i][1])] = VOID;
                            body[i][1] = body[(i - 1)][3];
                            body[i][2] = body[(i - 1)][4];
                            field[(body[i][2])][(body[i][1])] = value;
                        }
                        else {
                            body[i][3] = body[i][1];
                            body[i][4] = body[i][2];
                            field[(body[i][2])][(body[i][1])] = VOID;
                            body[i][1] = lastPositionX;
                            body[i][2] = lastPositionY;
                            field[(body[i][2])][(body[i][1])] = value;
                        }
                    }
                }
            }
        } else { 
            _goUp(field);
        }
    }

    void _goLeft(char(*field)[FIELD_SIZE]) {
        if (lastMove != RIGHT) {
            lastPositionX = positionX;
            lastPositionY = positionY;
            positionX -= 1;
            lastMove = LEFT;
            field[lastPositionY][lastPositionX] = VOID;
            field[positionY][positionX] = value;
            if (score) {
                for (int i = 0; i < score; i++) {
                    if (body[i][0]) {
                        if (i) {
                            body[i][3] = body[i][1];
                            body[i][4] = body[i][2];
                            field[(body[i][2])][(body[i][1])] = VOID;
                            body[i][1] = body[(i - 1)][3];
                            body[i][2] = body[(i - 1)][4];
                            field[(body[i][2])][(body[i][1])] = value;
                        }
                        else {
                            body[i][3] = body[i][1];
                            body[i][4] = body[i][2];
                            field[(body[i][2])][(body[i][1])] = VOID;
                            body[i][1] = lastPositionX;
                            body[i][2] = lastPositionY;
                            field[(body[i][2])][(body[i][1])] = value;
                        }
                    }
                }
            }
            /*if (score) {
                for
            }*/
        } else { 
            _goRight(field);
        }
    }
};

class apple {
public:
    short int positionX;
    short int positionY;
    short int checkNewPositionX;
    short int checkNewPositionY;
    char value;

    void _appleNewPosition(char (*field)[FIELD_SIZE]) {
        bool isntBreak;

        do {
            checkNewPositionX = rand() % FIELD_SIZE;
            checkNewPositionY = rand() % FIELD_SIZE;

            if (field[checkNewPositionY][checkNewPositionX] == VOID) {
                isntBreak = false;
            } else {
                isntBreak = true;
            }
        } while (isntBreak);

        positionX = checkNewPositionX;
        positionY = checkNewPositionY;

        field[positionY][positionX] = value;
    }

    bool _appleCheck(char (*field)[FIELD_SIZE]) {
        bool isApple = false;

        for (int i = 0; i < FIELD_SIZE; i++) {
            for (int j = 0; j < FIELD_SIZE; j++) {
                if (field[i][j] == APPLE) {
                    isApple = true;
                }
            }
        }

        if (!(isApple)) {
            _appleNewPosition(field);
            return true;
        } else {
            return false;
        }
    }

    apple(char (*field)[FIELD_SIZE]) {
        value = APPLE;
        _appleNewPosition(field);
    }
};

void _frame(char(*field)[FIELD_SIZE]) {
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            cout << field[i][j];
        }
        cout << "\n";
    }
}

void _asciiTable() {
    char symbol = -128;
    while (symbol <= 127) {
        cout << (int)symbol << ": " << symbol << endl;
        symbol++;
        if (symbol == 127) {
            break;
        }
    }
}

bool _loseCheck(char(*field)[FIELD_SIZE], int score) {
    int check = 0;
    int checkWall = 0;
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (field[i][j] == SNAKE) {
                check++;
            }
            if (field[i][j] == WALL) {
                checkWall++;
            }
        }
    }
    if ((check == (score + 1)) && (checkWall == ((FIELD_SIZE * 4) - 4))) {
        return false;
    } else { 
        return true;
    }
}

int main() {
    system("cls");
    srand(time(0));

    char field[FIELD_SIZE][FIELD_SIZE];
    auto timeCheck = chrono::system_clock::now();
    auto timeCheck2 = chrono::system_clock::now();

    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if ((i == 0) || (i == (FIELD_SIZE - 1)) || (j == 0) || (j == (FIELD_SIZE - 1))) {
                field[i][j] = WALL;
            } else {
                field[i][j] = VOID;
            }
        }
    }

    head head(field);
    apple apple(field);
    for (int i = 0; i < (FIELD_SIZE * FIELD_SIZE); i++) {
        for (int j = 0; j < 5; j++) {
            head.body[i][j] = false;
        }
    }

    timeCheck = chrono::system_clock::now();
    do {
        system("cls");

        _frame(field);

        if (_kbhit()) {
            head.input = _getch();
        }

        if (abs(chrono::duration_cast<chrono::milliseconds>(timeCheck - timeCheck2).count()) < true) {
            switch (head.input) {
            case 72:
                head._goUp(field);
                break;
            case 77:
                head._goRight(field);
                break;
            case 80:
                head._goBottom(field);
                break;
            case 75:
                head._goLeft(field);
                break;
            }
            timeCheck2 = chrono::system_clock::now();
        }

        if (_loseCheck(field, head.score)) {
            break;
        }

        if (apple._appleCheck(field)) {
            if (head.score == 0) {
                head.body[head.score][0] = true;
                head.body[head.score][1] = head.lastPositionX;
                head.body[head.score][2] = head.lastPositionY;
                field[(head.body[head.score][2])][(head.body[head.score][1])] = head.value;
            } else {
                head.body[head.score][0] = true;
                head.body[head.score][1] = head.body[(head.score - 1)][3];
                head.body[head.score][2] = head.body[(head.score - 1)][4];
                field[(head.body[head.score][2])][(head.body[head.score][1])] = head.value;
            }
            head.score++;
        }
        timeCheck = chrono::system_clock::now();
    } while (true);
    
    system("cls");
    cout << "Your score: " << head.score << endl;

    system("pause");
    return 0;
}