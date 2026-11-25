#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QStringList>
#include <vector>

#include "Operation.h"

using namespace::std;

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
    vector<Operation*> operations;

    double storedNum = 0;
    bool operationClicked = 0;

    Operation *currentOperation = nullptr;
    Operation* findOperation(QString symbol);
    QString formatNumber(double number);

private slots:
    void onDigitClicked();
    void onOperationClicked();
    void onCommaClicked();
};

#endif


