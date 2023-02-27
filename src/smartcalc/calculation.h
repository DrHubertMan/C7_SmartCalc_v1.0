#ifndef CALCULATION_H
#define CALCULATION_H

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

private slots:
    void dig1();
    void dig2();
    void dig3();
    void dig4();
    void dig5();
    void dig6();
    void dig7();
    void dig8();
    void dig9();

private:
    MyButton *createButton(const QString text, const char *member);

    QString m_infix_string;

    QLineEdit *m_display_up;
    QLineEdit *m_display_down;
    QLabel *m_label;
};
#endif // CALCULATION_H
