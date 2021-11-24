#include "Dialog.h"
#include "ui_Dialog.h"
#include <QWidgetAction>
#include "WidgetContainerMenu.h"
#include "MyWidget.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //默认
    {
        QToolButton *pToolButton = ui->toolButton_Default;
        WidgetContainerMenu *pMenu = new WidgetContainerMenu(pToolButton);
        MyWidget *pWidget = new MyWidget;
        QWidgetAction *pWidgetAction = new QWidgetAction(pToolButton);
        pWidgetAction->setDefaultWidget(pWidget);
        pMenu->addAction(pWidgetAction);
        pToolButton->setMenu(pMenu);
        connect(pToolButton,&QToolButton::clicked,
                pToolButton,&QToolButton::showMenu);
    }
    //向上弹
    {
        QToolButton *pToolButton = ui->toolButton_Up;
        WidgetContainerMenu *pMenu = new WidgetContainerMenu(pToolButton);
        pMenu->SetPopUpDirection(WidgetContainerMenu::E_Up);
        MyWidget *pWidget = new MyWidget;
        QWidgetAction *pWidgetAction = new QWidgetAction(pToolButton);
        pWidgetAction->setDefaultWidget(pWidget);
        pMenu->addAction(pWidgetAction);
        pToolButton->setMenu(pMenu);
        connect(pToolButton,&QToolButton::clicked,
                pToolButton,&QToolButton::showMenu);
    }
    //向下弹
    {
        QToolButton *pToolButton = ui->toolButton_Down;
        WidgetContainerMenu *pMenu = new WidgetContainerMenu(pToolButton);
        pMenu->SetPopUpDirection(WidgetContainerMenu::E_Down);
        MyWidget *pWidget = new MyWidget;
        QWidgetAction *pWidgetAction = new QWidgetAction(pToolButton);
        pWidgetAction->setDefaultWidget(pWidget);
        pMenu->addAction(pWidgetAction);
        pToolButton->setMenu(pMenu);
        connect(pToolButton,&QToolButton::clicked,
                pToolButton,&QToolButton::showMenu);
    }




}

Dialog::~Dialog()
{
    delete ui;
}

