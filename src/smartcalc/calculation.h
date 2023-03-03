#ifndef CALCULATION_H
#define CALCULATION_H

#include <QSignalMapper>
#include <QGridLayout>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include "mybutton.h"

class Calculation : public QWidget
{
    Q_OBJECT

public:
    Calculation();

private:
    MyButton *createNumButton(const QString text);
    MyButton *createOperButton(const QString text);
    MyButton *createFuncButton(const QString text);
    MyButton *createDotButton(const QString text);
    QString m_infix_string;
    QLineEdit *m_display_up;
    QLineEdit *m_display_down;
    QLabel *m_label;

private slots:
    void onNumClicked(QString digit);
    void onOperClicked(QString digit);
    void onAcClicked();
    void onCClicked();
    void onFuncClicked(QString digit);
    void onDotClicked(QString digit);
    void onBrClicked();
};

#endif // CALCULATION_H
