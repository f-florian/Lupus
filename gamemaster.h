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

#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QtCore/QObject>
#include <list>
#include "player.h"

using namespace std;

class GameMaster : public QObject
{
    Q_OBJECT
#warning use Q_ENUMS(names)?
public:
    explicit GameMaster(QObject *parent = 0);

    enum DayTime{
        day=0,
        sunset,
        night,
        dawn,
        maxDayTime
    };

    enum Party{
        /** so we always have <name> -1 */
        none=0,
        people,
        wolves,
        sum,
        maxParty
    };

signals:
    
private:
    int advance();
    bool addplayer(QString name_p, Player::Character role_p);
    bool rmplayer(QString name_p);
    list<Player> players;
    int dayNumber;
    DayTime currentDaytime;
    unsigned short partyNumbers[maxParty];
};

#endif // GAMEMASTER_H
