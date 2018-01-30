#pragma once
#include <qLabel>
#include <qVariant>
#include "widgetSettingsWindow.h"
class SensorWidget;


//Окно управления датчиком
class SensorSettingsWindow : public WidgetSettingsWindow
{
public:
	explicit SensorSettingsWindow(SensorWidget* parent);
	~SensorSettingsWindow(void) {}
private:
	QPushButton* buttonRealControl;
	QPushButton* buttonManualControl;
	SensorWidget* widget;
};

