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
    /**
     * @brief The Character enum list of roles a Player can have.
     *
     * Roles are grouped by Party, each section ending with max<Partyname>
     */
    enum Character{
        peasant=0,
        maxPeople,
        wolf,
        maxWolves,
        maxCharacter
    };
    
    enum LifeState{
        alive=0,
        dead,
        poisoned,
        resurrected,
        phantom,
        maxLifeState
    };

    explicit Player(QString name_p, Character role_p, QObject *parent = 0);
    QString getname();
    bool action(Player* first, Player* second=nullptr);
    Player::LifeState processVisitors();
signals:

public slots:
private:
    /**
     * @brief actOn act on this Player
     * @param visitor the acting player
     */
    bool actOn(Player* visitor);

    /** @brief name Player (nick)name */
    QString name;
    /** @brief visiting the person whose house this Player is in */
    Player* visiting;
    /** @brief visited Players visiting this one */
    list<Player*> visited;
    /** @brief role role in the game */
    Character role;
};

#endif // PLAYER_H
