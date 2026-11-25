#include "Calculator.h"
#include "Operation.h"


Calculator::Calculator(QWidget *parent): QMainWindow(parent)
{
    this->resize(400, 600);
    this->setWindowTitle("Calculator");

    QWidget *centralWidget = new QWidget(this);
    QGridLayout *grid = new QGridLayout(centralWidget);

    line = new QLineEdit("0", centralWidget);
    line->setMinimumSize(400, 50);
    line->setReadOnly(1);
    grid->addWidget(line, 0, 0, 1, 3);

    operations.push_back(new Equal());
    operations.push_back(new Addition());
    operations.push_back(new Substraction());
    operations.push_back(new Multiplication);
    operations.push_back(new Division);
    operations.push_back(new Factorial);


    // Кнопки 0-9
    for (int num = 9; num >= 0; num--){
        int row = (9 - num) / 3 + 1;
        int col = (num + 2) % 3;

        QPushButton *button = new QPushButton(QString::number(num), centralWidget);
        button->setMinimumSize(100, 100);

        if (num != 0){
            grid->addWidget(button, row, col);
        }
        else{
            grid->addWidget(button, 4, 0, 1, 2);
        }

        connect(button, &QPushButton::clicked, this, &Calculator::onDigitClicked);
    }

    // Кнопка ","
    QPushButton *commaButton = new QPushButton(",", centralWidget);
    commaButton->setMinimumSize(100, 100);
    grid->addWidget(commaButton, 4, 2, 1, 1);
    connect(commaButton, &QPushButton::clicked, this, &Calculator::onCommaClicked);

    int row = 0;
    for (Operation* operation : operations){
        QPushButton *button = new QPushButton(operation->getSymbol(), centralWidget);
        button->setMinimumSize(100, 100);
        grid->addWidget(button, row++, 4);

        connect(button, &QPushButton::clicked, this, &Calculator::onOperationClicked);
    }

    setCentralWidget(centralWidget);
}


void Calculator::onDigitClicked(){
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (button){
        QString digit = button->text();

        if (line->text() != "0" && !operationClicked)
        {
            line->setText(line->text() + digit);
        }
        else{
            line->setText(digit);
            operationClicked = 0;
        }
    }
}

void Calculator::onOperationClicked(){
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (button){
        double currentNum = line->text().toDouble();
        QString symbol = button->text();

        if (currentOperation != nullptr){
            storedNum = currentOperation->exec(storedNum, currentNum);
        }

        else{
            storedNum = currentNum;
        }

        currentOperation = findOperation(symbol);

        if (symbol == "!" || symbol == "="){
            if (currentOperation != nullptr){
                storedNum = currentOperation->exec(storedNum, 0);
            }

            currentOperation = nullptr;
            line->setText(formatNumber(storedNum));
        }
        line->setText(formatNumber(storedNum));
        operationClicked = 1;
    }
}


Operation* Calculator::findOperation(QString Symbol)
{
    for (Operation* operation : operations){
        if (operation->getSymbol() == Symbol){
            return operation;
        }
    }

    return nullptr;
}



void Calculator::onCommaClicked(){
    if (!line->text().contains(".")){
        line->setText(line->text() + ".");
    }
}

QString Calculator::formatNumber(double number)
{
    QString result = QString::number(number, 'f', 8);

    while (result.contains('.') && result.endsWith('0'))
        result.chop(1);

    if (result.endsWith('.'))
        result.chop(1);
    return result;
}



Calculator::~Calculator()
{
    for (Operation* operation : operations){
        delete operation;
    }
}
