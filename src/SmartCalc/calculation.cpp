#include "calculation.h"
#include <iostream>

Calculation::Calculation() {

    m_display_up   = new QLineEdit();
    m_display_down = new QLineEdit();
    m_label        = new QLabel();
    char answer    = 'n';

    QWidget *mainWindow = new QWidget();
    mainWindow->setWindowTitle("SmartCalc_v_1.0@mammiemi");

    QTabWidget *tabWidget = new QTabWidget(mainWindow);

    QWidget *tab1 = new QWidget();
    QWidget *tab2 = new QWidget();

    calcLayout  = new QGridLayout();
    graphLayout = new QGridLayout();

//    Loan *myloan = new Loan
    // Добавляем виджеты во вкладки
    QVBoxLayout *layout1 = new QVBoxLayout(tab1);
    layout1->addLayout(calcLayout);
    QVBoxLayout *layout2 = new QVBoxLayout(tab2);
    layout2->addLayout(graphLayout);

    // Добавляем вкладки в виджет вкладок
    tabWidget->addTab(tab1, "Calculation");
    tabWidget->addTab(tab2, "Loan_calculator");

    // Создаем главный менеджер компоновки и добавляем виджет вкладок в него
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);

    // Устанавливаем главный менеджер компоновки для главного окна
    mainWindow->setLayout(mainLayout);

    // Отображаем главное окно
    mainWindow->show();

    m_label->setStyleSheet("font: 25pt");
    m_label->setAlignment(Qt::AlignRight);

    m_display_up->setReadOnly(true);
    m_display_up->setStyleSheet("font: 18pt");
    m_display_up->setAlignment(Qt::AlignRight);
    m_display_up->setMaxLength(255);

    m_display_down->setReadOnly(true);
    m_display_down->setStyleSheet("font: 18pt");
    m_display_down->setAlignment(Qt::AlignRight);
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
    MyButton *ln   = createFuncButton("ln");
    MyButton *log  = createFuncButton("log");

    MyButton *sqrt = createFuncButton(QChar(0x0000221A));
    disconnect(sqrt, &MyButton::clicked, this, nullptr);
    connect(sqrt, &MyButton::clicked, this, [=](){ onSqrtClicked();});

    MyButton *bracket_op  = createNumButton("(");
    disconnect(bracket_op, &MyButton::clicked, this, nullptr);
    connect(bracket_op, &MyButton::clicked, this, [=](){ onBrOpClicked();});
    MyButton *bracket_cl  = createNumButton(")");
    disconnect(bracket_cl, &MyButton::clicked, this, nullptr);
    connect(bracket_cl, &MyButton::clicked, this, [=](){ onBrClClicked();});
    MyButton *dot  = createDotButton(".");
    MyButton *x  = createNumButton("x");
    disconnect(x, &MyButton::clicked, this, nullptr);
    connect(x, &MyButton::clicked, this, [=](){ onXClicked();});

    checkXVarBox = new QCheckBox("x_var", this);
    checkXVarBox->setStyleSheet("font: 18pt");
    connect(checkXVarBox, &QCheckBox::stateChanged, this, &Calculation::onXVarClicked);

    checkXGraphBox = new QCheckBox("x_graph", this);
    checkXGraphBox->setStyleSheet("font: 18pt");
    connect(checkXGraphBox, &QCheckBox::stateChanged, this, &Calculation::onXGraphClicked);

    MyButton *sum = createOperButton("+");
    MyButton *sub = createOperButton("-");
    MyButton *mul = createOperButton("*");
    MyButton *div = createOperButton("/");
    MyButton *deg = createOperButton("^");
    MyButton *mod = createOperButton("%");



    MyButton *unar_sign   = createNumButton(QChar(0x000000B1));
    disconnect(unar_sign, &MyButton::clicked, this, nullptr);
    connect(unar_sign, &MyButton::clicked, this, [=](){ onUnarClicked();});
    MyButton *equal  = createNumButton("=");
    disconnect(equal, &MyButton::clicked, this, nullptr);
    connect(equal, &MyButton::clicked, this, [=](){ onEqClicked();});
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
    allClean->setStyleSheet(  "background-color: #66bdff; color: #303030; font: 18pt");
    clean->setStyleSheet(     "background-color: #66bdff; color: #303030; font: 18pt");
    // background: linear-gradient(to bottom, #33ccff 0%, #ff99cc 100%

    calcLayout->addWidget(m_label,        8, 5, 1, 1);
    calcLayout->addWidget(m_display_up,   7, 0, 1, 6);
    calcLayout->addWidget(m_display_down, 9, 0, 1, 6);
    calcLayout->addWidget(num7,           0, 0, 1, 1);
    calcLayout->addWidget(num8,           0, 1, 1, 1);
    calcLayout->addWidget(num9,           0, 2, 1, 1);
    calcLayout->addWidget(deg,            0, 3, 1, 1);
    calcLayout->addWidget(unar_sign,      0, 4, 1, 1);
    calcLayout->addWidget(mod,            0, 5, 1, 1);
    calcLayout->addWidget(num4,           1, 0, 1, 1);
    calcLayout->addWidget(num5,           1, 1, 1, 1);
    calcLayout->addWidget(num6,           1, 2, 1, 1);
    calcLayout->addWidget(sub,            1, 3, 1, 1);
    calcLayout->addWidget(sum,            1, 4, 1, 1);
    calcLayout->addWidget(div,            1, 5, 1, 1);
    calcLayout->addWidget(num1,           2, 0, 1, 1);
    calcLayout->addWidget(num2,           2, 1, 1, 1);
    calcLayout->addWidget(num3,           2, 2, 1, 1);
    calcLayout->addWidget(bracket_op,     2, 3, 1, 1);
    calcLayout->addWidget(bracket_cl,     2, 4, 1, 1);
    calcLayout->addWidget(mul,            2, 5, 1, 1);
    calcLayout->addWidget(zero,           3, 0, 1, 2);
    calcLayout->addWidget(dot,            3, 2, 1, 1);
    calcLayout->addWidget(equal,          3, 3, 1, 2);
    calcLayout->addWidget(x,              3, 5, 1, 1);
    calcLayout->addWidget(cos,            4, 0, 1, 2);
    calcLayout->addWidget(sin,            4, 2, 1, 2);
    calcLayout->addWidget(tan,            4, 4, 1, 2);
    calcLayout->addWidget(acos,           5, 0, 1, 2);
    calcLayout->addWidget(asin,           5, 2, 1, 2);
    calcLayout->addWidget(atan,           5, 4, 1, 2);
    calcLayout->addWidget(sqrt,           6, 0, 1, 2);
    calcLayout->addWidget(ln,             6, 2, 1, 2);
    calcLayout->addWidget(log,            6, 4, 1, 2);
    calcLayout->addWidget(allClean,       10, 0, 1, 2);
    calcLayout->addWidget(clean,          10, 2, 1, 1);
    calcLayout->addWidget(checkXVarBox,   10, 3, 1, 1);
    calcLayout->addWidget(checkXGraphBox, 10, 5, 1, 1);


    amountCredit = new QSpinBox();
    QLabel *amountCreditLabel = new QLabel("Amount of credit");
    loanTerm = new QSpinBox();
    QLabel *loanTermLabel = new QLabel("Loan term (months)");
    annualInterest = new QSpinBox();
    QLabel *annualInterestLabel = new QLabel("Annual Interest (%)");

    amountCredit->setRange(0, 999999999);
    amountCredit->setValue(0);
    amountCredit->setStyleSheet("font: 25pt");
    amountCreditLabel->setStyleSheet("font: 18pt");

    loanTerm->setRange(0, 999999999);
    loanTerm->setValue(0);
    loanTerm->setStyleSheet("font: 25pt");
    loanTermLabel->setStyleSheet("font: 18pt");

    annualInterest->setRange(0, 99);
    annualInterest->setValue(0);
    annualInterest->setStyleSheet("font: 25pt");
    annualInterestLabel->setStyleSheet("font: 18pt");

    annutet = new QRadioButton("Annuity");
    annutet->setStyleSheet("font: 18pt");
    difer = new QRadioButton("Differential");
    difer->setStyleSheet("font: 18pt");

    MyButton *calculationCredit  = createNumButton("Calculation");
    calculationCredit->setStyleSheet("background: #ff99cc; color: #303030; font: 18pt");
    disconnect(calculationCredit, &MyButton::clicked, this, nullptr);
    connect(calculationCredit, &MyButton::clicked, this, [=](){ onCreditClicked();});


    graphLayout->addWidget(amountCreditLabel, 1, 0, 1, 2);
    graphLayout->addWidget(amountCredit, 2, 0, 1, 2);
    graphLayout->addWidget(loanTermLabel, 4, 0, 1, 2);
    graphLayout->addWidget(loanTerm, 5, 0, 1, 2);
    graphLayout->addWidget(annualInterestLabel, 7, 0, 1, 2);
    graphLayout->addWidget(annualInterest, 8, 0, 1, 2);
    graphLayout->addWidget(calculationCredit, 9, 0, 2, 2);
    graphLayout->addWidget(annutet, 2, 3, 1, 2);
    graphLayout->addWidget(difer, 4, 3, 1, 2);

    QLabel *fakeLabel = new QLabel("");
    fakeLabel->setStyleSheet("font: 25pt");
    graphLayout->addWidget(fakeLabel, 10, 0, 20, 5);

//    QLabel *fakeLabeltwo = new QLabel("");
//    fakeLabeltwo->setStyleSheet("font: 25pt");
//    graphLayout->addWidget(fakeLabeltwo, 14, 0, 3, 5);
//    QLabel *fakeLabelthree = new QLabel("");
//    fakeLabelthree->setStyleSheet("font: 25pt");
//    graphLayout->addWidget(fakeLabelthree, 17, 0, 3, 5);

}

void Calculation::onEqClicked() {
    m_display_down->insert(" " + m_display_up->text());
    m_display_up->setText("");
    char *input = m_display_down->text().toUtf8().data();
    char output[MAX_STR];
    double resultCalc = 0;
    if (sorting_station(input, output) >= 0) {
        if (answer == 'x') {
            bool isDouble;
            double x_value = m_x_var->text().toDouble(&isDouble);
            if (isDouble) {
                resultCalc = calculation_x_str(output, x_value);
                typeResult(resultCalc);
            } else {
                QMessageBox::critical(this, tr("Invalid expression"), tr(m_x_var->text().toUtf8().data()));
                m_x_var->setText("");
            }
        } else if (answer == 'f'){
            graphEdition(output);
        } else {
            resultCalc = calculation_core(output);
            typeResult(resultCalc);
        }
    } else {
        QMessageBox::critical(this, tr("Invalid expression"), tr(m_display_down->text().toUtf8().data()));
        m_display_down->setText("");
    }
}

void Calculation::typeResult(double resultCalc) {
    QString str = QString::number(resultCalc, 'f', 7).remove(QRegularExpression("0+$")).remove(QRegularExpression("\\.$"));
    m_display_down->setText("");
    m_display_down->insert(str);
}

void Calculation::graphEdition(char *output){
    int xMinValue= xMin->value();
    int xMaxValue= xMax->value();
    QVector<double> x((xMaxValue) - xMinValue);
    QVector<double> y((xMaxValue) - xMinValue);
    int i = 0;
    for (; xMinValue < xMaxValue; xMinValue ++, i++) {
        x[i] = (double)xMinValue;
        if (strncmp(output, "", 1)== 0){
            y[i] = 0;
        } else {
            y[i] = calculation_x_str(output, x[i]);
        }
    }

    QCustomPlot *customPlot = new QCustomPlot;
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    customPlot->xAxis->setRange(xMin->value(), xMax->value());
    customPlot->yAxis->setRange(yMin->value(), yMax->value());
    customPlot->resize(800, 800);
    customPlot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    customPlot->show();


}

MyButton* Calculation::createNumButton(QString text) {
    MyButton *button = new MyButton(text);
    connect(button, &MyButton::clicked, this, [=]() { onNumClicked(text); });
    return button;
}

MyButton *Calculation::createOperButton(const QString text) {
    MyButton *button = new MyButton(text);
    connect(button, &MyButton::clicked, this, [=]() { onOperClicked(text); });
    return button;
}

MyButton *Calculation::createFuncButton(const QString text) {
    MyButton *button = new MyButton(text);
    connect(button, &MyButton::clicked, this, [=]() { onFuncClicked(text); });
    return button;
}

MyButton *Calculation::createDotButton(const QString text) {
    MyButton *button = new MyButton(text);
    connect(button, &MyButton::clicked, this, [=]() { onDotClicked(text); });
    return button;
}

void Calculation::onNumClicked(QString digit) {
    if (answer == 'x') {
        m_x_var->insert(digit);
    } else {
        m_display_up->insert(digit);
    }
}

void Calculation::onCreditClicked(){
   if (annutet->isChecked()) {
       annutetFunction();
   } else if (difer->isChecked()){
       diferFunction();
   }
}
// everymonth, overpay, summpay
void Calculation::annutetFunction() {

    double sumCredt = amountCredit->value();
    int months = loanTerm->value();
    double percent = annualInterest->value();

    double ps = (percent/(100*12));
    double znam = (1 - pow(1 + ps, -months));
    double resultCredit = sumCredt * (ps / znam);

    double sumPay = resultCredit * months;
    double overPay = sumPay - sumCredt;

    QString str = QString::number(resultCredit, 'f', 2).remove(QRegularExpression("0+$")).remove(QRegularExpression("\\.$"));

    QListWidget *listWidget = new QListWidget();
    listWidget->setStyleSheet("font: 16pt");
    listWidget->resize(300,300);

    for (int i = 0; i < months; i++){
        QString iString = QString::number(i+1);
        listWidget->addItem(iString + " Month - " + str);
    }

    QString sumString = QString::number(sumPay, 'f', 2);
    QString overString = QString::number(overPay, 'f', 2);
    listWidget->addItem("Overpayment - " + overString);
    listWidget->addItem("Total payment - " + sumString);

    listWidget->show();

}

void Calculation::diferFunction() {

    double sumCredt = amountCredit->value();
    int months = loanTerm->value();
    double percent = annualInterest->value();

    double everymonth = sumCredt/months;
    double sumPay = 0;
    double overPay = 0;

    QListWidget *listWidget = new QListWidget();
    listWidget->setStyleSheet("font: 16pt");
    listWidget->resize(300,300);

    for (int i = 0; i < months; i++){
        double thatMounth = everymonth + (sumCredt - (i * everymonth)) * (percent / 100) * 31 / 365;
        QString iString = QString::number(i+1);
        QString str = QString::number(thatMounth, 'f', 2);
        listWidget->addItem(iString + " Month - " + str);
        sumPay += thatMounth;
    }

    QString sumString = QString::number(sumPay, 'f', 2);
    overPay = sumPay - sumCredt;
    QString overString = QString::number(overPay, 'f', 2);
    listWidget->addItem("Overpayment - " + overString);
    listWidget->addItem("Total payment - " + sumString);

    listWidget->show();
}

void Calculation::onDotClicked(QString digit)
{
    bool isDouble;
    if (answer == 'x') {
        dotClick(m_x_var, &isDouble, digit);
    } else {
        dotClick(m_display_up, &isDouble, digit);
    }
}

void Calculation::dotClick(QLineEdit *line, bool *isDouble, QString digit){
    line->text().toDouble(isDouble);
    if (line->text().contains('.') || !line->text().compare("")) {
    } else if (*isDouble){
        line->insert(digit);
    }
}

void Calculation::onBrClClicked() {
    bool isDouble;
    m_display_up->text().toDouble(&isDouble);
    if (isDouble || !m_display_up->text().compare("x")) {
        m_display_down->insert(" " + m_display_up->text() + ")");
        m_display_up->setText("");
    } else {
        m_display_down->insert(" )");
    }
}

void Calculation::onBrOpClicked() {
    if (m_display_up->text().compare("")){
        m_display_down->insert("(");
        m_label->setText("");
    } else {
        m_display_down->insert(m_label->text() + m_display_up->text() + "(");
        m_label->setText("");
        m_display_up->setText("");
    }
}

void Calculation::onFuncClicked(QString digit) {
    m_display_down->insert(" " + digit + "(" + m_display_up->text());
    m_display_up->setText("");
}

void Calculation::onXClicked() {
    if (!m_display_up->text().compare("")){
        m_display_up->insert("x");
        m_label->setText("");
    }
}

void Calculation::onOperClicked(QString digit) {
    bool isDouble;
    double value = m_display_up->text().toDouble(&isDouble);
    QString strDown = m_display_down->text();
    if((!m_display_up->text().compare("")) && (strDown.endsWith("+") || strDown.endsWith("-") || strDown.endsWith("/") || strDown.endsWith("*") || strDown.endsWith("d"))) {
    } else {
        if (isDouble || !m_display_up->text().compare("x")) {
            if (value < 0 ) {
                m_display_down->insert(" (" + m_display_up->text() + ") " + digit);
            } else {
                m_display_down->insert(" " + m_display_up->text() + " " + digit);
            }
            m_display_up->setText("");
        } else {
            m_display_down->insert(" " + digit);
        }
    }
}

void Calculation::onAcClicked() {
    m_display_up->setText("");
    m_display_down->setText("");
    m_label->setText("");
}

void Calculation::onCClicked() {
    m_display_up->setText("");
}

void Calculation::onUnarClicked() {
    bool isDouble;
    if (answer == 'x') {
        unarClick(m_x_var, &isDouble);
    } else {
        unarClick(m_display_up, &isDouble);
    }
}

void Calculation::unarClick(QLineEdit *line, bool *isDouble){
    QString tmp = line->text();
    double value = tmp.toDouble(isDouble);
    if (*isDouble) {
        value *= -1;
        QString str = QString::number(value, 'f', 7).remove(QRegularExpression("0+$")).remove(QRegularExpression("\\.$"));
        line->setText("");
        line->insert(str);
    }
}

void Calculation::onSqrtClicked() {
    m_display_down->insert(" sqrt (" + m_display_up->text());
    m_display_up->setText("");
}

void Calculation::onXVarClicked(int state) {
    if (state == Qt::Checked) {
        checkXGraphBox->setChecked(false);
        m_x_var   = new QLineEdit();
        m_x_var->setReadOnly(true);
        m_x_var->setStyleSheet("font: 18pt");
        m_x_var->setAlignment(Qt::AlignRight);
        calcLayout->addWidget(m_x_var, 10, 4, 1, 1);
        answer = 'x';
    } else {
        calcLayout->removeWidget(m_x_var);
        delete m_x_var;
        m_x_var = nullptr;
        answer = 'n';
    }
}

void Calculation::onXGraphClicked(int state) {
    if (state == Qt::Checked) {
        checkXVarBox->setChecked(false);
        xMin = new QSpinBox();
        x_min_label = new QLabel("X_min");
        xMax = new QSpinBox();
        x_max_label = new QLabel("X_max");
        yMin = new QSpinBox();
        y_min_label = new QLabel("Y_min");
        yMax = new QSpinBox();
        y_max_label = new QLabel("Y_max");

        xMin->setRange(-1000000, 1000000);
        xMin->setValue(0);
        calcLayout->addWidget(x_min_label, 3, 7, 1, 1);
        calcLayout->addWidget(xMin, 3, 8, 1, 2);

        xMax->setRange(-1000000, 1000000);
        xMax->setValue(0);
        calcLayout->addWidget(x_max_label, 4, 7, 1, 1);
        calcLayout->addWidget(xMax, 4, 8, 1, 2);

        yMin->setRange(-1000000, 1000000);
        yMin->setValue(0);
        calcLayout->addWidget(y_min_label, 6, 7, 1, 1);
        calcLayout->addWidget(yMin, 6, 8, 1, 2);

        yMax->setRange(-1000000, 1000000);
        yMax->setValue(0);
        calcLayout->addWidget(y_max_label, 7, 7, 1, 1);
        calcLayout->addWidget(yMax, 7, 8, 1, 2);

        answer = 'f';

    } else {
        calcLayout->removeWidget(xMin);
        calcLayout->removeWidget(x_min_label);
        delete xMin;
        delete x_min_label;
        calcLayout->removeWidget(xMax);
        calcLayout->removeWidget(x_max_label);
        delete xMax;
        delete x_max_label;
        calcLayout->removeWidget(xMin);
        calcLayout->removeWidget(y_min_label);
        delete yMin;
        delete y_min_label;
        calcLayout->removeWidget(yMax);
        calcLayout->removeWidget(y_max_label);
        delete yMax;
        delete y_max_label;
        answer = 'n';
    }
}
