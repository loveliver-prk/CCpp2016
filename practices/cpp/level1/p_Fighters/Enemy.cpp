//
//  Enemy.cpp
//  SFML-PLANE
//
//  Created by iam24 on 16/5/10.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include "Enemy.hpp"
#include "Texture.hpp"
int Enemy::tot_enemy = 0;
int Enemy::escape_enemy = 0;
Enemy::Enemy(double speed, sf::Vector2f p, int hp, int score_)
{
    enemy_speed = speed;
    health = hp;
    score = score_;
    pos = p;
    if (hp == 1)
        sprite.setTexture(Texture::enemy_texture);
    else
        sprite.setTexture(Texture::enemy_boss_texture);
    sprite.setPosition(p);
    tot_enemy++;
}

void Enemy::add_enemy()
{
    if (escape_enemy>=10) return ;
    if (enemy_time<enemy_limit) return;
    if (all_enemy.size()>=5) return ;
    int x = random() % 600;
    sf::Vector2f pos(x,0.f);
    double  a = fmin(tot_enemy/10 * 1.0+1, 20.0);
    int hp = (tot_enemy%20 == 0) ? enemy_boss_health: 1;
    if (hp == enemy_boss_health)
        all_enemy.push_back(Enemy(0,pos, hp, enemy_boss_score));
        else all_enemy.push_back(Enemy(a,pos,hp, enemy_score));
    enemy_time = 0;
}
void Enemy::enemy_move()
{
    enemy_time = fmin(enemy_time+1, 1000);
    int tot = all_enemy.size();
    for (int i = 0 ; i < tot; i++)
    {
        all_enemy[i].pos.y += all_enemy[i].enemy_speed;
    }
    for (int i = tot-1 ;i >=0 ;i--)
    {
        double x = all_enemy[i].pos.x;
        double y = all_enemy[i].pos.y;
        if (y>1250)
        {
            all_enemy.erase(all_enemy.begin()+i);
            escape_enemy++;
        }
        else all_enemy[i].sprite.setPosition(x, y);
    }
}

