#include <qLayout>
#include <qPalette>
#include "windows/sensorSettingsWindow.h"
#include "widgets/sensorWidget.h"


SensorSettingsWindow::SensorSettingsWindow(SensorWidget *parent) :
	WidgetSettingsWindow(parent),
	widget(parent)
{
	this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	this->setAttribute(Qt::WA_DeleteOnClose);
	this->setFixedWidth(100);

	auto centralLayout = this->centralWidget()->layout();

	buttonRealControl = new QPushButton;
	buttonRealControl->setText(QString::fromLocal8Bit("Реальное"));
	QObject::connect(buttonRealControl, &QPushButton::clicked, [&]()
	{
		widget->lStatus = ScadaObject::Status::real;
	});
	centralLayout->addWidget(buttonRealControl);

	buttonManualControl = new QPushButton;
	buttonManualControl->setText(QString::fromLocal8Bit("Ручное"));
	QObject::connect(buttonManualControl, &QPushButton::clicked, [&]()
	{
		widget->lStatus = ScadaObject::Status::manualImitation;
	});
	centralLayout->addWidget(buttonManualControl);

	auto buttonExit = this->CreateExitButton();
	centralLayout->addWidget(buttonExit);

	auto ConfigControlButtons = [&](const QVariant& status)
	{
		this->ConfigControlButton(buttonRealControl, status, ScadaObject::Status::real);
		this->ConfigControlButton(buttonManualControl, status, ScadaObject::Status::manualImitation);
	};
	QObject::connect(&widget->loStatus, &LinkValue::Change, ConfigControlButtons);
	ConfigControlButtons(widget->loStatus.GetValue());
}
