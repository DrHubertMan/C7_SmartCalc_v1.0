#ifndef CALCULATION_H
#define CALCULATION_H

#include <QMessageBox>
#include <QGridLayout>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include <QCheckBox>
#include <QSpinBox>
#include <QTabWidget>
#include <QRegularExpression>
#include "qcustomplot.h"
//#include <QtCharts/QChart>
//#include <QtCharts/QChartView>
//#include <QtCharts/QLineSeries>
//#include <QtCharts/QValueAxis>
#include "mybutton.h"

#ifdef __cplusplus
extern "C" {
#endif
    #include "../calculation_module.h"
#ifdef __cplusplus
}
#endif

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
//    QLineSeries *seriesGraph;
//    QChart *chartGraph;
//    QValueAxis *axisX;
//    QValueAxis *axisY;
//    QChartView *chartViewGraph;

    QCheckBox *checkXVarBox;
    QCheckBox *checkXGraphBox;
    QSpinBox *xMin;
    QSpinBox *xMax;
    QSpinBox *yMin;
    QSpinBox *yMax;

    QLabel *x_min_label;
    QLabel *x_max_label;
    QLabel *y_min_label;
    QLabel *y_max_label;
    QLabel *m_label;

    QLineEdit *m_display_up;
    QLineEdit *m_display_up_save;
    QLineEdit *m_display_down;
    QLineEdit *m_x_var;

    QGridLayout *calcLayout;
    QGridLayout *graphLayout;

    QRadioButton *annutet;
    QRadioButton *difer;

    QSpinBox *amountCredit;
    QSpinBox *loanTerm;
    QSpinBox *annualInterest;

    char answer;

    void typeResult(double resultCalc);
    void graphEdition(char *output);
    void dotClick(QLineEdit *line, bool *isDouble, QString digit);
    void unarClick(QLineEdit *line, bool *isDouble);
    void annutetFunction();
    void diferFunction();
private slots:
    void onNumClicked(QString digit);
    void onOperClicked(QString digit);
    void onAcClicked();
    void onCClicked();
    void onFuncClicked(QString digit);
    void onDotClicked(QString digit);
    void onBrClClicked();
    void onUnarClicked();
    void onBrOpClicked();
    void onEqClicked();
    void onSqrtClicked();
    void onXClicked();
    void onXVarClicked(int state);
    void onXGraphClicked(int state);
    void onCreditClicked();
};

#endif // CALCULATION_H
