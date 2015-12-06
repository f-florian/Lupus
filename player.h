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

#ifndef PLAYER_H
#define PLAYER_H

#include <QtCore/QObject>
#include <list>

using namespace std;

class Player : public QObject
{
    Q_OBJECT
public:
    enum Character{
	wolf=0,
	maxCharacter
    };
    
    enum LifeState{
	alive=0,
	dead,
	dying,
	poisoned,
	resurrecting,
	maxLifeState
    };

    explicit Player(QString name_p, Character role_p, QObject *parent = 0);

signals:

public slots:
private:
    Player* visiting;
    //maybe useless
    list<Player*> visited;
    Character role;
};

#endif // PLAYER_H
