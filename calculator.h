#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QStringList>

#include "Operation.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    QLineEdit *line;

    double storedNum = 0;
    bool operationClicked = 0;
    Operation *currentOperation = nullptr;
    Operation* createOperation(QString operation);
    QString formatNumber(double number);

private slots:
    void onDigitClicked();
    void onOperationClicked();
    void onCommaClicked();
};

#endif


