#include "mybutton.h"

MyButton::MyButton(QString text, QWidget *parent):
    QToolButton(parent){
    setText(text);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

QSize MyButton::sizeHint() const {
    QSize size = QToolButton::sizeHint();
    size.rheight() += 30;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
