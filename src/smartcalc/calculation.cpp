#include "calculation.h"
#include <iostream>
//#include "./ui_calculation.h"



Calculation::Calculation() {

    m_display_up   = new QLineEdit();

    m_label = new QLabel();
    QGridLayout *mainLayout = new QGridLayout();

    m_display_up->setReadOnly(true);

    m_display_up->setAlignment(Qt::AlignRight);

    m_display_up->setMaxLength(255);

    m_label->setText("M");

    MyButton *num1 = createButton("1", SLOT(dig1()));
    MyButton *num2 = createButton("2", SLOT(dig2()));
    MyButton *num3 = createButton("3", SLOT(dig3()));
    MyButton *num4 = createButton("4", SLOT(dig4()));
    MyButton *num5 = createButton("5", SLOT(dig5()));
    MyButton *num6 = createButton("6", SLOT(dig6()));
    MyButton *num7 = createButton("7", SLOT(dig7()));
    MyButton *num8 = createButton("8", SLOT(dig8()));
    MyButton *num9 = createButton("9", SLOT(dig9()));
    MyButton *zero  = createButton("0", SLOT(dig9()));
    MyButton *cos  = createButton("cos", SLOT(dig9()));
    MyButton *sin  = createButton("sin", SLOT(dig9()));
    MyButton *tan  = createButton("tan", SLOT(dig9()));
    MyButton *acos = createButton("acos", SLOT(dig9()));
    MyButton *asin = createButton("asin", SLOT(dig9()));
    MyButton *atan = createButton("atan", SLOT(dig9()));
    MyButton *sqrt = createButton("sqrt", SLOT(dig9()));
    MyButton *ln   = createButton("ln", SLOT(dig9()));
    MyButton *log  = createButton("log", SLOT(dig9()));
    MyButton *bracket_op  = createButton("(", SLOT(dig9()));
    MyButton *bracket_cl  = createButton(")", SLOT(dig9()));
    MyButton *sum = createButton("+", SLOT(dig9()));
    MyButton *sub = createButton("-", SLOT(dig9()));
    MyButton *mul = createButton("*", SLOT(dig9()));
    MyButton *div = createButton("/", SLOT(dig9()));
    MyButton *deg = createButton("^", SLOT(dig9()));
    MyButton *unar_sign   = createButton("+-", SLOT(dig9()));
    MyButton *mod  = createButton("mod", SLOT(dig9()));
    MyButton *dot  = createButton(".", SLOT(dig9()));

    num1->setStyleSheet("background-color: #ab8cff; color: #404040;");
    num2->setStyleSheet("background-color: #ab8cff; color: #404040;");
    num3->setStyleSheet("background-color: #ab8cff; color: #404040;");
    num4->setStyleSheet("background-color: #d940ff; color: #404040;");
    num5->setStyleSheet("background-color: #d940ff; color: #404040;");
    num6->setStyleSheet("background-color: #d940ff; color: #404040;");
    num7->setStyleSheet("background-color: #FF00FF; color: #404040;");
    num8->setStyleSheet("background-color: #FF00FF; color: #404040;");
    num9->setStyleSheet("background-color: #FF00FF; color: #404040;");
    //zero->setStyleSheet("background-color: fuchsia;");
    cos->setStyleSheet("background-color: #9ca6ff; color: #404040;");
    sin->setStyleSheet("background-color: #9ca6ff; color: #404040;");
    tan->setStyleSheet("background-color: #9ca6ff; color: #404040;");
    acos->setStyleSheet("background-color: #8cbfff; color: #404040;");
    asin->setStyleSheet("background-color: #8cbfff; color: #404040;");
    atan->setStyleSheet("background-color: #8cbfff; color: #404040;");
    sqrt->setStyleSheet("background-color: #75e6ff; color: #404040;");
    ln->setStyleSheet("background-color: #75e6ff; color: #404040;");
    log->setStyleSheet("background-color: #75e6ff; color: #404040;");
    bracket_op->setStyleSheet("background-color: #ab8cff; color: #404040;");
    bracket_cl->setStyleSheet("background-color: #ab8cff; color: #404040;");
    sum->setStyleSheet("background-color: #ab8cff; color: #404040;");
    sub->setStyleSheet("background-color: #d940ff; color: #404040;");
    mul->setStyleSheet("background-color: #d940ff; color: #404040;");
    div->setStyleSheet("background-color: #d940ff; color: #404040;");
    deg->setStyleSheet("background-color: #FF00FF; color: #404040;");
    unar_sign->setStyleSheet("background-color: #FF00FF; color: #404040;");
    mod->setStyleSheet("background-color: #FF00FF; color: #404040;");

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
    mainLayout->addWidget(mul,          1, 4, 1, 1);
    mainLayout->addWidget(div,          1, 5, 1, 1);
    mainLayout->addWidget(num1,         2, 0, 1, 1);
    mainLayout->addWidget(num2,         2, 1, 1, 1);
    mainLayout->addWidget(num3,         2, 2, 1, 1);
    mainLayout->addWidget(bracket_op,   2, 3, 1, 1);
    mainLayout->addWidget(bracket_cl,   2, 4, 1, 1);
    mainLayout->addWidget(sum,          2, 5, 1, 1);
    mainLayout->addWidget(cos,          3, 0, 1, 2);
    mainLayout->addWidget(sin,          3, 2, 1, 2);
    mainLayout->addWidget(tan,          3, 4, 1, 2);
    mainLayout->addWidget(acos,         4, 0, 1, 2);
    mainLayout->addWidget(asin,         4, 2, 1, 2);
    mainLayout->addWidget(atan,         4, 4, 1, 2);
    mainLayout->addWidget(sqrt,         5, 0, 1, 2);
    mainLayout->addWidget(ln,           5, 2, 1, 2);
    mainLayout->addWidget(log,          5, 4, 1, 2);

//    mainLayout->addWidget(m_display_up  , 0 , 0, 5, 1);
//    mainLayout->addWidget(m_label  , 1 , 5, 1, 1);


    setLayout(mainLayout);


    setWindowTitle("Smartcalc@mammiemi");
}

void Calculation::dig1()
{
    qDebug() << "1";
}

void Calculation::dig2()
{
    qDebug() << "2";
}

void Calculation::dig3()
{
    qDebug() << "3";
}

void Calculation::dig4()
{
    qDebug() << "4";
}

void Calculation::dig5()
{
    qDebug() << "5";
}

void Calculation::dig6()
{
    qDebug() << "6";
}

void Calculation::dig7()
{
    qDebug() << "7";
}

void Calculation::dig8()
{
    qDebug() << "8";
}

void Calculation::dig9()
{
    qDebug() << "9";
}

MyButton *Calculation::createButton(const QString text, const char *member) {
    MyButton *btn = new MyButton(text);
    connect(btn, SIGNAL(clicked()), this, member);
    return btn;
}
