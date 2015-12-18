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

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <QtCore/QString>

class ErrorHandler
{
public:
    enum Severity{
        debug=0,
        low,
        normal,
        high,
        critical
    };

    ErrorHandler();

    static void init();
    static void logMessage(QString message_p);
    static void logError(QString error_p, Severity severity_p);
private:
    static QString logfilename;
    static QString errorfilename;
};

#endif // ERRORHANDLER_H
