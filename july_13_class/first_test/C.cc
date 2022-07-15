#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

struct ball_t {
    int speed;
    bool is_alive;
};

static constexpr const char * ALL_DIE = "GAME OVER";
std::vector<ball_t> g_balls;

int main() {

    int number_of_balls;

    cin >> number_of_balls;

    // Process input.
    for (int i = 0; i < number_of_balls; i++) {
        ball_t ball;
        cin >> ball.speed;
        ball.is_alive = true;
        g_balls.push_back(ball);
    }

    // Emulate hitting.
    for (int i = 0; i < g_balls.size() - 1; i++) {
        if (g_balls[i].is_alive) {
            // If the ball is still alive
            if ((std::abs(g_balls[i].speed) < std::abs(g_balls[i+1].speed)) && (g_balls[i+1].speed < 0 && g_balls[i].speed > 0)) {
                g_balls[i].is_alive = false;
            } else if ((std::abs(g_balls[i].speed) > std::abs(g_balls[i+1].speed)) && (g_balls[i+1].speed < 0 && g_balls[i].speed > 0)) {
                g_balls[i+1].is_alive = false;
            } else if ((std::abs(g_balls[i].speed) == std::abs(g_balls[i+1].speed)) && (g_balls[i+1].speed < 0 && g_balls[i].speed > 0)) {
                g_balls[i].is_alive = g_balls[i+1].is_alive = false;
            }
        } else {
            // Dead balls are no longer able to join the game.
            // They have been banned!
            continue;
        }
    }

    // The speed of livers.
    std::vector<int> livers;
    for (auto ball : g_balls) {
        if (ball.is_alive) {
            // Congratulation! The ball lives.
            livers.push_back(ball.speed);
        }
    }
    
    // Output the answer.
    if (livers.size() == 0) {
        cout << ALL_DIE << endl;
    } else {
        for (auto speed : livers) {
            cout << speed << ' ';
        }
        cout << endl;
    }

}
