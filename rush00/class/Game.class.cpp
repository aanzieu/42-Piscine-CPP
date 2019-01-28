/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:41:01 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/07 22:04:25 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Game.class.hpp"

Game::Game(int x, int y) : _endgame(1), _mapx(x), _mapy(y), _menu(0)
{
	this->_eCount = 8;
	this->_enemy_pool = new EntityPool();
	this->_stars_pools = new EntityPool();
	this->_canion_pools = new EntityPool();
	this->_pool_player_missile = new EntityPool();
	this->_pool_enemy_missile = new EntityPool();
	this->_kill = 0;
	spawnEnemy();
	spawnPlayer();
}

Game::Game(void)
{
	return;
}

Game::Game(Game const &src)
{
	*this = src;
	return;
}

Game::~Game(void)
{
	return;
}

Game &Game::operator=(Game const &r)
{
	this->_endgame = r._endgame;
	return (*this);
}

void Game::spawnEnemy(void)
{
	struct position pos;
	pos.y = 0;
	pos.x = 2 + (rand() % (_mapx - 4));

	for (int i = 0; i < this->_enemy_pool->getCount(); ++i)
	{
		AEntity *curr = this->_enemy_pool->getUnit(i);
		if (!curr->getHP())
		{
			curr->setPosition(pos.y, pos.x);
			curr->setHP(1);
			drawEnemy();
			return ;
		}
	}
	AEntity *next;
	next = new Enemy;

	next->setPosition(pos.y, pos.x);
	next->setHP(1);
	this->_enemy_pool->push(next);
	drawEnemy();
}

void Game::drawEnemy(void)
{
	for (int i = 0; i < this->_enemy_pool->getCount(); ++i)
	{
		AEntity *curr = this->_enemy_pool->getUnit(i);
		if (curr->getHP())
		{
			attron(COLOR_PAIR(5));
			mvaddch(curr->getPosition().y, curr->getPosition().x, '@');
			mvaddch(curr->getPosition().y, curr->getPosition().x - 1, '-');
			mvaddch(curr->getPosition().y, curr->getPosition().x - 2, '\\');
			mvaddch(curr->getPosition().y, curr->getPosition().x + 1, '-');
			mvaddch(curr->getPosition().y, curr->getPosition().x + 2, '/');
			attroff(COLOR_PAIR(5));
		}
	}
}

void Game::moveEnemies(void)
{
	int timer = this->_timer;
	clearMove();
	for (int i = 0; i < this->_enemy_pool->getCount(); ++i)
	{
		AEntity *curr = this->_enemy_pool->getUnit(i);
		if (curr->getHP())
		{
			if (curr->checkColision(this->_player->getPosition(), curr->getPosition(), 'P'))
			{
				this->_player->setHP(0);
				this->_endgame = 0;
			}
			curr->moveRandom('D', timer, _mapx, _mapy);
			attron(COLOR_PAIR(5));
			mvaddch(curr->getPosition().y, curr->getPosition().x, '@');
			mvaddch(curr->getPosition().y, curr->getPosition().x - 1, '-');
			mvaddch(curr->getPosition().y, curr->getPosition().x - 2, '\\');
			mvaddch(curr->getPosition().y, curr->getPosition().x + 1, '-');
			mvaddch(curr->getPosition().y, curr->getPosition().x + 2, '/');
			attroff(COLOR_PAIR(5));
		}
	}
	drawPlayer();
}

int Game::getKill()
{
	return (this->_kill);
}

void Game::ClearPrintEnnemi(int y, int x)
{
	mvaddch(y, x, ' ');
	mvaddch(y, x - 1, ' ');
	mvaddch(y, x - 2, ' ');
	mvaddch(y, x + 1, ' ');
	mvaddch(y, x + 2, ' ');
}

void Game::clearMove(void)
{
	for (int i = 0; i < this->_enemy_pool->getCount(); ++i)
	{
		AEntity *curr = this->_enemy_pool->getUnit(i);
		if (curr->getHP())
		{
			ClearPrintEnnemi(curr->getPosition().y, curr->getPosition().x);
		}
	}
}

void Game::setTime(int timer)
{
	this->_timer = timer;
}

int Game::getTime(void)
{
	return this->_timer;
}

void Game::spawnPlayer(void)
{
	struct position pos;
	pos.x = _mapx / 2 + 1;
	pos.y = _mapy - 1;
	this->_player = new User(pos, 1, '^', 0);
	drawPlayer();
	drawEnemy();
}

void Game::clearPlayer()
{
	mvaddch(_player->getPosition().y, _player->getPosition().x, ' ');
	mvaddch(_player->getPosition().y + 1, _player->getPosition().x + 1, ' ');
	mvaddch(_player->getPosition().y + 1, _player->getPosition().x - 1, ' ');
}

void Game::getInput(int c)
{

	clearPlayer();
	int x = _player->getPosition().x;
	int y = _player->getPosition().y;

	if (c == KEY_RIGHT && x < _mapx - 2)
	{
		_player->setPosition(y, x + 1);
	}
	if (c == 32 || c == ' ')
	{
		this->spawnMissile();
	}
	if (c == KEY_LEFT && x > 2)
	{
		_player->setPosition(y, x - 1);
	}
	drawPlayer();
}

void Game::drawPlayerMissile(void)
{
	for (int i = 0; i < this->_pool_player_missile->getCount(); ++i)
	{
		AEntity *curr = this->_pool_player_missile->getUnit(i);
		if (curr->getHP())
		{
			attron(COLOR_PAIR(2));
			mvaddch(curr->getPosition().y, curr->getPosition().x, '|');
			mvaddch(curr->getPosition().y + 1, curr->getPosition().x, ' ');
			attroff(COLOR_PAIR(2));
		}
	}
}

void Game::clearMoveMissile(void)
{
	for (int i = 0; i < this->_pool_player_missile->getCount(); ++i)
	{
		AEntity *curr = this->_pool_player_missile->getUnit(i);
		if (curr->getHP())
		{
			mvaddch(curr->getPosition().y, curr->getPosition().x, ' ');
		}
	}
}

void Game::movePlayerMissile(void)
{
	int timer = this->_timer;
	clearMoveMissile();

	for (int i = 0; i < this->_pool_player_missile->getCount(); ++i)
	{
		AEntity *curr = this->_pool_player_missile->getUnit(i);
		if (curr->getHP())
		{
			if (curr->moveMissile('U', timer, _mapx, _mapy))
			{
				for (int i = 0; i < this->_enemy_pool->getCount(); ++i)
				{
					AEntity *enemies = this->_enemy_pool->getUnit(i);
					if (enemies->getHP())
					{
						if (enemies->checkColision(enemies->getPosition(), curr->getPosition(), 'M'))
						{
							enemies->setHP(0);
							curr->setHP(0);
							ClearPrintEnnemi(enemies->getPosition().y, enemies->getPosition().x);
							this->_kill += 1;
						}
					}
				}
			}
		}
	}
	drawPlayerMissile();
	drawEnemy();
}

void Game::clearEnemyMoveMissile(void)
{
	for (int i = 0; i < this->_pool_enemy_missile->getCount(); ++i)
	{
		AEntity *curr = this->_pool_enemy_missile->getUnit(i);
		if (curr->getHP())
		{
			mvaddch(curr->getPosition().y, curr->getPosition().x, ' ');
		}
	}
}

void Game::drawEnemyMissile(void)
{
	for (int i = 0; i < this->_pool_enemy_missile->getCount(); ++i)
	{
		AEntity *curr = this->_pool_enemy_missile->getUnit(i);
		if (curr->getHP())
		{
			attron(COLOR_PAIR(2));
			mvaddch(curr->getPosition().y, curr->getPosition().x, '$');
			mvaddch(curr->getPosition().y - 1, curr->getPosition().x, ' ');
			attroff(COLOR_PAIR(2));
		}
	}
}

void Game::moveEnemiesMissile(void)
{
	int timer = this->_timer;
	clearMoveMissile();

	for (int i = 0; i < this->_pool_enemy_missile->getCount(); ++i)
	{
		AEntity *curr = this->_pool_enemy_missile->getUnit(i);
		if (curr->getHP())
		{
			if (curr->moveMissile('D', timer, _mapx, _mapy))
			{
				if (_player->getHP())
				{
					if (curr->checkColision(this->_player->getPosition(), curr->getPosition(), 'P'))
					{
						this->_player->setHP(0);
						this->_endgame = 0;
					}
				}
			}
		}
	}
	drawEnemyMissile();
}

void Game::enemyShoot()
{
	int   random = rand() % this->_enemy_pool->getCount();
	AEntity *missile = new Missile();

	for (int i = 0; i < this->_enemy_pool->getCount(); ++i)
	{
		AEntity *curr = this->_enemy_pool->getUnit(random);
		if (curr->getHP())
		{
			missile = this->_enemy_pool->getUnit(random)->attack();	
			for (int i = 0; i < this->_pool_enemy_missile->getCount(); ++i)
			{
				AEntity *curr_missile = this->_pool_enemy_missile->getUnit(i);
				if (!curr->getHP())
				{
					curr_missile->setPosition(missile->getPosition().y, missile->getPosition().x);
					delete missile;
					curr_missile->setHP(1);
					drawEnemyMissile();
					return ;
				}
			}
			this->_pool_enemy_missile->push(missile);
			drawEnemyMissile();
		}
		else
			delete missile;
			return ;
	}
}

void Game::spawnMissile(void)
{
	AEntity *missile = new Missile();

	missile = _player->attack();
	for (int i = 0; i < this->_pool_player_missile->getCount(); ++i)
	{
		AEntity *curr = this->_pool_player_missile->getUnit(i);
		if (!curr->getHP())
		{
			curr->setPosition(missile->getPosition().y, missile->getPosition().x);
			delete missile;
			curr->setHP(1);
			drawPlayerMissile();
			return ;
		}
	}
	this->_pool_player_missile->push(missile);
	drawPlayerMissile();
}

void Game::drawPlayer(void)
{
	attron(COLOR_PAIR(1));
	mvaddch(_player->getPosition().y, _player->getPosition().x, '^');
	mvaddch(_player->getPosition().y + 1, _player->getPosition().x + 1, '^');
	mvaddch(_player->getPosition().y + 1, _player->getPosition().x - 1, '^');
	attroff(COLOR_PAIR(1));
}

int Game::checkEndgame(void)
{
	return (this->_endgame);
}

void Game::spawnStars(void)
{
	// clear();
	struct position pos;
	pos.y = 0 + (rand() % 3 + 1);
	pos.x = 4 + (rand() % (_mapx - 4));

	for (int i = 0; i < this->_stars_pools->getCount(); ++i)
	{
		AEntity *curr = this->_stars_pools->getUnit(i);
		if (!curr->getHP())
		{
			curr->setPosition(pos.y, pos.x);
			curr->setHP(1);
			drawStars();
			return ;
		}
	}
	AEntity *next;
	next = new Enemy;

	next->setPosition(pos.y, pos.x);
	next->setHP(1);

	this->_stars_pools->push(next);
	drawStars();
}

void Game::clearStars(void){
	for (int i = 0; i < this->_stars_pools->getCount(); ++i)
	{
		AEntity *curr = this->_stars_pools->getUnit(i);
		mvaddch(curr->getPosition().y, curr->getPosition().x, ' ');
	}
}

void Game::drawStars(void)
{
	for (int i = 0; i < this->_stars_pools->getCount(); ++i)
	{
		AEntity *curr = this->_stars_pools->getUnit(i);
		mvaddch(curr->getPosition().y, curr->getPosition().x, '.');
	}
}

void Game::moveStars(void)
{
	clearStars();
	for (int i = 0; i < this->_stars_pools->getCount(); ++i)
	{
		AEntity *curr = this->_stars_pools->getUnit(i);
		if (curr->getPosition().y >= _mapy) 
			curr->setHP(0);
		curr->setPosition(curr->getPosition().y + 1, curr->getPosition().x);
		mvaddch(curr->getPosition().y, curr->getPosition().x, '*');
	}
	drawStars();
}

void Game::spawnCanion(void)
{
	struct position pos;
	pos.y = 0;
	pos.x = 1;
	for (int i = 0; i < this->_canion_pools->getCount(); ++i)
	{
		AEntity *curr = this->_canion_pools->getUnit(i);
		if (!curr->getHP())
		{
			curr->setPosition(pos.y, pos.x);
			curr->setHP(1);
			drawCanion();
			return ;
		}
	}

	AEntity *left;
	left = new Enemy;
	left->setPosition(pos.y, pos.x);
	left->setHP(1);
	this->_canion_pools->push(left);
	drawCanion();
}

void Game::clearCanion(void){
	for (int i = 0; i < this->_canion_pools->getCount(); ++i)
	{
		AEntity *curr = this->_canion_pools->getUnit(i);
		mvaddch(curr->getPosition().y, curr->getPosition().x, ' ');
	}
}

void Game::drawCanion(void)
{
	for (int i = 0; i < this->_canion_pools->getCount(); ++i)
	{
		AEntity *curr = this->_canion_pools->getUnit(i);
		mvaddch(curr->getPosition().y, curr->getPosition().x, 'H');
		mvaddch(curr->getPosition().y, curr->getPosition().x + (_mapx - 1), 'H');
	}
}

void Game::moveCanion(void)
{
	clearCanion();

	for (int i = 0; i < this->_canion_pools->getCount(); ++i)
	{
		AEntity *curr = this->_canion_pools->getUnit(i);
		if (curr->getPosition().y >= _mapy) 
			curr->setHP(0);
		curr->setPosition(curr->getPosition().y + 1, curr->getPosition().x);
	}
	drawCanion();
}
