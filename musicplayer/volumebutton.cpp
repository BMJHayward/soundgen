#include "volumebutton.h"

#include <QLabel>
#include <QToolButton>
#include <QtWidgets>


VolumeButton::VolumeButton(QWidget *parent) :
    QToolButton(parent), menu(0), label(0), slider(0)
{
    setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    setPopupMode(QToolButton::InstantPopup);

    QWidget *popup = new QWidget(this);

    slider = new QSlider(Qt::Horizontal, popup);
    slider->setRange(0, 100);
    connect(slider, &QAbstractSlider::valueChanged, this, &VolumeButton::volumeChanged);

    label = new QLabel(popup);
    label->setAlignment(Qt::AlignCenter);
    label->setNum(100);
    label->setMinimumWidth(label->sizeHint().width());

    typedef void(QLabel::*IntSlot)(int);
    connect(slider, &QAbstractSlider::valueChanged, label, static_cast<IntSlot>(&QLabel::setNum));

    QBoxLayout *popupLayout = new QHBoxLayout(popup);
    popupLayout->setMargin(2);
    popupLayout->addWidget(slider);
    popupLayout->addWidget(label);

    QWidgetAction *action = new QWidgetAction(this);
    action->setDefaultWidget(popup);

    menu = new QMenu(this);
    menu->addAction(action);
    setMenu(menu);

    stylize();
}


void VolumeButton::increaseVolume()
{
    slider->triggerAction(QSlider::SliderPageStepAdd);
}


void VolumeButton::decreaseVolume()
{
    slider->triggerAction(QSlider::SliderPageStepSub);
}


int VolumeButton::volume() const
{
    return slider->value();
}


void VolumeButton::setVolume(int volume)
{
    slider->setValue(volume);
}


void VolumeButton::stylize()
{
}
