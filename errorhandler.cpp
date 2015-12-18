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

#include "errorhandler.h"
#include <stdio.h>
#include <QDateTime>

extern QString ErrorHandler::logfilename;
extern QString ErrorHandler::errorfilename;

#warning unix only; set in config file
const QString logfile="~/.cdb.log";
const QString errfile="~/.cdb.err";

ErrorHandler::ErrorHandler(){}

void ErrorHandler::init()
{

#warning change this
    logfilename=logfile;
    errorfilename=errfile;

    //let's log output to files instead of console
    freopen(logfilename.toUtf8().constData(),"a",stdout);
    freopen(errorfilename.toUtf8().constData(),"a",stderr);
}

void ErrorHandler::logError(QString error_p, Severity severity_p)
{
#warning set a rule to hide low severity
    //write timestamp and severiry level before message
    fprintf(stderr,"%s\t (error severity %d): %s",
            QDateTime::currentDateTime().toString(DATETIMEFORMAT).toUtf8().constData(),
            severity_p,
            error_p.toUtf8().constData());
}

void ErrorHandler::logMessage(QString message_p)
{
    //write timestamp before message
    fprintf(stderr,"%s\t: %s",
            QDateTime::currentDateTime().toString(DATETIMEFORMAT).toUtf8().constData(),
            message_p.toUtf8().constData());
}
