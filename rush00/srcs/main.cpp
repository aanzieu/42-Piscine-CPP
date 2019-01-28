/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:27:22 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 22:03:18 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GamePlayer.hpp"
#include "../includes/Game.class.hpp"
#include <unistd.h>
char getRandomChar()
{
    static char c = 'A' + rand() % 24;
    return c;
}

int game_player()
{
    int col = 0;
    int row = 0;
    getmaxyx(stdscr, col, row);
    Game *game = new Game(row - 2, col - 2);

    int key;
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);

    refresh();
    clear();
    Timer timer(clock());
    float fps = 200;

    int frame = 0;

    while (game->checkEndgame() == 1)
    {
        box(stdscr, 0, 0);
        clock_t previousFrame = clock();
        mvprintw(0, 0, "SCORE  %d", 100);
        mvprintw(col - 1, 0, "LEVEL %d | LIVES %d | TIME %d | KILLS (%d)", 1, 1, timer.getSec(clock()), game->getKill());
        
        if ((key = getch()) != ERR)
            game->getInput(key);
        while ((float)((clock() - previousFrame) / (float)CLOCKS_PER_SEC) <= (1.f / fps))
            continue;

        frame++;
         if(frame % 3 == 0)
            game->spawnStars();
        if(frame % 1 == 0){
            game->spawnCanion();
            game->movePlayerMissile();
        }
        if(frame % 2== 0){
			game->moveEnemiesMissile();
            game->moveCanion();
        }
        if(frame % 4 == 0){
            game->moveStars();
        }
        if(frame % 6 == 0)
            game->moveEnemies();
        if(frame % 15 == 0)
		{
//			game->enemyShoot();
            game->spawnEnemy();
		}
		refresh();
    }
    clear();
	return 0;
}

int main()
{

    srand(time(NULL));

    initscr(); //creates std screen
    cbreak();  //enter raw modal
    noecho();
    curs_set(0);
    while (1)
    {
        if (!game_player())
        {
            clear();
            return (0);
        };
    }
    return (0);
}
