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

class GameMaster : public QObject
{
    Q_OBJECT
public:
    explicit GameMaster(QObject *parent = 0);
    enum DayTime{
	day=0,
	dawn,
	night,
	maxdaytime
    }

signals:
    
private:
    void advance();
    bool setplayer
    list<Player*> players;
    int day;
    DayTime currentdaytime;
};

#endif // GAMEMASTER_H
