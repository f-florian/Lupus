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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <stdio.h>

#warning unix only; set in config file
const char* logfile="~/.cdb.log";
const char* errfile="~/.cdb.err";


int main(int argc, char *argv[])
{
    QApplication a(argc,argv);


    //let's log output to files instead of console
    freopen(logfile,"a",stdout);
    freopen(errfile,"a",stderr);

    //set some application parameters from cmake (see the 'add_definitions' line)
    a.setApplicationName(APPNAME);
    a.setApplicationVersion(QString("%1.%2").arg(MAJOR).arg(MINOR));
    a.setApplicationDisplayName(a.applicationName());

    return a.exec();
}
