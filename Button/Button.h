#ifndef SHITOT_BUTTON_H
#define SHITOT_BUTTON_H
#include "../IControl/IControl.h"
#include "../Label/Label.h"
#include "MouseListener.h"

#pragma once
class Button : public Label
{
private:
	MouseListener * mouseListener;

public:
	Button(int width);
	void addMouseListener(MouseListener *);
	void operateKeyboardEvents(KEY_EVENT_RECORD);
	void operateMouseEvents(MOUSE_EVENT_RECORD);
	void onPressed();
	void focus();
	~Button();
};

#endif //SHITOT_BUTTON_H