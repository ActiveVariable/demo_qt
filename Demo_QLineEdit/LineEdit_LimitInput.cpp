#include "LineEdit_LimitInput.h"
#include <QLineEdit>
#include <QLabel>
LineEdit_LimitInput::LineEdit_LimitInput(QWidget *parent) : QLineEdit(parent)
{
    m_pLabel = new QLabel(this);
}

void LineEdit_LimitInput::SetMaxCharactorLength(int nMaxCharactorLength)
{
    setMaxLength(nMaxCharactorLength);
    setStyleSheet("QLineEdit{font: 14px \"微软雅黑\";padding:0px "+QString::number(m_nLabelWidth + 10)+"px 0px 0px;}");
    m_pLabel->setAlignment(Qt::AlignRight);
    m_pLabel->setStyleSheet("QLabel{color:gray;font: 14px \"微软雅黑\";background-color:transparent;}");
    m_pLabel->setText("0/" + QString::number(nMaxCharactorLength) + "  ");
    m_pLabel->setFixedWidth(m_nLabelWidth);
    connect(this,&QLineEdit::textChanged,[=]
    {
        QString text = this->text();
        m_pLabel->setText(QString::number(text.size()) + "/" + QString::number(nMaxCharactorLength) + "  ");
    });
}

void LineEdit_LimitInput::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
    m_pLabel->move(width() - m_nLabelWidth,0);
}

void LineEdit_LimitInput::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    m_pLabel->move(width() - m_nLabelWidth,0);
}
