/*
* ========================================================================== *
*                                                                            *
*    This file is part of the Openterface Mini KVM App QT version            *
*                                                                            *
*    Copyright (C) 2024   <info@openterface.com>                             *
*                                                                            *
*    This program is free software: you can redistribute it and/or modify    *
*    it under the terms of the GNU General Public License as published by    *
*    the Free Software Foundation, either version 3 of the License, or       *
*    (at your option) any later version.                                     *
*                                                                            *
*    This program is distributed in the hope that it will be useful, but     *
*    WITHOUT ANY WARRANTY; without even the implied warranty of              *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
*    General Public License for more details.                                *
*                                                                            *
*    You should have received a copy of the GNU General Public License       *
*    along with this program. If not, see <http://www.gnu.org/licenses/>.    *
*                                                                            *
* ========================================================================== *
*/

#ifndef MOUSEMANAGER_H
#define MOUSEMANAGER_H


#include "serial/SerialPortManager.h"

#include <QObject>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(log_core_mouse)

class MouseManager : public QObject
{
    Q_OBJECT

public:
    explicit MouseManager(SerialPortManager& spm, QObject *parent = nullptr);

    void handleAbsoluteMouseAction(int x, int y, int mouse_event, int wheelMovement);
    void handleRelativeMouseAction(int dx, int dy, int mouse_event, int wheelMovement);

private:
    SerialPortManager& serialPortManager;
    bool isDragging = false; 
    
    uint8_t mapScrollWheel(int delta);
    // ... rest of your class definition ...
};

#endif // MOUSEMANAGER_H