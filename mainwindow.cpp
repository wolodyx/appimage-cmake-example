#include "mainwindow.h"

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "model.h"


MainWindow::MainWindow(QWidget* parent)
  : QWidget(parent)
{
  this->setWindowTitle(tr("Мое приложение"));
  QPixmap image(tr(":/resources/aroundcpp.png"));
  auto label = new QLabel();
  label->setPixmap(image);

  m_button = new QPushButton(tr("Click me, please!"), parent);

  auto ly = new QBoxLayout(QBoxLayout::TopToBottom, parent);
  ly->addWidget(label);
  ly->addWidget(m_button);
  this->setLayout(ly);

  connect(m_button, SIGNAL(clicked(bool)), this, SLOT(buttonClicked(bool)));
}


void MainWindow::buttonClicked(bool checked)
{
  auto str = greeting();
  m_button->setText(QString::fromStdString(str));
}
