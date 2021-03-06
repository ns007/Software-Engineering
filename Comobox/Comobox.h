#pragma once
#ifndef SHITOT_COMOBOX_H
#define SHITOT_COMOBOX_H
#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

class Comobox : public Panel
{

private:
	vector<string> entries;
	Panel * choisesPanel;
	Panel * chosenValuePanel;
	Label * chosenValueLabel;
	Button * chosenOption;
	Button * openCloseChoisesPanelButton;

public:
	Comobox(int, int, vector<string>);
	~Comobox();
	void operateKeyboardEvents(KEY_EVENT_RECORD);
	void operateMouseEvents(MOUSE_EVENT_RECORD);
	Panel * getChoisesPanel();
	Label * getChosenValueLabel();
	Button * getChosenOption();
	void setChosenOption(Button *);
	void setVisible(bool);
	void focus();
	void focusOut();
	MouseListener * getOpenCloseButtonMouseListener();
	MouseListener * getChooseOptionButtonMouseListener();
};

#endif //SHITOT_COMOBOX_H
