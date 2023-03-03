#include "calculation.h"
#include <iostream>
#include "../smartcalc.h"



Calculation::Calculation() {

    m_display_up   = new QLineEdit();
    m_display_down = new QLineEdit();
    m_label = new QLabel();

    QGridLayout *mainLayout = new QGridLayout();

    m_label->setStyleSheet("font: 25pt");
    m_label->setAlignment(Qt::AlignRight);

    m_display_up->setReadOnly(true);
    m_display_up->setStyleSheet("font: 18pt");
    m_display_down->setStyleSheet("font: 18pt");
    m_display_down->setReadOnly(true);

    m_display_up->setAlignment(Qt::AlignRight);
    m_display_down->setAlignment(Qt::AlignRight);

    m_display_up->setMaxLength(255);
    m_display_down->setMaxLength(255);

    MyButton *num1 = createNumButton("1");
    MyButton *num2 = createNumButton("2");
    MyButton *num3 = createNumButton("3");
    MyButton *num4 = createNumButton("4");
    MyButton *num5 = createNumButton("5");
    MyButton *num6 = createNumButton("6");
    MyButton *num7 = createNumButton("7");
    MyButton *num8 = createNumButton("8");
    MyButton *num9 = createNumButton("9");
    MyButton *zero  = createNumButton("0");

    MyButton *cos  = createFuncButton("cos");
    MyButton *sin  = createFuncButton("sin");
    MyButton *tan  = createFuncButton("tan");
    MyButton *acos = createFuncButton("acos");
    MyButton *asin = createFuncButton("asin");
    MyButton *atan = createFuncButton("atan");

    MyButton *sqrt = createFuncButton(QChar(0x0000221A));
    MyButton *ln   = createFuncButton("ln");
    MyButton *log  = createFuncButton("log");

    MyButton *bracket_op  = createNumButton("(");
    MyButton *bracket_cl  = createNumButton(")");
    disconnect(bracket_cl, &MyButton::clicked, this, nullptr);
    connect(bracket_cl, &MyButton::clicked, this, [=](){ onBrClicked();});
    MyButton *dot  = createDotButton(".");
    MyButton *x  = createNumButton("x");

    MyButton *sum = createOperButton("+");
    MyButton *sub = createOperButton("-");
    MyButton *mul = createOperButton("*");
    MyButton *div = createOperButton(QChar(0x000000F7));
    MyButton *deg = createOperButton("^");
    MyButton *mod  = createOperButton("mod");


    MyButton *unar_sign   = createNumButton(QChar(0x000000B1));
    disconnect(unar_sign, &MyButton::clicked, this, nullptr);
    MyButton *equal  = createNumButton("=");
    disconnect(equal, &MyButton::clicked, this, nullptr);

    MyButton *allClean = createNumButton("AC");
    disconnect(allClean, &MyButton::clicked, this, nullptr);
    connect(allClean, &MyButton::clicked, this, [=](){ onAcClicked();});
    MyButton *clean = createNumButton("C");
    disconnect(clean, &MyButton::clicked, this, nullptr);
    connect(clean, &MyButton::clicked, this, [=](){ onCClicked();});

    num7->setStyleSheet(      "background-color: #c20aff; color: #303030; font: 18pt");
    num8->setStyleSheet(      "background-color:  #c20aff; color: #303030; font: 18pt");
    num9->setStyleSheet(      "background-color:  #c20aff; color: #303030; font: 18pt");
    deg->setStyleSheet(       "background-color:  #c20aff; color: #303030; font: 18pt");
    unar_sign->setStyleSheet( "background-color:  #c20aff; color: #303030; font: 18pt");
    mod->setStyleSheet(       "background-color:  #c20aff; color: #303030; font: 18pt");
    num4->setStyleSheet(      "background-color: #a329ff; color: #303030; font: 18pt");
    num5->setStyleSheet(      "background-color: #a329ff; color: #303030; font: 18pt");
    num6->setStyleSheet(      "background-color: #a329ff; color: #303030; font: 18pt");
    sub->setStyleSheet(       "background-color: #a329ff; color: #303030; font: 18pt");
    sum->setStyleSheet(       "background-color: #a329ff; color: #303030; font: 18pt");
    div->setStyleSheet(       "background-color: #a329ff; color: #303030; font: 18pt");
    num1->setStyleSheet(      "background-color: #8547ff; color: #303030; font: 18pt");
    num2->setStyleSheet(      "background-color: #8547ff; color: #303030; font: 18pt");
    num3->setStyleSheet(      "background-color: #8547ff; color: #303030; font: 18pt");
    bracket_op->setStyleSheet("background-color: #8547ff; color: #303030; font: 18pt");
    bracket_cl->setStyleSheet("background-color: #8547ff; color: #303030; font: 18pt");
    mul->setStyleSheet(       "background-color: #8547ff; color: #303030; font: 18pt");
    zero->setStyleSheet(      "background-color: #8547ff; color: #303030; font: 18pt");
    dot->setStyleSheet(       "background-color: #8547ff; color: #303030; font: 18pt");
    equal->setStyleSheet(     "background-color: #8547ff; color: #303030; font: 18pt");
    x->setStyleSheet(         "background-color: #8547ff; color: #303030; font: 18pt");
    cos->setStyleSheet(       "background-color: #6666ff; color: #303030; font: 18pt");
    sin->setStyleSheet(       "background-color: #6666ff; color: #303030; font: 18pt");
    tan->setStyleSheet(       "background-color: #6666ff; color: #303030; font: 18pt");
    acos->setStyleSheet(      "background-color: #4785ff; color: #303030; font: 18pt");
    asin->setStyleSheet(      "background-color: #4785ff; color: #303030; font: 18pt");
    atan->setStyleSheet(      "background-color: #4785ff; color: #303030; font: 18pt");
    sqrt->setStyleSheet(      "background-color: #29a3ff; color: #303030; font: 18pt");
    ln->setStyleSheet(        "background-color: #29a3ff; color: #303030; font: 18pt");
    log->setStyleSheet(       "background-color: #29a3ff; color: #303030; font: 18pt");

    mainLayout->addWidget(m_label, 8, 5, 1, 1);
    mainLayout->addWidget(m_display_up, 7, 0, 1, 6);
    mainLayout->addWidget(m_display_down, 9, 0, 1, 6);
    mainLayout->addWidget(num7,         0, 0, 1, 1);
    mainLayout->addWidget(num8,         0, 1, 1, 1);
    mainLayout->addWidget(num9,         0, 2, 1, 1);
    mainLayout->addWidget(deg,          0, 3, 1, 1);
    mainLayout->addWidget(unar_sign,    0, 4, 1, 1);
    mainLayout->addWidget(mod,          0, 5, 1, 1);
    mainLayout->addWidget(num4,         1, 0, 1, 1);
    mainLayout->addWidget(num5,         1, 1, 1, 1);
    mainLayout->addWidget(num6,         1, 2, 1, 1);
    mainLayout->addWidget(sub,          1, 3, 1, 1);
    mainLayout->addWidget(sum,          1, 4, 1, 1);
    mainLayout->addWidget(div,          1, 5, 1, 1);
    mainLayout->addWidget(num1,         2, 0, 1, 1);
    mainLayout->addWidget(num2,         2, 1, 1, 1);
    mainLayout->addWidget(num3,         2, 2, 1, 1);
    mainLayout->addWidget(bracket_op,   2, 3, 1, 1);
    mainLayout->addWidget(bracket_cl,   2, 4, 1, 1);
    mainLayout->addWidget(mul,          2, 5, 1, 1);
    mainLayout->addWidget(zero,         3, 0, 1, 2);
    mainLayout->addWidget(dot,          3, 2, 1, 1);
    mainLayout->addWidget(equal,        3, 3, 1, 2);
    mainLayout->addWidget(x,            3, 5, 1, 1);
    mainLayout->addWidget(cos,          4, 0, 1, 2);
    mainLayout->addWidget(sin,          4, 2, 1, 2);
    mainLayout->addWidget(tan,          4, 4, 1, 2);
    mainLayout->addWidget(acos,         5, 0, 1, 2);
    mainLayout->addWidget(asin,         5, 2, 1, 2);
    mainLayout->addWidget(atan,         5, 4, 1, 2);
    mainLayout->addWidget(sqrt,         6, 0, 1, 2);
    mainLayout->addWidget(ln,           6, 2, 1, 2);
    mainLayout->addWidget(log,          6, 4, 1, 2);
    mainLayout->addWidget(allClean,     10, 0, 1, 2);
    mainLayout->addWidget(clean,     10, 2, 1, 2);

    setLayout(mainLayout);

    setWindowTitle("Smartcalc@mammiemi");


}

MyButton* Calculation::createNumButton(QString text) {
    MyButton *button = new MyButton(text);
    connect(button, &MyButton::clicked, this, [=]() { onNumClicked(text); });
    return button;
}

MyButton *Calculation::createOperButton(const QString text)
{
    MyButton *button = new MyButton(text);
    connect(button, &MyButton::clicked, this, [=]() { onOperClicked(text); });
    return button;
}

MyButton *Calculation::createFuncButton(const QString text)
{
    MyButton *button = new MyButton(text);
    connect(button, &MyButton::clicked, this, [=]() { onFuncClicked(text); });
    return button;
}

MyButton *Calculation::createDotButton(const QString text)
{
    MyButton *button = new MyButton(text);
    connect(button, &MyButton::clicked, this, [=]() { onDotClicked(text); });
    return button;
}

void Calculation::onNumClicked(QString digit)
{
    m_display_up->insert(digit);
}

void Calculation::onDotClicked(QString digit)
{
    bool isDouble;
    m_display_up->text().toDouble(&isDouble);
    if (m_display_up->text().contains('.') || !m_display_up->text().compare("")) {
    } else if (isDouble){
        m_display_up->insert(digit);
    }
}

void Calculation::onBrClicked()
{
    m_display_down->insert(m_display_up->text() + ")");
    m_display_up->setText("");
}


void Calculation::onFuncClicked(QString digit)
{
    if (!m_display_up->text().compare("") && !m_label->text().compare("")) {
        m_display_down->insert(digit);
        m_display_down->insert("(");
    } else {
    }
}

void Calculation::onOperClicked(QString digit)
{
    if (!m_display_up->text().compare("")){
    } else {
        m_display_down->insert(m_label->text());
        m_display_down->insert(m_display_up->text());
        m_label->setText(digit);
        m_display_up->setText("");
    }
}

void Calculation::onAcClicked()
{
    m_display_up->setText("");
    m_display_down->setText("");
    m_label->setText("");
}

void Calculation::onCClicked()
{
    m_display_up->setText("");
}
