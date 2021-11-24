#include "WidgetContainerMenu.h"
#include <QToolButton>
WidgetContainerMenu::WidgetContainerMenu(QToolButton *parent) : QMenu(parent)
{
    m_pToolButton = parent;
}

void WidgetContainerMenu::SetPopUpDirection(WidgetContainerMenu::PopUpDirection eDirection)
{
    m_eDirection = eDirection;
}

void WidgetContainerMenu::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
    QPoint point = m_pToolButton->mapToGlobal(QPoint(0,0));
    switch(m_eDirection)
    {
    case E_Default:
    {
    }break;
    case E_Up:
    {
        move(point.x(),point.y() - sizeHint().height());
    }break;
    case E_Down:
    {
        move(point.x(),point.y() + m_pToolButton->sizeHint().height());
    }break;
    }
}
