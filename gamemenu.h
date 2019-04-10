#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <qmainwindow.h>
#include "gamemenuitems.h"

namespace Ui {
class GameMenu;
}

class GameMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameMenu(QWidget *parent = nullptr);
    ~GameMenu();

signals:
    void menu_option_selected(GameMenuItems option);

private slots:
    void on_buttonGame_clicked();

    void on_buttonSettings_clicked();

private:
    Ui::GameMenu *ui;
};

#endif // GAMEMENU_H
