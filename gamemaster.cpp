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

GameMaster::GameMaster(QObject *parent) : QObject(parent)
{

}

int GameMaster::advance()
{
    currentDaytime++;
    currentDaytime%=maxDayTime;
    switch (currentDaytime) {
    case day:
        break;
    case sunset:
        break;
    case night:
        for (Player* currentplayer:players)
            currentplayer->action(nullptr,nullptr);
        break;
    case dawn:
        for (Player* currentplayer:players)
            currentplayer->processVisitors();
        bool peoplewin=true;
        for(unsigned i=people+1;i<maxParty;i++){
            if(partyNumbers[i]*2>partyNumbers[sum]){
                printf("%d party wins",i);
                return i;
            }
            else if(partyNumbers[i]!=0)
                peoplewin=false;
        }
        if(peoplewin){
            printf("peoples' party wins");
            return people;
        }
        break;
    default:
        fprintf(stderr,"Error: unknown daytime %d",currentDaytime);
        break;
    }
}
