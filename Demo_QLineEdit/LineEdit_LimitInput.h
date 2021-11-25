#ifndef LINEEDIT_LIMITINPUT_H
#define LINEEDIT_LIMITINPUT_H

#include <QLineEdit>

class QLabel;
class LineEdit_LimitInput : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEdit_LimitInput(QWidget *parent = nullptr);

    void SetMaxCharactorLength(int nMaxCharactorLength);
protected:
    void showEvent(QShowEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    QLabel *m_pLabel = nullptr;
    int m_nLabelWidth = 50;//字符统计标签宽度
};

#endif // LINEEDIT_LIMITINPUT_H
