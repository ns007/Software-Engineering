#include <windows.h>
#include <iostream>
#include "../IControl/IControl.h"
#include "../Panel/Panel.h"
#include "ConsoleEventsHandler.h"

#define BYTES_TO_READ 128

using namespace std;

HANDLE hStdin;
INPUT_RECORD irInBuf[128];
DWORD cNumRead;
IControl * form;
std::vector<IControl*>::iterator it;

ConsoleEventsHandler::ConsoleEventsHandler(IControl * _form)
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	setForm(_form);
}

ConsoleEventsHandler::ConsoleEventsHandler()
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
}

ConsoleEventsHandler::~ConsoleEventsHandler()
{
}


void ConsoleEventsHandler::setForm(IControl * _form)
{
	form = _form;
}

void ConsoleEventsHandler::listenToEvents() {

	vector<IControl *> controllers = ((Panel*)form)->getControllers();
	it = controllers.begin();
	(*it)->focus();
	while (true)
	{
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle
			irInBuf,     // buffer to read into
			BYTES_TO_READ,         // size of read buffer
			&cNumRead)) // number of records read
			exit(-1);

		// Dispatch the events to the appropriate handler.
		for (int i = 0; i < cNumRead; i++)
		{
			if (irInBuf[i].EventType == KEY_EVENT &&  irInBuf[i].Event.KeyEvent.bKeyDown && irInBuf[i].Event.KeyEvent.uChar.AsciiChar == '\t')
			{				
				(*it)->focusOut();
				if (controllers.end() - it == 1)
					it = controllers.begin();
				else 
					it++;
				(*it)->focus();
			}

			else if (irInBuf[i].EventType == MOUSE_EVENT && irInBuf[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				(*it)->focusOut();
				COORD c = form->getMousePositionCoordinates(irInBuf[i].Event.MouseEvent);
				IControl * controller = ((Panel *)form)->findRelevantController({ c.X, c.Y });
				it = find(controllers.begin(), controllers.end(), controller);
				form->handleEvent(&irInBuf[i]);
			}
			else if (irInBuf[i].EventType == MOUSE_EVENT || irInBuf[i].EventType == KEY_EVENT)
			{
				form->handleEvent(&irInBuf[i]);
			}
		}
	}
}