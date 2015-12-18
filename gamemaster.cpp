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

#include "gamemaster.h"
#include "errorhandler.h"

GameMaster::GameMaster(QObject *parent) : QObject(parent)
{

}

int GameMaster::advance()
{
    //advance day
    currentDaytime=static_cast<DayTime>(static_cast<int>(currentDaytime)+1);
    currentDaytime=static_cast<DayTime>(static_cast<int>(currentDaytime)%static_cast<int>(maxDayTime));

    //process actions according to DayTime
    switch (currentDaytime) {
    case day:
#warning write
        break;
    case sunset:
#warning write
        break;
    case night:
        //use night powers
        for (auto &currentplayer:players)
#warning make them actually act
            currentplayer.action(nullptr,nullptr);
        break;
    case dawn:
        //process nightly events
        for (auto &currentplayer:players)
            currentplayer.processVisitors();

        //check victory
        if(partyNumbers[people]==partyNumbers[sum]){
            printf("peoples' party wins");
            return people;
        }
        //check victory
        for(auto i=people+1;i<maxParty;i++)
            if(partyNumbers[i]*2>partyNumbers[sum]){
                printf("%d party wins",i);
                return i;
            }
        break;
    default:
        ErrorHandler::logError("Error: unknown daytime "+QString(static_cast<int>(currentDaytime)),ErrorHandler::high);
        break;
    }
    return Party::none;
}

bool GameMaster::addplayer(QString name_p, Player::Character role_p)
{
    for(auto &x:players)
        if(x.getname()==name_p){
            return false;
        }
    players.emplace_front(name_p,role_p);
    return true;
}

bool GameMaster::rmplayer(QString name_p)
{
    for(auto &x:players)
        if(x.getname()==name_p){
//            players.remove(x);
            return true;
        }
    return false;
}
