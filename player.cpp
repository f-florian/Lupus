/**************************************************************************
 * Copyright (C) 2015 Francesco Florian, Klest Dedja
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>
 *************************************************************************/

#include "player.h"

Player::Player(QString name_p, Character role_p, QObject *parent):QObject(parent)
{
    name=name_p;
    role=role_p;
}

QString Player::getname()
{
    return name;
}

bool Player::action(Player *first, Player *second)
{
#warning check nullptr
    first->actOn(this);
    second->actOn(this);
}

Player::LifeState Player::processVisitors()
{
#warning write something that makes sense
    return alive;
}


bool Player::actOn(Player *visitor)
{
#warning write something that makes sense
    return true;
}
