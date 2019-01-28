/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:19:46 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/07 19:59:19 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include "GamePlayer.hpp"

class Game
{

	public:
		Game(void);
		Game(int x, int y);
		Game(Game const &obj);
		virtual ~Game(void);
		Game &operator=(Game const &r);

		int checkEndgame(void);
		void drawPlayer(void);
		void drawEnemy(void);
		void getInput(int c);

		void pushMenu();

		// Spawn Entity
		void spawnEnemy(void);
		void spawnPlayer(void);

		void enemyMissile(void);


		//void spawnStars(void);
		void spawnStars(void);
		void drawStars(void);
		void clearStars(void);
		void moveStars(void);


		// STARTSS
		void spawnCanion(void);
		void drawCanion(void);
		void clearCanion(void);
		void moveCanion(void);

		void spawnMissile(void);
		// Move Enemy
		void enemyShoot();
		void moveEnemies(void);
		void moveEnemiesMissile(void);

		// Clear for Moves;
		void clearMove(void);
		void clearPlayer(void);

		void clearMoveMissile(void);
		void clearEnemyMoveMissile(void);
		// MISSILE
		void drawPlayerMissile(void);
		void movePlayerMissile(void);

		// Timer for mouvement
		int getTime(void);
		void setTime(int timer);

		int getKill(void);

		void ClearPrintEnnemi(int x, int y);
		void drawEnemyMissile(void);

	private:
		int _checkHit(int x, int y);
		int _checkPHit(int x, int y);

		int _timer;
		int _endgame;

		int _kill;
		int _input;

		int _mapx;
		int _mapy;

		IEntityPool *_stars_pools;
		AEntity *_star;


		IEntityPool *_canion_pools;
		AEntity *_canion;


		IEntityPool *_enemy_pool;
		AEntity *_enemy;

		IEntityPool *_player_pool;
		AEntity *_player;

		IEntityPool *_pool_player_missile;
		AEntity *_player_missile;


		IEntityPool *_pool_enemy_missile;
		AEntity *_enemy_missile;

		int _menu;

		int _eCount;
		// int _eBullet;
};

#endif
