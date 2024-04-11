#ifndef appimage_app_mainwindow_h
#define appimage_app_mainwindow_h

#include <QWidget>

class QPushButton;


class MainWindow : public QWidget
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);

private slots:
  void buttonClicked(bool);

private:
  QPushButton* m_button;
};

#endif // !appimage_app_mainwindow_h

