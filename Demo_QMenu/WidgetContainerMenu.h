#ifndef WIDGETCONTAINERMENU_H
#define WIDGETCONTAINERMENU_H

#include <QMenu>

class QToolButton;
class WidgetContainerMenu : public QMenu
{
    Q_OBJECT
public:
    explicit WidgetContainerMenu(QToolButton *parent = nullptr);

    //菜单弹出方向
    enum PopUpDirection
    {
        E_Default,//与右键菜单一致,默认向下弹,位置不够自动向上弹
        E_Up,//向上弹
        E_Down//向下弹
    };
    void SetPopUpDirection(PopUpDirection eDirection = E_Default);
    void showEvent(QShowEvent* event);
private:
    QToolButton *m_pToolButton = nullptr;
    PopUpDirection m_eDirection = E_Default;
};

#endif // WIDGETCONTAINERMENU_H
